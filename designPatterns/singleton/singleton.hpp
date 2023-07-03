
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

// need to have a interface to have a possibility to mock singleton
class Database
{
public:
    virtual int get_population(const std::string& name) = 0;
};

// singleton pattern
// private constructor
// static metnod to get a reference
// deleted copy, move constructors
class SingletonDatabase : public Database
{
    SingletonDatabase()
    {
        std::cout << "Initializing database" << std::endl;

        capitals.insert({"Mexico City", 17500000});
        capitals.insert({"Seoul", 17400000});
    }

    std::map<std::string, int> capitals;

public:
    SingletonDatabase(SingletonDatabase const&) = delete;
    void operator=(SingletonDatabase const&) = delete;

    static SingletonDatabase& get()
    {
        static SingletonDatabase db;
        return db;
    }

    int get_population(const std::string& name) override
    {
        return capitals[name];
    }
};

// mock tadabase for testing
class MockDatabase : public Database
{
    std::map<std::string, int> capitals;

public:
    MockDatabase()
    {
        capitals["alpha"] = 1;
        capitals["beta"] = 2;
        capitals["gamma"] = 3;
    }

    int get_population(const std::string& name) override
    {
        return capitals[name];
    }
};

// class which internally use the singleton
// !!!! without dependency injection !!!!!
// not possible to test class
struct SingletonRecordFinder
{
    int total_population(std::vector<std::string> names)
    {
        int result = 0;
        for(auto& name : names)
            result += SingletonDatabase::get().get_population(name);
        return result;
    }
};

// dependency injection into constructor
// possible to inject real or mock singleton class
struct ConfigurableRecordFinder
{
    explicit ConfigurableRecordFinder(Database& db)
        : db{db}
    {
    }

    int total_population(std::vector<std::string> names) const
    {
        int result = 0;
        for(auto& name : names)
            result += db.get_population(name);
        return result;
    }

    Database& db;
};
