#include <gtest/gtest.h>
#include <container.hpp>

// Demonstrate some basic assertions.
TEST(VectorTest, Constractors)
{
    container::Vector<int> vec(3);
    std::fill(vec.begin(), vec.end(), 3);

    for(const auto& item : vec)
    {
        EXPECT_EQ(item, 3);
    }
}

TEST(VectorTest, InitializeList)
{
    container::Vector<int> vec{1, 2, 3};

    int i{0};
    for(const auto& item : vec)
    {
        EXPECT_EQ(item, ++i);
    }

    container::Vector<std::string> strVec{"hello", "hi", "hallo"};

    auto it = strVec.begin();

    EXPECT_EQ(*it++, "hello");
    EXPECT_EQ(*it++, "hi");
    EXPECT_EQ(*it, "hallo");
}

TEST(VectorTest, getElements)
{
    container::Vector<int> vec{1, 2, 3};

    EXPECT_EQ(vec.at(0), 1);
    EXPECT_EQ(vec.at(1), 2);
    EXPECT_EQ(vec.at(2), 3);

    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[1], 2);
    EXPECT_EQ(vec[2], 3);

    EXPECT_EQ(vec.front(), 1);
    EXPECT_EQ(vec.back(), 3);

    EXPECT_EQ(vec.size(), 3);
    EXPECT_EQ(vec.empty(), false);

    EXPECT_THROW(vec.at(-1), std::out_of_range);
    EXPECT_THROW(vec.at(3), std::out_of_range);
}

TEST(VectorTest, capacity)
{
    container::Vector<int> vec;

    EXPECT_EQ(vec.capacity(), 0);

    container::Vector<int> secondVec(5);

    EXPECT_EQ(secondVec.capacity(), 5);
}

TEST(VectorTest, addItem)
{
    container::Vector<int> vec;
    EXPECT_EQ(vec.capacity(), 0);
    EXPECT_EQ(vec.size(), 0);
    vec.reserve(1);

    EXPECT_EQ(vec.capacity(), 1);
    EXPECT_EQ(vec.size(), 0);

    vec.push_back(5);

    EXPECT_EQ(vec.capacity(), 1);
    EXPECT_EQ(vec.at(0), 5);
    EXPECT_EQ(vec.size(), 1);

    vec.push_back(10);

    EXPECT_EQ(vec.capacity(), 2);
    EXPECT_EQ(vec.at(0), 5);
    EXPECT_EQ(vec.at(1), 10);
    EXPECT_EQ(vec.size(), 2);
}

TEST(VectorTest, addItemEmplaceBack)
{
    container::Vector<std::string> vec;
    EXPECT_EQ(vec.capacity(), 0);
    EXPECT_EQ(vec.size(), 0);
    vec.reserve(1);

    EXPECT_EQ(vec.capacity(), 1);
    EXPECT_EQ(vec.size(), 0);

    vec.push_back(std::string("first"));

    EXPECT_EQ(vec.capacity(), 1);
    EXPECT_EQ(vec.at(0), "first");
    EXPECT_EQ(vec.size(), 1);

    vec.push_back("second");

    EXPECT_EQ(vec.capacity(), 2);
    EXPECT_EQ(vec.at(0), "first");
    EXPECT_EQ(vec.at(1), "second");
    EXPECT_EQ(vec.size(), 2);
}
