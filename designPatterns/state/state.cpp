#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

// classic state design pattern
// not the best
class LightSwitch;

struct State
{
    virtual void on(LightSwitch* ls)
    {
        cout << "Light is already on\n";
    }
    virtual void off(LightSwitch* ls)
    {
        cout << "Light is already off\n";
    }
};

struct OnState : State
{
    OnState()
    {
        cout << "Light turned on\n";
    }

    void off(LightSwitch* ls) override;
};

struct OffState : State
{
    OffState()
    {
        cout << "Light turned off\n";
    }

    void on(LightSwitch* ls) override;
};

class LightSwitch
{
    State* state;

public:
    LightSwitch()
    {
        state = new OffState();
    }
    void set_state(State* state)
    {
        this->state = state;
    }
    void on()
    {
        state->on(this);
    }
    void off()
    {
        state->off(this);
    }
};

void OnState::off(LightSwitch* ls)
{
    cout << "Switching light off...\n";
    ls->set_state(new OffState());
    delete this;
}

void OffState::on(LightSwitch* ls)
{
    cout << "Switching light on...\n";
    ls->set_state(new OnState());
    delete this;
}

int mainClassicMachine()
{
    LightSwitch ls;
    ls.on();
    ls.off();
    ls.off();
}

// state machine with enums

enum class StateEnum
{
    OffHook,
    Connecting,
    Connected,
    OnHold,
    OnHook
};

inline ostream& operator<<(ostream& os, const StateEnum& s)
{
    switch(s)
    {
        case StateEnum::OffHook:
            os << "off the hook";
            break;
        case StateEnum::Connecting:
            os << "connecting";
            break;
        case StateEnum::Connected:
            os << "connected";
            break;
        case StateEnum::OnHold:
            os << "on hold";
            break;
        case StateEnum::OnHook:
            os << "on the hook";
            break;
    }
    return os;
}

enum class Trigger
{
    CallDialed,
    HungUp,
    CallConnected,
    PlacedOnHold,
    TakenOffHold,
    LeftMessage,
    StopUsingPhone
};

inline ostream& operator<<(ostream& os, const Trigger& t)
{
    switch(t)
    {
        case Trigger::CallDialed:
            os << "call dialed";
            break;
        case Trigger::HungUp:
            os << "hung up";
            break;
        case Trigger::CallConnected:
            os << "call connected";
            break;
        case Trigger::PlacedOnHold:
            os << "placed on hold";
            break;
        case Trigger::TakenOffHold:
            os << "taken off hold";
            break;
        case Trigger::LeftMessage:
            os << "left message";
            break;
        case Trigger::StopUsingPhone:
            os << "putting phone on hook";
            break;
        default:
            break;
    }
    return os;
}

int main_f()
{
    map<StateEnum, vector<pair<Trigger, StateEnum>>> rules;

    rules[StateEnum::OffHook] = {
        {Trigger::CallDialed, StateEnum::Connecting},
        {Trigger::StopUsingPhone, StateEnum::OnHook}};

    rules[StateEnum::Connecting] = {
        {Trigger::HungUp, StateEnum::OffHook},
        {Trigger::CallConnected, StateEnum::Connected}};

    rules[StateEnum::Connected] = {
        {Trigger::LeftMessage, StateEnum::OffHook},
        {Trigger::HungUp, StateEnum::OffHook},
        {Trigger::PlacedOnHold, StateEnum::OnHold}};

    rules[StateEnum::OnHold] = {
        {Trigger::TakenOffHold, StateEnum::Connected},
        {Trigger::HungUp, StateEnum::OffHook}};

    StateEnum currentState{StateEnum::OffHook},
        exitState{StateEnum::OnHook};

    while(true)
    {
        cout << "The phone is currently " << currentState << endl;
    select_trigger:
        cout << "Select a trigger:"
             << "\n";

        int i = 0;
        for(auto item : rules[currentState])
        {
            cout << i++ << ". " << item.first << "\n";
        }

        int input;
        cin >> input;
        if(input < 0 || (input + 1) > rules[currentState].size())
        {
            cout << "Incorrect option. Please try again."
                 << "\n";
            goto select_trigger;
        }

        currentState = rules[currentState][input].second;
        if(currentState == exitState)
            break;
    }

    cout << "We are done using the phone"
         << "\n";
}

int main()
{
    mainClassicMachine();
    main_f();
    getchar();
    return 0;
}
