#include <cstdlib>
#include <cmath>
#include <vector>
#include "ShipList.h"

using std::rand;
using std::ceil;
using std::log;
using std::vector;

int ShipList::randLevel()
{
    int level = 1;
    for (;rand() < p && maxLevel; level++);
    return level;
}

ShipList::ShipList(double _p, int _maxN) 
{
    p = _p;
    maxN = _maxN;
    maxLevel = static_cast<int>(ceil(log(_maxN) / log(1/p)));
    forward = vector<Node*>(maxLevel+1, nullptr);  // 使用拷贝构造进行初始化

}

int 
ShipList::Search(int _key)
{

    // 出循环的时候已经到达最后一层
    vector<Node*>& p = forward;
    for (int i = maxLevel; i > 0; --i) {
        if (!p[i]) continue;
        if (p[i]->key < _key)
            p = p[i]->forward;
        else if (p[i]->key == _key)
            return p[i]->key;
    }
    while (1) {
        if (p[1]->key == _key) {
            return p[1]->key;
        } else if (p[1]->key < _key) {
            return -1;
        }
        p = p[1]->forward;
    }
    return -1;
}

void 
ShipList::Insert(int _key)
{
    vector<Node*> update(maxLevel, nullptr); // 用于更新
    vector<Node*>& p = forward;
    for (int i = maxLevel; i > 0; --i) {
        if (!p[i]) continue;
        if (p[i]->key < _key) {
            update[i] = p[i];
            p = p[i]->forward;
        }
        else if (p[i]->key == _key)
            return ; // 因为出现相等了
    }

    // 循环找插入节点
    while (1) {
        if (p[1]->key < _key) {
            update[1] = p[1];
            p = p[1]->forward;
        } else if (p[1]->key == _key) {
            return; // 直接返回
        } else break; 
    }
    
    /**
     *  创建节点:
     *  1. 随机选randlevel
     *  2. new节点
     *  3. 更新具体链表信息
     */
    int level = randLevel();
    Node* newNode = new Node(level, _key);
    p = newNode->forward;
    for (int i = 1; i <= level; ++i) {
        p[i] = update[i]->forward[i];
        update[i]->forward[i] = newNode;
    }
}

void 
ShipList::Delete(int _key) 
{
    if (Search(_key) < 0) return;
    vector<Node*> update(maxLevel, nullptr); // 用于更新
    vector<Node*>& p = forward;
    for (int i = maxLevel; i > 0; --i) {
        if (!p[i]) continue;
        if (p[i]->key < _key) {
            update[i] = p[i];
            p = p[i]->forward;
        }
        else if (p[i]->key == _key)
            return ; // 因为出现相等了
    }

    // 循环找插入节点
    while (1) {
        if (p[1]->key < _key) {
            update[1] = p[1];
            p = p[1]->forward;
        } else
            break; // =等于跳出循环
    }

    // 找到的离开该最近的节点
    // p是forward的引用
    int level = update[1]->forward.size();
    Node* delPtr = update[1];
    for (int i = 1; i <= level; ++i) {
        update[i]->forward[i] = p[i];
    }
    delete delPtr;
}