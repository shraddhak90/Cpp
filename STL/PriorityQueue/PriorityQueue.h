#include "Entity.h"

class PriorityQueue
{
  private:
  int size;
  Entity arr[100];
  int front, rear;

  public:
  PriorityQueue();
  PriorityQueue(int s);
  void insert(Entity e);
  Entity remove();
  bool isFull();
  bool isEmpty();
};