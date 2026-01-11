#include <iostream>
#include <unordered_map>
#include <mutex>
using namespace std;

class LRUCache
{
  private:
    int capacity;

    struct Node
    {
        int key, value;
        Node* next;
        Node* prev;

        Node(int k, int v):key(k), value(v), next(nullptr), prev(nullptr)
        {
        }
    };

  public:
    Node* head, *tail; // head and tail for MRU and LRU
    unordered_map<int, Node*> cache;
    mutex mtx;

    //Remove node from tail --> LRU removal
    void removeNode(Node* node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addAtFront(Node* node)
    {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

  public:
    LRUCache(int c)
    {
      capacity = c;

      head = new Node(-1, -1);
      tail = new Node(-1, -1);

      head->next = tail;
      tail->prev = head;
    }

    //To get key from cache, and Move it to MRU
    int get(int key)
    {
        lock_guard<mutex> lock(mtx);
        if (cache.find(key)== cache.end())
        {
            return -1;
        }

        Node* node = cache[key];
        removeNode(node);
        addAtFront(node);

        return node->value;
    }

    //If capacity is full, then remove from LRU and add new entry to front
    void put(int k, int v)
    {
        lock_guard<mutex> lock(mtx);
        //If key exists, update and move to MRU
        if (cache.find(k) != cache.end())
        {
            Node* node = cache[k];
            node->value = v;
            removeNode(node);
            addAtFront(node);
            return;
        }

        //If capacity is full, then remove from LRU
        if (cache.size() == capacity)
        {
            Node* lru = tail->prev;
            cache.erase(lru->key);
            removeNode(lru);
            delete lru;
        }

        Node* node = new Node(k, v);
        addAtFront(node);
        cache[k] = node;
    }
};

int main() {
    LRUCache lru(2);

    lru.put(1, 10);
    lru.put(2, 20);

    cout << lru.get(1) << endl; // 10 (MRU: 1)
    lru.put(3, 30);             // Removes key 2 (LRU)

    cout << lru.get(2) << endl; // -1
    cout << lru.get(3) << endl; // 30

    return 0;
}