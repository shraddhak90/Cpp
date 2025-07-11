#include "Entity.h"


Entity::Entity()
{
    data = 0;
    priority = 0;
}

Entity::Entity(int d, int p)
{
    data = d;
    priority = p;
}

void Entity::setData(int d)
{
    data = d;
}

void Entity::setPriority(int p)
{
    priority = p;
}

int Entity::getData()
{
  return data;
}

int Entity::getPriority()
{
    return priority;
}