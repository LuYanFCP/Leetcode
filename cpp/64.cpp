class Solution {
public:
    int sumNums(int n) {
        int sum = 0;
        _sum(n, sum);
        return sum;
    }
    int _sum(int n, int &sum) {
        sum += n;
        return n && _sum(n-1, sum);
    }
};