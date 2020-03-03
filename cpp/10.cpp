#include <string>
#include <iostream>
#include <cassert>
#include <vector>
using std::string;
using std::vector;

struct Pattern
{
    vector<char> str;
    vector<bool> isRepeat;
    int len;
    bool flag = false;
    Pattern(string &p) {
        char c;
        len = 0;
        int plus = 0;
        for (int i = 0; i < p.size(); ++i) {
            
            c = p[i];
            if (c == '*') {
                isRepeat.pop_back();
                isRepeat.push_back(true);
                plus++;
            } else {
                str.push_back(c);
                isRepeat.push_back(false);
                len++;
            }
        }
        if (plus == len) {
            flag = true;
        }
    }
    // void print() {
    //     for (char c: str) {
    //         std::cout << c << " " ; 
    //     }
    //     std::cout << std::endl;
    //     for (bool b: isRepeat) {
    //         std::cout << b << " ";
    //     }
    //     std::cout << std::endl;
    // }
};

class Solution {
public:
    /* 
     * 72 ms, faster than 23.75% 
     * 7.8 MB, less than 100.00%
     */
    bool isMatch(string s, string p) {
        Pattern pattern(p);
        if (s.size() == 0 && pattern.flag)
            return true;
        return match(s, pattern, 0, 0);
    }
    bool match(string &s, Pattern &p, int s_pos, int p_pos) {
        if (s_pos == s.size()) {
            for (int i = p_pos; i < p.len; ++i) {
                if (!p.isRepeat[i])
                    return false;
            }
            return true;
        }

        if (p_pos == p.len)
            return false;
        
        char pattern = p.str[p_pos];
        if (pattern == s[s_pos] || pattern == '.') {
            if (p.isRepeat[p_pos]) {
                return match(s, p, s_pos + 1, p_pos) || match(s, p, s_pos, p_pos + 1);
            } else {
                return match(s, p, s_pos + 1, p_pos + 1);
            }
        } else if (p.isRepeat[p_pos]) {
            return match(s, p, s_pos, p_pos+1);
        }
        return false;
    }
};

int main() {
    Solution s;
    
    assert(s.isMatch("aa", "a") == false);
    assert(s.isMatch("aa", "a*") == true);
    assert(s.isMatch("ab", ".*") == true);
    assert(s.isMatch("aab", "c*a*b") == true);
    assert(s.isMatch("ab", ".*c") == false);
    assert(s.isMatch("aaa", "ab*ac*a") == true);
    assert(s.isMatch("bbbba", ".*a*a") == true);
    assert(s.isMatch("", "c*c*") == true);
    assert(s.isMatch("aabcbcbcaccbcaabc", ".*a*aa*.*b*.c*.*a*"));
    /*
"aaa"
"ab*ac*a"*/
}