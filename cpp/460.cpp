#include <unordered_map>
#include <cstdio>
#include <climits>
using std::printf;
struct Node {
    int val;
    int key;
    int freq;
    struct Node *pre, *next;
    Node(int _key, int _val): key(_key), val(_val), pre(nullptr), next(nullptr), freq(0) {}
};

class LFUCache {

/**
 * 1. 更新把所有LFU需要更新的操作抽象出一个函数。
 * 2. 插入时候也考虑
 */
public:
    LFUCache(int capacity) {
        cache = new int[capacity];
        this->capacity = capacity; // 链表容量
        hashmap = new std::unordered_map<int, Node*>(capacity); // 初始化一个hashmap去存放
        len = 0; // 链表的长度
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->freq = INT_MAX;  // 一定会到这个位置停止
        tail->freq = 0;  // 尾节点的freq一定是0
        head->next = tail;
        tail->pre = head;
    }
    
    int get(int key) {
        auto target = hashmap->find(key);
        if (target == hashmap->end())  // 如果能get到一定能命中
            return -1;
        Node* pos = target->second; // 获得node的位置，进行更新
        /**
         * 1. 保留pos之前的节点指针
         * 2. 删除pos节点
         * 3. pos->freq++;
         * 4. 找到pos节点插入位点
         * 5. 
        */
        Node* it = pos->pre;
        del_node(pos); // 删除节点
        ++(pos->freq);

        // 找到插入位点，进行插入
        it = _up(it);
        insert_after(it, pos);
        // 返回pos的val
        return pos->val;
    }
    
    void put(int key, int value) {
        auto it = hashmap->find(key);
        if (it == hashmap->end()) {
            // 默认插入不重复
            if (len < capacity) {
                Node* node = new Node(key, value);
                node->freq = 1;
                // insert_head(node);
                /**
                 * 1. 从尾部开始
                 */
                Node* it = tail;
                it = _up(it);
                insert_after(it, node);
                len++; // 增加长度
                (*hashmap)[key] = node; // 插入
            } else {
                // 需要替换
                Node* tail_node = get_tail(); // 一定有，不用判空
                Node* it = tail_node->pre;
                del_node(tail_node); // 从列表中删除
                int pre_key = tail_node->key;
                tail_node->key = key;
                tail_node->val = value; // 更换val
                tail_node->freq = 1;
                it = _up(it);
                insert_after(it, tail_node);
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

    Node* _up(Node* pos) {
        int pos_freq = pos->freq;
        for (; pos->freq <= pos_freq; pos = pos->pre);
        return pos;
    }

    void insert_after(Node* pos, Node *node) {
        node->next = pos->next; // node后一个指针指向下一个
        pos->next->pre = node;  // pos后一个有一个指针指向node
        node->pre = pos; // node前指
        pos->next = node; // Post后指
    }

    void del_node(Node* node) {
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main()
{
    LFUCache cache( 2 /* capacity */ );
    cache.put(1, 1);
    cache.put(2, 2);
    cache.get(1);       // returns 1
    cache.put(3, 3);    // evicts key 2
    cache.get(2);       // returns -1 (not found)
    cache.get(3);       // returns 3.
    cache.put(4, 4);    // evicts key 1.
    cache.get(1);       // returns -1 (not found)
    cache.get(3);       // returns 3
    cache.get(4);       // returns 4
}