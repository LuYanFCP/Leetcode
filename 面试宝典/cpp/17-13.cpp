#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    TrieNode* next[26];
    bool isword;
    TrieNode() {
        fill(next, next+26, nullptr);
        isword = false;
    }
    ~TrieNode() {
        for (int i = 0; i < 26; ++i) if (next[i]) delete next[i];
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* p = root;
        int n = word.size();
        for (int i = n-1; i >=0; --i) { // 反插入
            int idx = word[i] - 'a';
            // printf("%c, %d\n", word[i],  idx);
            if (!p->next[idx]) p->next[idx] = new TrieNode();
            p = p->next[idx]; 
        }
        p->isword = true;
    }
};


class Solution {
public:
    int respace(vector<string>& dictionary, string sentence) {
        Trie t; // 创建书
        for (const string &str: dictionary) t.insert(str);
        size_t n = sentence.size();
        int dp[n+1];
        fill(dp, dp+n+1, INT_MAX);
        // printf("bool:%d\n", t.search("dekool"));
        dp[0] = 0;
        for (int i = 0; i < n; ++i) {  //遍历s

            // printf("%d\n", dp[i]);

            dp[i+1] = dp[i] + 1; // 先设定后修正
            TrieNode* p = t.root;
            for (int j = i; j >= 0; --j) {  //向后查找
                int idx = sentence[j] - 'a';
                //  printf("%d, %c, %d\n",i, sentence[j]],  idx);
                if (p->next[idx] == nullptr) break; // 没找到
                if (p->next[idx]->isword) {
                    dp[i+1] = min(dp[i+1], dp[j]);
                }
                p = p->next[idx];
            }
        }
        return dp[n];
    }
};