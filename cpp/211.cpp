#include<bits/stdc++.h>
using namespace std;

class TrieNode{
public:
    TrieNode* next[26];
    bool isword;
    TrieNode() {
        memset(next, NULL, sizeof(next));
        isword = false;
    }
    ~TrieNode() {
        for (int i = 0; i < 26; ++i)
            if (next[i]) delete next[i];
    }
};

class WordDictionary {

TrieNode* root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* p = root;
        int n = word.size();
        for (int i = 0; i < n; ++i) {
            int idx = word[i] - 'a';
            if (!p->next[idx]) p->next[idx] = new TrieNode();
            p = p->next[idx];
        }
        p->isword = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        TrieNode* p = find(root, word);
        return p && p->isword;
    }

    TrieNode* find(TrieNode* p, string word) {
        int n = word.size();
        for(int i = 0; i < n && p; ++i) {
            if (word[i] == '.') {
                for (int j = 0; j < 26; ++j) {
                    if (p->next[j]) {
                        int len = word.size() - i - 1;
                        if (len >= 1) {
                            TrieNode *res = find(p->next[j], word.substr(i+1, len));
                            if (res && res->isword) return res;
                        } else if (p->next[j]->isword) 
                            return p->next[j];
                    }
                }
                return nullptr;
            } else {
                p = p->next[word[i]-'a'];
            }
        }
        return p;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */