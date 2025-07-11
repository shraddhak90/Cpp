#include <iostream>
#include "PriorityQueue.h"

int main()
{
    PriorityQueue p(10);
    
    p.insert(Entity(4, 5));
    p.insert(Entity(3, 4));
    p.insert(Entity(7,7));

    Entity e = p.remove();
    std::cout <<"Removed element: "<<e.getData()<< " Priority: "<<e.getPriority()<<std::endl;

    Entity e1 = p.remove();
    std::cout <<"Removed element: "<<e1.getData()<< " Priority: "<<e1.getPriority()<<std::endl;
    return 0;
}