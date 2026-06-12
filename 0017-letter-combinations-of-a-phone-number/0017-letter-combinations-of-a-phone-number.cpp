class Solution {
public:
    vector<string> ans;
    vector<string> mp = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    void solve(string &digits, int idx, string cur) {
        if (idx == digits.size()) {
            ans.push_back(cur);
            return;
        }

        string s = mp[digits[idx] - '0'];

        for (char c : s)
            solve(digits, idx + 1, cur + c);
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};

        solve(digits, 0, "");
        return ans;
    }
};