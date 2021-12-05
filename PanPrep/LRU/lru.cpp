#include <unordered_map>
#include <string>
#include <iostream>
// simple single threaded LRUCache
using namespace std;

class LRUCache {
    class ListNode {
    public:
        ListNode *prev;
        ListNode *next;
        int key;
        int value;

        ListNode(int key, int value) {
            this->key = key;
            this->value = value;
        }

        ListNode() {}

        int getVal() {
            return this->value;
        }

        int getKey() {
            return this->key;
        }

        void setVal(int val) {
            this->value = val;
        }
    };

    unordered_map<int, ListNode *> cache;
    // each entry in linked list is <key, value>
    ListNode *head;
    ListNode *tail;
    int capacity; // total capacity

public:

    LRUCache(int capacity) {
        // cout<<"sizeof(ListNode) = "<<sizeof(ListNode)<<endl;
        this->capacity = capacity;
        head = new ListNode();
        tail = new ListNode();
        head->next = tail;
        head->prev = NULL;
        tail->next = NULL;
        tail->prev = head;
    }

    ~LRUCache() {
        for (auto &t: cache) {
            delete t.second;
        }
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;
        ListNode *valNode = cache.at(key);

        //remove node from the dll and put to end;
        //remove:
        ListNode *nextNode = valNode->next;
        ListNode *prevNode = valNode->prev;
        nextNode->prev = prevNode;
        prevNode->next = nextNode;

        //put valNode to end;
        tail->prev->next = valNode;
        valNode->prev = tail->prev;
        tail->prev = valNode;
        valNode->next = tail;

        return valNode->getVal();
    }

    void put(int key, int value) {
        if (cache.find(key) == cache.end()) {
            ListNode *newNode = new ListNode(key, value);
            if (cache.size() >= this->capacity) {
                //capacity surpassed
                //evict LRU item!
                ListNode *itemToDel = head->next;
                int keyToDel = itemToDel->getKey();
                //delete from dll
                head->next = itemToDel->next;
                head->next->prev = head;
                itemToDel->prev = NULL;
                itemToDel->next = NULL;
                //delete from hmap
                cache.erase(keyToDel);
                delete (itemToDel);
            }
            //insert new element in hmap
            cache.insert(make_pair(key, newNode));
            //put to end of dll
            tail->prev->next = newNode;
            newNode->prev = tail->prev;
            tail->prev = newNode;
            newNode->next = tail;
        } else {
            //item already in cache!
            ListNode *valNode = cache.at(key);
            valNode->setVal(value);
            get(key);
        }
    }

    string print() {
        string result = "";
//        for (auto &x: cache) {
//            result += "(" + to_string(x.first) + "," + to_string(x.second->value) + "),";
//        }
//        return result;
        ListNode *itr = this->tail->prev;
        while(itr!=this->head){
            result += "(" + to_string(itr->key) + "," + to_string(itr->value) + "),";
            itr = itr->prev;
        }
        return result;
    }
};

int main() {
    LRUCache *cache = new LRUCache(2);
    cache->put(10,20);
    cache->put(11,21);
    cache->put(12,22);
    cout<<cache->print()<<endl;
    cache->put(11,20);
    cout<<cache->print()<<endl;
    return 0;
}
