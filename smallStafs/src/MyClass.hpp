
#ifndef PROJECT_MY_CLASS_HPP
#define PROJECT_MY_CLASS_HPP

#include <iostream>
#include <memory>

namespace project {

class MyClass : public std::enable_shared_from_this<MyClass>
{
// prevent to create class with public constructor
private:
    struct CtorGuard
    {
        explicit CtorGuard() = default;
    };  
public:
    static std::shared_ptr<MyClass> makeShared()
    {
        return std::make_shared<MyClass>(CtorGuard{});
    }
    ///
    /// \brief Construct a new MyClass object
    /// Function should not be used. Instead use makeShared()
    ///
    /// \param cTorGuard cTorGuard to prevent creation except with makeShared()
    ///
    
    explicit MyClass(const CtorGuard& guard)
    {
        
    }

    MyClass(MyClass &&) = delete;
    MyClass(const MyClass &) = delete;
    MyClass &operator=(MyClass &&) = delete;
    MyClass &operator=(const MyClass &) = delete;
    ~MyClass() = default;

private:
    
};

}



#endif //PROJECT_MY_CLASS_HPP