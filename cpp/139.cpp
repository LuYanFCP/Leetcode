#include<bits/stdc++.h>
using namespace std;

class TrieNode{
public:
    TrieNode* next[26];
    bool isword;
    TrieNode() {
        fill(next, next+26, nullptr);
        isword = false;
    }
    ~TrieNode() {
        for (int i = 0; i < 26; ++i)
            if (next[i]) delete next[i];
    }
};


class Solution {
public:
    void insert(const string &s, TrieNode* root) {
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            int idx = s[i] - 'a';
            if (!root->next[idx]) root->next[idx] = new TrieNode();
            root = root->next[idx];
        }
        root->isword = true;
    }
    bool search(const string &s, TrieNode* root) {
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            int idx = s[i] - 'a';
            if (!root->next[idx]) return false;
            root = root->next[idx];
        }
        return root && root->isword;
    }
    bool findWord(const string &s, TrieNode* root, int begin, vector<bool> &hash) {
        int n = s.size();
        
        if (begin == n) return true;
        TrieNode* p = root;
        bool flag = false;
        for (int i = begin; i < n; ++i) {
            int idx = s[i] - 'a';
            if (!p->next[idx]) {
                if (p->isword) {
                    p = root;  // 找到一个
                    --i;
                    continue;
                } else {
                    return flag;
                }
            }
            if (p->next[idx]->isword) {
                if (!hash[i]) {
                    hash[i] = true;
                    flag = flag || findWord(s, root, i+1, hash); // 如果完成之后就在进行
                }
            } 
            p = p->next[idx];
        }
        return (p && p->isword) || flag;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        TrieNode* root = new TrieNode();  // 根节点
        for (const string &_s : wordDict) insert(_s, root);
        vector<bool> ht(s.size(), false);
        return findWord(s, root, 0, ht);
    }
};

int main()
{
    
    Solution s;
    vector<string> dict = {"a","abc","b","cd"};
    printf("%d\n", s.wordBreak("abcd", dict));
}
