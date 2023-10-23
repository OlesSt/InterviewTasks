#ifndef MYSHAREDPOINTER_H
#define MYSHAREDPOINTER_H
#include <iostream>

namespace CreaateSharedPointer
{

template <typename T>
class MySharedPointer
{
public:
    MySharedPointer<T>()
    {
        m_ptr   = nullptr;                                          // by default ptr and counter points to nothing
        m_count = nullptr;
    }

    MySharedPointer(T* ptr)
        : m_ptr(ptr) {m_count = new size_t {1};}                    // when create object increment counter

    MySharedPointer(const MySharedPointer<T>& copyObj)              // Copy Constructor : copy object data and update counter
        : m_ptr(copyObj.m_prt), m_count(copyObj.m_count)
    {
        if (m_count) {*(m_count)++;}
    }

    MySharedPointer(MySharedPointer<T>&& moveObj)                   // Move Constructor : move object data and kill it
        : m_ptr(moveObj.m_ptr), m_count(moveObj.m_count)
    {
        moveObj.m_ptr   = nullptr;
        moveObj.m_count = nullptr;
    }

    MySharedPointer& operator=(const MySharedPointer<T>& copyObj)   // Overload operaotor= as copy : copy obj data and uprate counter
    {
        if (this != copyObj)                    // check obj doesn't point to itself
        {
            if (m_count && --(*m_count) == 0)   // check this is the last owner of shared data
            {
                delete m_ptr;                   // delete dynamicly allocated ptr
                delete m_count;
            }
        }


        m_ptr   = copyObj.m_ptr;
        m_count = copyObj.m_count;
        if (m_count) {*(m_count)++;}
        return *this;
    }

    MySharedPointer& operator=(const MySharedPointer<T>&& moveObj)   // Overload operaotor= as move : move obj data and kill it
    {
        if (this != moveObj)                    // check obj doesn't point to itself
        {
            if (m_count && --(*m_count) == 0)   // check this is the last owner of shared data
            {
                delete m_ptr;                   // delete dynamicly allocated ptr
                delete m_count;
            }
        }

        m_ptr   = moveObj.m_ptr;
        m_count = moveObj.m_count;

        moveObj.m_ptr   = nullptr;
        moveObj.m_count = nullptr;
        return *this;
    }

    ~MySharedPointer()
    {
        if (m_count && --(*m_count) == 0)       // when counter = 0 there is no object that use shared pointer, delete last object and counter
        {
            std::cout << "All objects deleted" << std::endl;
            delete m_ptr;
            delete m_count;
        }
    }

    // Getters
    T*     getData()  const {return m_ptr;}
    size_t getCount() const {return m_count ? *m_count : 0;}


    // Overload operator-> and operator* to use class methods
    T* operator->() {return m_ptr;}
    T& operator*()  {return *m_ptr;}

private:
    // T - object type, count - counts shared pointers objects
    T* m_ptr;
    size_t* m_count;
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



void runMySharedPointer()
{
    std::cout << "\n ----- Test Create Object 01" << std::endl;
    MySharedPointer<TestClass> obj01 (new TestClass("obj", 1));
    obj01->doStuff();

    std::cout << "\n ----- Test Move Constructor Object 02" << std::endl;
    MySharedPointer<TestClass> obj02 (std::move(obj01));
    obj02->doStuff();

    std::cout << "\n ----- Test Operator= as Copy Objectr 03" << std::endl;
    MySharedPointer<TestClass> &obj03 = obj02;
    obj03->doStuff();
}
}

#endif // MYSHAREDPOINTER_H
