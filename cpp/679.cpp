#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    static constexpr int TARGET = 24;
    static constexpr double EPSILON = 1e-6;
    enum {ADD = 0, MULTIPLY = 1, SUBTRACT = 2, DIVIDE = 3};

    bool judgePoint24(vector<int> &nums) {
        vector<double> l;
        for (const int &num : nums) {
            l.emplace_back(static_cast<double>(num));
        }
        return solve(l);
    }

    bool solve(vector<double> &l) {
        if (l.size() == 0) {
            return false;
        }
        if (l.size() == 1) {
            return fabs(l[0] - TARGET) < EPSILON;
        }
        int size = l.size();
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (i != j) {
                    vector<double> list2 = vector<double>();
                    for (int k = 0; k < size; k++) {
                        if (k != i && k != j) {
                            list2.emplace_back(l[k]);
                        }
                    }
                    for (int k = 0; k < 4; k++) {
                        if (k < 2 && i > j) {
                            continue;
                        }
                        switch (k)
                        {
                        case ADD:
                            list2.emplace_back(l[i] + l[j]);
                            break;
                        case MULTIPLY:
                            list2.emplace_back(l[i] * l[j]);
                            break;
                        case SUBTRACT:
                            list2.emplace_back(l[i] - l[j]);
                            break;
                        case DIVIDE: 
                            if (fabs(l[j]) < EPSILON) {
                                continue;
                            }
                            list2.emplace_back(l[i] / l[j]);
                            break;
                        }

                        if (solve(list2)) {
                            return true;
                        }
                        list2.pop_back();  // 全排列
                    }
                }
            }
        }
        return false;
    }
};


int main(int argc, char const *argv[])
{
    
    return 0;
}
