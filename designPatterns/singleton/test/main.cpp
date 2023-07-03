#include "../singleton.hpp"
#include <gtest/gtest.h>

TEST(RecordFinderTests, SingletonTotalPopulationTest)
{
    SingletonRecordFinder rf;
    std::vector<std::string> names{"Seoul", "Mexico City"};
    int tp = rf.total_population(names);
    EXPECT_EQ(17500000 + 17400000, tp);
}

TEST(RecordFinderTests, DependantMockTotalPopulationTest)
{
    MockDatabase db{};
    ConfigurableRecordFinder rf{db};
    EXPECT_EQ(4, rf.total_population(std::vector<std::string>{"alpha", "gamma"}));
}

TEST(RecordFinderTests, DependantRealTotalPopulationTest)
{
    ConfigurableRecordFinder rf{SingletonDatabase::get()};
    std::vector<std::string> names{"Seoul", "Mexico City"};
    EXPECT_EQ(17500000 + 17400000, rf.total_population(names));
}

int dsfmain(int ac, char* av[])
{
    testing::InitGoogleTest(&ac, av);
    return RUN_ALL_TESTS();
}