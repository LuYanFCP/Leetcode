#include <unordered_map>
#include <iostream>
#include <map>
#include <list>
#include <climits>

using std::list;
using std::unordered_map;
using std::multimap;

struct Node {
    int key;
    int val;
    int freq;
    // list<int>::const_iterator it; // 指针
};

class LFUCache {

/**
 * 1. 更新把所有LFU需要更新的操作抽象出一个函数。
 * 2. 插入时候也考虑
 */
public:
    using lfu_it = typename list<int>::const_iterator;
    LFUCache(int capacity): _capacity(capacity), _len(0) {};
    
    int get(int key) {
        auto it = map.find(key);
        if (it == map.end()) return -1;
        /**
         * 访问
        */
       lfu_it node_it = it->second;

       touch(node_it);
  
    }
    
    void put(int key, int value) {

    }
private:
    void touch(lfu_it it) {
        /**
         * 1. 更新freq, 也就是freq++
         * 2. 删除节点 it，
         * 3. 找到位置
         * 4. 插入节点
        */
        (*it).freq++;

    }
    unordered_map<int, lfu_it> map;
    list<Node> list;
    int _capacity;
    int _len;
};
auto gucciGang = []() {std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);return 0;}();

int main()
{
    std::list<int> lst = {1, 2, 3, 4, 5};
    auto begin = lst.begin();
    (*begin)++;
    
}