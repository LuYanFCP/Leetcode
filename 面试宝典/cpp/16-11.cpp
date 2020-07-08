class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        if (!k) return vector<int>();
        if (shorter == longer) return vector<int> {k*longer};

        vector<int> res(k+1);
        // int diff = longer - shorter, max = longer * k;
        // res[0] = shorter * k;
        for (int i = 0; i < k+1; ++i) res[i] = (k-i)*shorter+i*longer;
        return res;
            
    }
};