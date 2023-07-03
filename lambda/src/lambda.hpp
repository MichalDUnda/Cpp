#include <iostream>
#include <string>
#include <vector>
#include <type_traits>
struct Type
{
    virtual void type() const = 0;
};
struct IntType : public Type
{
    int value;
    void type() const override
    {
        std::cout << "my type is Int" << std::endl;
    }
};

struct FloatType : public Type
{
    void type() const override
    {
        std::cout << "my type is Float" << std::endl;
    }
    float value;
};

struct StringType : public Type
{
    void type() const override
    {
        std::cout << "my type is String" << std::endl;
    }
    std::string value;
};

//type trait for itemType
template <typename T>
struct ItemType;

/// \brief Type trait specialization for IntType type
template <>
struct ItemType<IntType>
{
    using type = int;
};
/// \brief Type trait specialization for FloatType type
template <>
struct ItemType<FloatType>
{
    using type = float;
};
/// \brief Syntax sugar for  type trait
template <typename T>
using ItemType_t = typename ItemType<T>::type;

/// \brief Type trait indication if the type @c T is supported type
template <typename T>
struct isSupportedType : std::false_type
{
};

/// \brief Type trait indication if the type @c T is supported alarm limit type
template <>
struct isSupportedType<IntType> : std::true_type
{
};

/// \brief Type trait indication if the type @c T is supported alarm limit type
template <>
struct isSupportedType<FloatType> : std::true_type
{
};

// example of function which use isSupported type trait
template <typename T, std::enable_if_t<isSupportedType<T>::value, bool> = 0>
void exampleFuncForIsSupported(const T& val)
{
    std::cout << "type is supported" << std::endl;
    val.type();
}

template <typename T>
static inline constexpr std::enable_if_t<isSupportedType<T>::value, bool>
exampleFuncForIsSupportedWithReturnType(const T& val)
{
    std::cout << "type is supproted" << std::endl;
    val.type();
    return true;
}

// type trait if class has a type() function
template <typename T, typename = void>
struct hasTypeFunction : std::false_type
{
};

// true type only if type has a type function
template <typename T>
struct hasTypeFunction<T, std::void_t<decltype(std::declval<T>().type())>> : std::true_type
{
};

//void_t explanation -> any valid type convert to void !!!!!
// usage hasMemberVariable<T>::value -> in code hasMemberVariable<A>::value
// 1. primary template found
//      1.1 provide 1 param but 2 needed
//      1.2 substitution -> hasMemberVariable<A, void>::value -> false type
// 2. find the specialization
//      2.1 if no param list matches the primary template is used as fallback
//      2.2 try one with void_t
//      2.3 first param deduction performed
//      2.4 second param
//      2.5 it is well formet because A has member "variable"
//      2.6 hasMemberVariable<A, void>::value -> true type but better match

// type trait if class has a type() function
template <typename T, typename = void>
struct hasMemberVariable : std::false_type
{
};

// true type only if type has a type function
template <typename T>
struct hasMemberVariable<T, std::void_t<decltype(T::variable)>> : std::true_type
{
};

struct HasTypeFunc
{
    void type() const
    {
        std::cout << "type call" << std::endl;
    }
    int variable;
};

struct HasStringVariable
{
    std::string variable;
};

struct HasNotTypeFunc
{
    void NotType() const
    {
        std::cout << "not Type call" << std::endl;
    }
};

// example of function which use isSupported type trait
template <typename T, std::enable_if_t<hasTypeFunction<T>::value, bool> = 0>
void exampleFunctionWitchHasType(const T& val)
{
    std::cout << "has type function" << std::endl;
    val.type();
}

// example of function which use hasMemberVariable type trait
template <typename T, std::enable_if_t<hasMemberVariable<T>::value, bool> = 0>
void exampleFunctionWitchHasMemberVariable(T& val)
{
    std::cout << "type has member variable" << std::endl;
    /*
    if constexpr(std::is_integral<T>)
    {
        val.variable = 5;
    }
    if constexpr(std::is_same<T, std::string>)
    {
        val.variable = "five";
    }*/
}
