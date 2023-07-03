#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

//command design pattern
// take reference to obj and call on it some particular action
// also take function parameters.

struct BankAccount
{
    int balance{0};
    int overdraft_limit{-500};

    void deposit(int amount)
    {
        balance += amount;
        cout << "deposited " << amount << " and the balance is now " << balance << endl;
    }

    void withdraw(int amount)
    {
        if((balance - amount) >= overdraft_limit)
        {
            balance -= amount;
            cout << "withdraw " << amount << " and the balance is now " << balance << endl;
        }
    }

    friend ostream& operator<<(ostream& os, const BankAccount& account)
    {
        os << "balance " << account.balance;
        return os;
    }
};

// command intf.
struct command
{
    virtual void call() const = 0;
    virtual void undo() const = 0;
};

// command
// take a reference to account, operation type (od could be func pointer) and parameters of the function
struct BankAccountCommand : public command
{
    BankAccount& account;
    enum Action
    {
        deposit,
        withdraw
    } action;
    int amount;

    BankAccountCommand(BankAccount& account,
        const Action action,
        const int amount)
        : account(account)
        , action(action)
        , amount(amount)
    {
    }

    void call() const override
    {
        switch(action)
        {
            case deposit:
                account.deposit(amount);
                break;
            case withdraw:
                account.withdraw(amount);
                break;
            default:
                break;
        }
    }

    void undo() const override
    {
        switch(action)
        {
            case withdraw:
                account.deposit(amount);
                break;
            case deposit:
                account.withdraw(amount);
                break;
            default:
                break;
        }
    }
};

// composit command pattern
struct CompositeBankAccountCommand
    : public vector<BankAccountCommand>,
      public command
{
    CompositeBankAccountCommand(const initializer_list<value_type>& items)
        : vector<BankAccountCommand>(items)
    {
    }

    void call() const override
    {
        for(auto& cmd : *this)
            cmd.call();
    }

    void undo() const override
    {
        for(auto& cmd : *this)
            cmd.undo();
    }
};

int main()
{
    BankAccount account;
    vector<BankAccountCommand> commands{
        BankAccountCommand{account, BankAccountCommand::deposit, 100},
        BankAccountCommand{account, BankAccountCommand::withdraw, 200}};

    cout << account << endl;
    for(auto cmd : commands)
    {
        cmd.call();
    }
    cout << account << endl;

    for_each(commands.rbegin(), commands.rend(), [](const BankAccountCommand& cmd) { cmd.undo(); });

    cout << account << endl;

    return 0;
}
