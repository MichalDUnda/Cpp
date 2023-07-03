#include <iostream>
#include <string>
#include <unordered_map>
#include <functional>
#include <vector>
using namespace std;

using action = std::function<void()>;
struct HandlerIntf
{
    virtual void processEvents(std::unordered_map<std::string, action>& actions) = 0;
};

struct ObsInterface
{
protected:
    std::vector<HandlerIntf*> m_handlers;

public:
    void registerHandler(HandlerIntf* handler)
    {
        m_handlers.push_back(handler);
    }
};

class HandlerForAlarmRemoving : public HandlerIntf
{
public:
    void processEvents(std::unordered_map<std::string, action>& actions) override
    {
        std::cout << "pRemoving alarm if it is present " << std::endl;
        actions.erase("Alarm");
    }
    void applyHandlerOn(ObsInterface& observerIntf)
    {
        observerIntf.registerHandler(this);
    }
};

class Observer : public ObsInterface
{
public:
    Observer()
    {
    }
    ~Observer() = default;
    void processEvent()
    {
        auto actions = possible_actions;
        if(possible_actions.empty())
        {
            return;
        }
        for(const auto& handler : m_handlers)
        {
            handler->processEvents(actions);
        }
        for(const auto& actionToPerform : actions)
        {
            actionToPerform.second();
        }
    }

    void addAction(const std::string& name, action action)
    {
        possible_actions.insert_or_assign(name, action);
    }

    std::unordered_map<std::string, action> possible_actions;
};

int main()
{

    Observer obs;
    auto alarmAction = [] { std::cout << "Perform action under name ALARM" << std::endl; };
    auto eventAction = [] { std::cout << "Perform action under name EVENT" << std::endl; };

    obs.addAction("Alarm", alarmAction);
    obs.addAction("Event", eventAction);

    obs.processEvent();

    HandlerForAlarmRemoving handler;
    handler.applyHandlerOn(obs);

    obs.processEvent();

    return 0;
}
