#include <iostream>

class Entity
{
    private:
    int data;
    int priority;

    public:
    Entity();
    Entity(int d, int p);
    void setData(int d);
    void setPriority(int p);
    int getData();
    int getPriority();
    void show();
};