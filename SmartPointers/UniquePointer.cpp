#include <iostream>

template <typename T>
class UniquePointer
{
    private:
    T* ptr;
    
    public:
    UniquePointer(T* p=nullptr)
    {
        ptr = p;
    }
    
    ~UniquePointer()
    {
        delete ptr;
    }
    
    //delete copy constructors
    UniquePointer(UniquePointer& other)= delete;
    UniquePointer& operator=(UniquePointer& other) = delete;
    
    //Move constructor
    UniquePointer(UniquePointer&& other) noexcept
    {
        ptr =nullptr;
        ptr=other.ptr;
        other.ptr=nullptr;
    }
    
    //Move assignment
    UniquePointer& operator=(UniquePointer&& other)
    {
        if (this != &other)
        {
            ptr = nullptr;
            ptr =other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }
    
    T* operator->() const
    {
        return ptr;
    }
    
    T& operator*() const
    {
        return *ptr;
    }
    
    //get raw pointer
    T* get() const
    {
        return ptr;
    }
};

class Test
{
    public:
    void demo()
    {
        std::cout<<"In demo"<<std::endl;
    }
};


int main()
{
    std::cout<<"Hello World\n";
    UniquePointer<Test> up1 = new Test();
    
    up1->demo();
    
    UniquePointer<Test> up2;
    
    up2 = std::move(up1);
    
    up2->demo();

    return 0;
}