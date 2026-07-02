class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> a;
        vector<int> f(n + 1, 1);

        for (int i = 1; i <= n; i++) {
            a.push_back(i);
            f[i] = f[i - 1] * i;
        }

        k--;

        string ans;

        for (int i = n; i >= 1; i--) {
            int idx = k / f[i - 1];
            ans += char(a[idx] + '0');
            a.erase(a.begin() + idx);
            k %= f[i - 1];
        }

        return ans;
    }
};