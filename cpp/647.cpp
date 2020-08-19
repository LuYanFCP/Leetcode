#include <bits/stdc++.h>

using namespace std;

#define PRINT_VECTOR(vec, type) \
do { \
    copy(vec.begin(), vec.end(), ostream_iterator<type>(cout, " ")); \
    cout << endl; \
} while(0)

#define CHECK(j, k, m)  ((j) >= 0) && ((k) < (m))


class Solution {
public:
    /**
     * 
     */
	int countSubstrings(string s)
	{
        ostringstream strbuf;
        strbuf << "#";
        for (const char &c: s) {
            strbuf << c << "#";
        }
        string str = strbuf.str();
        // #a#b#c#
        int m = str.size();
        vector<int> radius(m, 0); 

        int r_radius = 0, mid_index = 0, count = 0;
        for (int i = 0; i < m; ++i) {
            
            if (i <= r_radius + mid_index) {
                // 对称位置是否超出右边的限制
                // printf("%d, %d\n", radius[mid_index*2-i], mid_index+r_radius-i);
                radius[i] = min(radius[mid_index*2-i], mid_index+r_radius-i);
            }
            #if 0
            printf("radius[%d]=%d ", i, radius[i]);
            printf(" str[i]=%c ", str[i]);
            printf("str[i-radius[i]-1]=%c, str[i+radius[i]+1]=%c ", str[i-radius[i]-1], str[i+radius[i]+1] );
            printf("%d ===> %d,%d\n", CHECK(i-radius[i]-1, i+radius[i]+1, m), i, str[i-radius[i]-1] == str[i + radius[i]+1]);
            #endif
            while (CHECK(i-radius[i]-1, i+radius[i]+1, m) && str[i-radius[i]-1] == str[i+radius[i]+1]) {
                ++radius[i];
            }
            
            if (mid_index + r_radius < i + radius[i]) {
                r_radius = radius[i];
                mid_index = i;
            }
            count += (radius[i]+1)/2;
        }
        // PRINT_VECTOR(radius, int);
        return count;
    }
};

#if 0

#define CHECK(j, k, m)  ((j) >= 0) && ((k) < (m))

    /** 基础算法*/
    int countSubstrings(string s) {
        ostringstream str;
        int n = s.size(), count = 0;
        for (int i = 0; i < n; ++i) {

            str << "#" << s[i];
        }
        str << '#';
        string ss = str.str();

        int j, k, m = ss.size(), flag_num;
        for (int i = 1; i < m; ++i) {
            j = i - 1, k = i + 1;
            flag_num = ss[i] == '#'? 1:0;
            while(CHECK(j, k, m)) {
                if (ss[j]=='#') flag_num++;
                if (ss[j] == ss[k]){
                    if (ss[j]=='#') {
                        if (flag_num < 2) count++;
                    } else {
                        count++;
                    }
                } 
                else break;
                j--;
                k++;
            }
        }
        return count;
    }
#endif


int main(int argc, char const *argv[])
{
    Solution s;
    freopen("test.in", "r", stdin);
    string str;
    while (cin >> str) {
        /* code */
        cout << str << endl;
        int result = s.countSubstrings(str);
        cout << result << endl;
    }
    
    return 0;
}
