class Solution {
public:
    double myPow(double x, int n) {
        long long p = n;
        if (p < 0) {
            x = 1.0 / x;
            p = -p;
        }

        double ans = 1.0;

        while (p) {
            if (p & 1) ans *= x;
            x *= x;
            p >>= 1;
        }

        return ans;
    }
};