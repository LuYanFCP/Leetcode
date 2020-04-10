#include <vector>
using std::vector;


struct Node 
{
    int k; // 表示它的阶数
    int key; // key value
    vector<Node*> forward;
    Node()=default;
    Node(int _k, int _key): k(_k), key(_key) {forward.push_back(nullptr);};
};

class ShipList
{
public:
    ShipList()=default;
    ShipList(double _p, int _maxN);
    int Search(int _key);  // 这类做简化，只返回key，而不是指针和具体的value
    void Insert(int _key);
    void Delete(int _key);
private:
    int randLevel();
    double p;
    int maxLevel;
    int maxN;
    vector<Node*> forward; 
    Node* _search(Node* node, int _key);
};