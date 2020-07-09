#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        stack<int> st;
        int preRoot = INT_MAX;
        for (int i = postorder.size() - 1; i>=0; --i) {
            if (postorder[i] > preRoot) return false;
            while (! st.empty() && postorder[i] < st.top()) {
                preRoot = st.top();
                st.pop();
            }
            st.push(postorder[i]);
        }
        return true;
    }
};