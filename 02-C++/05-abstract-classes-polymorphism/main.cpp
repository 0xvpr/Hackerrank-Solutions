#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <map>
#include <set>

using node_t = std::shared_ptr<struct Node>;
using map_t = std::map<int, node_t>;

struct Node {
    node_t prev;
    node_t next;
    int key;
    int value;
    Node(Node* p, Node* n, int k, int val)
        : prev(p)
        , next(n)
        , key(k)
        , value(val)
    {
    }
    Node(int k, int val)
        : prev(nullptr)
        , next(nullptr)
        , key(k)
        , value(val)
    {
    };
};

class Cache {
protected: 
    map_t  mp;                      // map the key to the node in the linked list
    int    cp;                      // capacity
    node_t tail;                    // double linked list tail pointer
    node_t head;                    // double linked list head pointer
    virtual void set(int, int) = 0; // set function
    virtual int get(int) = 0;       // get function

};

class [[nodiscard]] LRUCache : protected Cache {
public:
    LRUCache(size_t capacity)
        : cp(capacity)
        , head(nullptr)
        , tail(nullptr)
    {
    }
    ~LRUCache()
    {
    }
    void set(int key, int value) noexcept {
        if (!mp.count(key)) {
            auto node = std::make_shared<Node>(Node(key, value));
            node->next = nullptr;
            node->prev = head;

            if (head) {
                head->next = node;
            }
            head = node;
            mp[key] = node;

            if (!tail) {
                tail = node;
            }

            if (mp.size() > cp) {
                mp.erase(tail->key);
                tail = tail->next;
                if (tail) {
                    tail->prev = nullptr;
                }
            }
        } else {
            auto node = mp.at(key);
            if (!node->prev && node->next) {
                node->next->prev = nullptr;
                tail = node->next;
            }

            node->prev  = head;
            node->next  = nullptr;
            head->next  = node;
            node->value = value;
            head        = node;
        }
    }
    [[nodiscard]] int get(int key) noexcept {
        return mp.count(key) ? mp[key]->value : -1;
    }
private:
    size_t cp;
    node_t head;
    node_t tail;
};

int main() {
    int n;
    size_t capacity;
    std::cin >> n >> capacity;

    LRUCache l(capacity);
    for (int i = 0; i < n; ++i) {
        std::string command;
        std::cin >> command;
        if (command == "get") {
            int key;
            std::cin >> key;
            std::cout << l.get(key) << "\n";
       } else if (command == "set") {
          int key, value;
          std::cin >> key >> value;
          l.set(key,value);
       }
    }

    return 0;
}
