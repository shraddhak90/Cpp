#include <iostream>
#include "QueueClass.h"

int main()
{
    QueueClass q;

    q.insert(10);
    q.insert(20);
    q.insert(30);
    q.insert(40);

    std::cout << "Front element: "<<q.getfront()<<std::endl;

    //q.remove();
    std::cout << "Remove element: "<<q.remove()<<std::endl;

    std::cout << "Front element: "<<q.getfront()<<std::endl;

    std::cout << "Remove element: "<<q.remove()<<std::endl;

    std::cout << "Front element: "<<q.getfront()<<std::endl;
    return 0;
}
