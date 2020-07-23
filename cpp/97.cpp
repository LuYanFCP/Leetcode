#include <bits/stdc++.h>
#include <iterator>
using namespace std;



class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size()) return false;
        vector<char> str(s3.size());
        return dfs(s1, s2, s3, str, 0, 0, 0, map);
    }
    bool dfs(string &s1, string &s2, string &s3, vector<char> &str, int pos_1, int pos_2, int pos, unordered_map<pair<int, int>, bool>) {
        if (pos == s1.size() + s2.size()) {
            for (int i = 0; i < s1.size() + s2.size(); ++i) {
                if (s3[i] != str[i]) return false;
            }
            return true;
        } 
        if (pos_1 < s1.size() && s3[pos] == s1[pos_1]) {
            str[pos] = s1[pos_1];
            if (dfs(s1, s2, s3, str, pos_1+1, pos_2, pos+1)) return true;
            // pos_1 = i;
        }
        if (pos_2 < s2.size() && s3[pos] == s2[pos_2]) {
            str[pos] = s2[pos_2];
            if (dfs(s1, s2, s3, str, pos_1, pos_2+1, pos+1)) return true;
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    string s1 = "bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa", 
    s2 = "babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab"
    , s3 = "babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab";
    printf("%d\n", s.isInterleave(s1, s2, s3));
    return 0;
}

