#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());  // sort
        int l = 0, r = arr.size()-1;
        // int pos =  (l + r) / 2;
        int r_val = arr[r], l_val = arr[l];
        int res = (r_val + l_val) / 2, mid = (l+r)/2;
        while (l < r) {
            /* code */
                        
        }
        return res;
    }
};