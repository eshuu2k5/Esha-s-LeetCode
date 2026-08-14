class Solution {
public:
    vector<string> ans;

    void solve(string &s, int pos, int parts, string cur) {
        if (parts == 4) {
            if (pos == s.size())
                ans.push_back(cur);
            return;
        }

        for (int len = 1; len <= 3 && pos + len <= s.size(); len++) {
            if (len > 1 && s[pos] == '0')
                break;

            string part = s.substr(pos, len);

            if (stoi(part) > 255)
                break;

            string next = cur.empty() ? part : cur + "." + part;
            solve(s, pos + len, parts + 1, next);
        }
    }

    vector<string> restoreIpAddresses(string s) {
        solve(s, 0, 0, "");
        return ans;
    }
};