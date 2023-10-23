#ifndef MYSMARTPOINTER_H
#define MYSMARTPOINTER_H
#include <iostream>

namespace CreateSmartPointer {

// SIMPLE SMARTPOINTER CLASS.
template <typename T>
class MySmartPointer
{
public:
    MySmartPointer<T>()       { m_ptr = nullptr; }              // must have default contructor
    MySmartPointer<T>(T* ptr) : m_ptr(ptr)    {}                // parametric constructor

    MySmartPointer<T>(MySmartPointer&& ref)                     // must have move contructor
    {
        m_ptr = ref.m_ptr;      // move ptr
        ref.m_ptr = nullptr;    // kill old ptr
    }

    MySmartPointer& operator=(MySmartPointer&& ref)          // must overload operator= to move ptr
    {
        m_ptr = ref.m_ptr;      // move ptr
        ref.m_ptr = nullptr;    // kill old ptr
    }

    // Must kill copy constructor and operator= to copy ptr
    MySmartPointer(const MySmartPointer& ref)             = delete;
    MySmartPointer& operator=(const MySmartPointer& ref)  = delete;

    // Must overload operator-> and operator* to call class methods
    T* operator->() { return m_ptr; }

    ~MySmartPointer<T>() { delete m_ptr; }                     // must have destructor

private:
    T* m_ptr;
};

class TestClass
{
public:
    TestClass(std::string name, int id) : m_name(name), m_id(id){ std::cout << "Test Class Constructor" << std::endl;}
    ~TestClass()    { std::cout << "Test Class Destructor" << std::endl;}
    void doStuff()  { std::cout << "Test Class Name : " << m_name << " and Id : " << m_id << " - do Stuff" << std::endl;}
private:
    std::string m_name;
    int m_id;
};

void runMySmartPointer()
{
    std::cout << "\n ----- Cretate Object 01 " << std::endl;
    MySmartPointer<TestClass> testObject01 (new TestClass("testObj", 01));
    testObject01->doStuff();

    std::cout << "\n ----- Test move constructor to Object 02 " << std::endl;
    MySmartPointer<TestClass> &testObject02 (testObject01);
    testObject02->doStuff();

    std::cout << "\n ----- Test overload operator= with Object 03 " << std::endl;
    MySmartPointer<TestClass> &testObject03 = testObject02;
    testObject03->doStuff();
}
}

#endif // MYSMARTPOINTER_H
