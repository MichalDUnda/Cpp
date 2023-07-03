#include <iostream>
#include <string>
#include <vector>

#include "MyClass.hpp"

#include <algorithm>
#include <assert.h>


struct A 
{
    A(int a)
    :a(a)
    {}
    int getA()
    {
        return a;
    }
    int a;
};

int main(int argc, char* argv[])

{
    using namespace project;

    // only possibility how to create onj of MyClass is to use of Static method
    // that means only shared ptr could exist, User is force to use this exact method
    auto obj = MyClass::makeShared();

   std::vector<std::shared_ptr<A>>  a{};
 //  a.push_back(std::make_shared<A>(1));
 //  a.push_back(std::make_shared<A>(1));
 //  a.push_back(std::make_shared<A>(1));

    std::cout << "is Empty " <<std::endl;
   auto res = std::find_if(a.begin(), a.end(), [](const auto& val) -> bool {
       assert(val);
       return (val->a == 5);
   });
   if(res == a.end())
   {
       std::cout << "end item " << std::endl;
   }
   std::cout << "try dereference " << std::endl;
   auto resPtr = *res;
   
   std::cout << "BEFORE ASSERT " << std::endl;
   assert(resPtr);

   std::cout << "AFTER ASSERT " << std::endl;

   std::cout << "is Empty " << a.empty() <<  resPtr->a << std::endl;

   return 0;
}