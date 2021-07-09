
#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include <iostream>
#include <iterator>
#include <cstddef>

namespace container {
template <class T>
class Vector
{
public:
    // constructors
    Vector();

    Vector(std::initializer_list<T> il);

    explicit Vector(int size);

    //copy constructor
    Vector(const Vector& vec);

    // move constructor
    Vector(Vector&& vec) noexcept;

    // Copy Assignment
    Vector<T>& operator=(const Vector<T>& vec);

    // Copy move
    Vector<T>& operator=(Vector<T>&& vec) noexcept;

    ~Vector() noexcept;

    //Iterator
    struct Iterator
    {
        using iterator_category = std::forward_iterator_tag;
        // a signed integer type that can be used to identify distance between iterator steps.
        // Our iterator is basically a wrapper around a pointer and leverages pointer arithmetic,
        // so the default std::ptrdiff_t is a good choice;
        using difference_type = std::ptrdiff_t;
        // the type the iterator iterates over. int in our case;
        using value_type = T;
        // defines a pointer to the type iterated over. int* in our case
        using pointer = T*; // or also value_type*
        // defines a reference to the type iterated over. int& in our case;
        using reference = T&; // or also value_type&

        //constructor
        Iterator(pointer ptr)
            : m_ptr(ptr)
        {
        }

        pointer operator->()
        {
            return m_ptr;
        }

        reference operator*()
        {
            return *m_ptr;
        }

        Iterator& operator++()
        {
            m_ptr++;
            return *this;
        }

        Iterator operator++(int)
        {
            Iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        friend bool operator==(const Iterator& a, const Iterator& b)
        {
            return a.m_ptr == b.m_ptr;
        }

        friend bool operator!=(const Iterator& a, const Iterator& b)
        {
            return !(a == b);
        }

    private:
        pointer m_ptr;
    };

    struct ConstIterator
    {
        using iterator_category = std::forward_iterator_tag;
        // a signed integer type that can be used to identify distance between iterator steps.
        // Our iterator is basically a wrapper around a pointer and leverages pointer arithmetic,
        // so the default std::ptrdiff_t is a good choice;
        using difference_type = std::ptrdiff_t;
        // the type the iterator iterates over. int in our case;
        using value_type = T;
        // defines a pointer to the type iterated over. int* in our case
        using pointer = T*; // or also value_type*
        // defines a reference to the type iterated over. int& in our case;
        using reference = T&; // or also value_type&

        //constructor
        ConstIterator(pointer ptr)
            : m_ptr(ptr)
        {
        }

        const pointer operator->() const
        {
            return m_ptr;
        }

        const reference operator*() const
        {
            return *m_ptr;
        }

        ConstIterator& operator++()
        {
            m_ptr++;
            return *this;
        }

        ConstIterator operator++(int)
        {
            ConstIterator tmp = *this;
            ++(*this);
            return tmp;
        }

        friend bool operator==(const ConstIterator& a, const ConstIterator& b)
        {
            return a.m_ptr == b.m_ptr;
        }

        friend bool operator!=(const ConstIterator& a, const ConstIterator& b)
        {
            return !(a == b);
        }

    private:
        pointer m_ptr;
    };

public:
    Iterator begin()
    {
        return Iterator(&m_data[0]);
    }

    Iterator printAddressOfFirstElement() const
    {
        std::cout << "Address of first elements is " << &m_data[0] << "/n";
    }
    Iterator end()
    {
        return Iterator(&m_data[m_size]);
    } // 200 is out of bounds

    ConstIterator begin() const
    {
        return ConstIterator(&m_data[0]);
    }
    ConstIterator end() const
    {
        return ConstIterator(&m_data[m_size]);
    }

    ConstIterator cbegin() const
    {
        return ConstIterator(&m_data[0]);
    }
    ConstIterator cend() const
    {
        return ConstIterator(&m_data[m_size]);
    }

private:
    size_t m_size;
    size_t m_capacity;
    T* m_data;

public:
    /* --- Element access --- */
    T& at(int);

    const T& at(int) const;
    // Access elements, no bounds checking
    T& operator[](int i);

    // Access elements, no bounds checking
    const T& operator[](int i) const;

    // Returns a reference to the first element
    T& front();

    // Returns a reference to the first element
    const T& front() const;

    // Returns a reference to the last element
    T& back();

    // Returns a reference to the last element
    const T& back() const;

    // Returns a pointer to the array used by Vector
    T* data();

    // Returns a pointer to the array used by Vector
    const T* data() const;

    bool empty() const;

    size_t size() const;

    size_t capacity() const;

    void push_back(const T& item);
    void push_back(T&& item);

    template <class... Args>
    void emplace_back(Args&&... args)
    {
        push_back(T(std::forward<Args>(args)...));
    }

    void reserve(int newSpace);
};

} // namespace container

#include "container.inl"

#endif