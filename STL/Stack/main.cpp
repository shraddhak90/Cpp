#include <iostream>
#include "StackClass.h"

int main()
{
    StackClass s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);

    int elem = s1.peek();
    std::cout<<"Element: "<<elem<<std::endl;

    s1.pop();
    std::cout<<"Element: "<<s1.peek()<<std::endl;

    s1.pop();
    std::cout<<"Element: "<<s1.peek()<<std::endl;
    

    return 0;
}