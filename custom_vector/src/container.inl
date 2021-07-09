#include "container.hpp"
#include <utility>

namespace container {

template <class T>
inline Vector<T>::Vector()
    : m_size(0)
    , m_capacity(0)
    , m_data(nullptr)
{
}

template <class T>
inline Vector<T>::Vector(std::initializer_list<T> il)
    : m_size(il.size())
    , m_capacity(il.size())
    , m_data(new T[m_size])
{
    Iterator it = begin();
    for(const T& item : il)
    {
        *it++ = item;
    }
}

template <class T>
inline Vector<T>::Vector(int size)
    : m_size(size)
    , m_capacity(size)
    , m_data(new T[size])
{
    for(int index; index < size; ++index)
    {
        m_data[index] = T();
    }
}
template <class T>
inline Vector<T>::Vector(const Vector& vec)
    : m_size(vec.m_size)
    , m_capacity(vec.m_capacity)
    , m_data(new T[m_size])
{
    std::copy(vec.begin(), vec.end(), begin());
}

template <class T>
inline Vector<T>::Vector(Vector&& vec) noexcept
    : m_size(std::move(vec.m_size))
    , m_capacity(std::move(vec.m_capacity))
    , m_data(new T[m_size])
{
    m_data = std::exchange(vec.m_data, nullptr);
    vec.m_size = 0;
    vec.m_capacity = 0;
}

template <class T>
inline Vector<T>& Vector<T>::operator=(const Vector<T>& vec)
{
    if(&vec == this)
    {
        return *this;
    }

    // current vector have enough space, no need for a new allocation
    if(m_capacity >= vec.m_size)
    {
        std::copy(vec.begin(), vec.end(), begin());
        m_size = vec.m_size;
        return *this;
    }

    delete[] m_data;
    //reallocation is needed
    m_data = new T[vec.m_size];

    std::copy(vec.begin(), vec.end(), begin());

    m_size = vec.m_size;
    m_capacity = vec.m_size;

    return *this;
}

template <class T>
inline Vector<T>& Vector<T>::operator=(Vector<T>&& vec) noexcept
{
    // no need...
    if(&vec == this)
    {
        return *this;
    }
    // 1. clean all visible resources
    delete[] m_data;

    //2. transfer the content
    m_size = std::move(vec.m_size);
    m_capacity = std::move(vec.m_capacity);
    m_data = std::exchange(vec.m_data, nullptr);

    //3. leave vector in valid but undefine state
    vec.m_size = 0;
    vec.m_capacity = 0;
}

template <class T>
inline Vector<T>::~Vector() noexcept
{
    delete[] m_data;
}

template <class T>
inline T& Vector<T>::at(int index)
{
    if(index < 0 || index >= m_size)
    {
        throw std::out_of_range("out of range");
    }
    return m_data[index];
}

template <class T>
inline const T& Vector<T>::at(int index) const
{
    if(index < 0 || index >= m_size)
    {
        throw std::out_of_range("out of range");
    }
    return m_data[index];
}

// Access elements, no bounds checking
template <class T>
inline T& Vector<T>::operator[](int i)
{
    return m_data[i];
}

template <class T>
inline const T& Vector<T>::operator[](int i) const
{
    return m_data[i];
}

template <class T>
inline T& Vector<T>::front()
{
    return m_data[0];
}

template <class T>
inline const T& Vector<T>::front() const
{
    return m_data[0];
}

template <class T>
inline T& Vector<T>::back()
{

    return m_data[m_size - 1];
}

template <class T>
inline const T& Vector<T>::back() const
{
    return m_data[m_size - 1];
}

template <class T>
inline T* Vector<T>::data()
{
    return m_data;
}

template <class T>
inline const T* Vector<T>::data() const
{
    return m_data;
}

template <class T>
inline bool Vector<T>::empty() const
{
    return m_size <= 0;
}

template <class T>
inline size_t Vector<T>::size() const
{
    return m_size;
}

template <class T>
inline size_t Vector<T>::capacity() const
{
    return m_capacity;
}

template <class T>
inline void Vector<T>::push_back(const T& item)
{
    if(m_capacity == 0)
    {
        reserve(8);
    }
    else if(m_size == m_capacity)
    {
        reserve(m_capacity * 2);
    }

    m_data[m_size] = item;

    ++m_size;
}

template <class T>
inline void Vector<T>::push_back(T&& item)
{
    if(m_capacity == 0)
    {
        reserve(8);
    }
    else if(m_size == m_capacity)
    {
        reserve(m_capacity * 2);
    }

    m_data[m_size] = std::move(item);

    ++m_size;
}

template <class T>
inline void Vector<T>::reserve(int newSpace)
{
    if(newSpace <= m_capacity)
    {
        return;
    }

    T* p = new T[newSpace];

    for(int i = 0; i < m_size; ++i)
        p[i] = std::move_if_noexcept(m_data[i]);

    delete[] m_data;

    m_data = p;

    m_capacity = newSpace;
}

} // namespace container