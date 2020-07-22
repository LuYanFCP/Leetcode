class Solution {
public:
    int minArray(vector<int>& numbers) {
        int n = numbers.size();
        int l = 0, r = n-1, mid;
        while(l < r) {
            mid = (r-l)/2 + l;
            if (numbers[mid] > numbers[r]) {
                l = mid + 1;
            } else if (numbers[mid] < numbers[r]) {
                r = mid;
            } else {
                --r;
            }

        }
        return numbers[l];
    }
};