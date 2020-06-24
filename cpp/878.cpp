#include<bits/stdc++.h>
class Solution {
public:
    int nthMagicalNumber(int N, int A, int B) {
        int a_b = A/gcd(A,B)*B;
        int MOD = (int)1e9 + 7;
        long i = 1, j = (long)1e15;
        long mid, n;
        while (i<j) {
            mid = (j - i)/2 + i;
            n = mid/A + mid/B - mid/a_b;
            if (n < N) {
                i = mid + 1;
            } else {
                j = mid;
            }
        }
        return (int) (i % MOD);
    }
    int gcd(int x, int y) {
        return !x ? y: gcd(y % x, x); 
    }

};