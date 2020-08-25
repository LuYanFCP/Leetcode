#include <bits/stdc++.h>
using namespace std;

class Solution {

    bool repeatedSubstringPattern(string s) {
        return (s+s).find(s, 1) != s.size();
    }
};
