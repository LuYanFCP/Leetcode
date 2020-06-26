#include<bits/stdc++.h>
using namespace std;

class TrieNode{
public:
    int isexist;
    TrieNode* next[26];
    TrieNode() {
        fill(next, next+26, nullptr);
        isexist = -1;
    }
    ~TrieNode() {
        for (int i = 0; i < 26; ++i)
            if (next[i]) delete next[i];
    }
};

class Solution {
public:
    int arr[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};  // 四个搜索方向

    void insert(TrieNode* root, const string& s, int& index) {
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            int idx = s[i] - 'a';
            if (!root->next[idx]) root->next[idx] = new TrieNode();
            root = root->next[idx];
        }
        root->isexist = index;
    }
    
    void dfs(int r, int c, TrieNode* root, unordered_set<int>& res, vector<vector<char>> b) {
        b[r][c] = '0';  // 走过的地方标记为0
        if (root && root->isexist) res.insert(root->isexist);
        for (int i = 0; i < 4; ++i) {
            int newr = r + arr[i][0], newc = c + arr[i][1];
            if (newr >= 0 && newc >= 0 && newr < b.size() && newc < b[0].size() && b[newr][newc] != '0' && root->next[b[newr][newc]-'a']) {
                dfs(newr, newc, root->next[b[newr][newc] - 'a'], res, b);
            }
        }
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        int n = words.size();
        for (int i = 0; i < n; ++i) {
            insert(root, words[i], i);
        }
        unordered_set<int> res; // 保存board中查到到的word序号

        for (int r = 0; r < board.size(); ++r) {
            for (int c= 0; c < board[r].size(); ++c) {
                if(root->next[board[r][c]-'a'])dfs(r,c,root->next[board[r][c]-'a'],res,board);
            }
        }
        vector<string>ress;//根据res中的序号制作string数组返回
        for(auto it:res){
            ress.push_back(words[it]);
        }

        return ress;
    }

};