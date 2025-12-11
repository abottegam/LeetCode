/*146. LRU Cache
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.

Example 1:

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4


Constraints:

1 <= capacity <= 3000
0 <= key <= 104
0 <= value <= 105
At most 2 * 105 calls will be made to get and put.
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>

using namespace std;

struct Node
{
    pair<int,int> data;
    Node *next;
    Node *prev;
};

class LRUCache
{
    Node *head = nullptr;
    Node *tail = nullptr;
    unordered_map<int, Node *> cache;
    int size;

public:
    LRUCache(int capacity)
    {
        size = capacity;
    }

    int get(int key)
    {
        unordered_map<int, Node *>::const_iterator got = cache.find(key);
        if (got == cache.end())
        {
            return -1;
        }
        pushToFront(got->second);
        return got->second->data.second;
    }

    void put(int key, int value)
    {
        Node *temp = new Node;
        cache[key] = temp; //if key diff than value add the difference in
        temp->data = make_pair(key,value);
        temp->next = nullptr;
        temp->prev = nullptr;

        if (head == nullptr)
        {
            head = tail = temp;
        }
        else
        {
            if (cache.size() > size)
            {
                deleteFromBack();
            }
            if(size == 1){
                head = tail = temp;
            }
            else{
                head->prev = temp;
                temp->next = head;
                head = temp;
            }
        }
    }
//to push to front after get
    void pushToFront(Node *nuevo)
    {
        if (nuevo != head)
        {
            nuevo->prev->next = nuevo->next;
            if (nuevo == tail)
                tail = nuevo->prev;
            else
                nuevo->next->prev = nuevo->prev;
            head->prev = nuevo;
            nuevo->next = head;
            nuevo->prev = nullptr;
            head = nuevo;
        }
        
    }

    void deleteFromBack()
    {
        cache.erase(tail->data.first); // erase the key from map
        if(tail == head){
            tail = nullptr;
            head = nullptr;
        }
        else{
            tail->prev->next = nullptr;
            tail = tail->prev;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main()
{
    LRUCache *obj = new LRUCache(2);
    obj->put(1, 1);
    obj->put(2, 2);
    int param_1 = obj->get(1); // return 1
    obj->put(3, 3);            // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    int param_2 = obj->get(2); // returns -1 (not found)
    obj->put(4, 4);            // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    int param_3 = obj->get(1); // return -1 (not found)
    int param_4 = obj->get(3); // return 3
    int param_5 = obj->get(4); // return 4
}