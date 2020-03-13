#include <unordered_map>
#include <cstdio>
using std::printf;
// LRU cache 
struct Node {
    int val;
    int key;
    struct Node *pre, *next;
    Node(int _key, int _val): key(_key), val(_val), pre(nullptr), next(nullptr) {}
};


class LRUCache {
public:
    LRUCache(int capacity) {
        cache = new int[capacity];
        this->capacity = capacity; // 链表容量
        hashmap = new std::unordered_map<int, Node*>(capacity); // 初始化一个hashmap去存放
        len = 0; // 链表的长度
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->pre = head;
    }
    
    int get(int key) {
        auto target = hashmap->find(key);
        if (target == hashmap->end())
            return -1;
        // 放置在最前面的节点
        Node* pos = target->second;
        // 去掉节点
        del_node(pos);
        // 加上插入节点头
        insert_head(pos);

        return pos->val;
    }
    
    void put(int key, int value) {
        auto it = hashmap->find(key);
        if (it == hashmap->end()) {
            // 默认插入不重复
            if (len < capacity) {
                Node* node = new Node(key, value);
                insert_head(node);
                len++; // 增加长度
                (*hashmap)[key] = node; // 插入
            } else {
                // 需要替换
                Node* tail_node = get_tail(); // 一定有，不用判空
                del_node(tail_node); // 从列表中删除
                int pre_key = tail_node->key;
                tail_node->key = key;
                tail_node->val = value; // 更换val
                insert_head(tail_node); // 从新插头
                // 更新hash表
                auto temp = hashmap->find(pre_key);
                hashmap->erase(temp); // 删除
                (*hashmap)[key] = tail_node;
            }
        } else {
            // 存在
            it->second->val = value;
            get(key); // 提前一下key
        }
    }
    ~LRUCache() {
        if (cache) delete[] cache;
        if (hashmap) delete hashmap;
    }
private:
    Node* head;
    Node* tail; 
    int len;
    int* cache;
    int capacity;
    std::unordered_map<int, Node*>* hashmap;

    void insert_head(Node *node) {
        if (!node) return;
        head->next->pre = node;
        node->next = head->next;
        node->pre = head;
        head->next = node; 
    }
    Node* get_tail() {
        if (!len) return nullptr; // 如果是0长度
        return tail->pre; 
    }

    void del_node(Node* node) {
        node->pre->next = node->next;
        node->next->pre = node->pre;
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
    LRUCache lru(2);
    lru.put(1, 1);
    lru.put(2, 2);
    lru.get(1);
    lru.put(3, 3);
    lru.get(2);
    lru.put(4, 4);
    lru.get(1);
    lru.get(3);
    lru.get(4);

}