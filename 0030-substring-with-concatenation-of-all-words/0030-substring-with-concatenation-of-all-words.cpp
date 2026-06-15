class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int n = words.size();
        int len = words[0].size();
        int total = n * len;

        unordered_map<string, int> need;
        for (auto &w : words) need[w]++;

        for (int offset = 0; offset < len; offset++) {
            unordered_map<string, int> have;
            int left = offset, count = 0;

            for (int right = offset; right + len <= s.size(); right += len) {
                string word = s.substr(right, len);

                if (need.count(word)) {
                    have[word]++;
                    count++;

                    while (have[word] > need[word]) {
                        string rem = s.substr(left, len);
                        have[rem]--;
                        left += len;
                        count--;
                    }

                    if (count == n) {
                        ans.push_back(left);
                        string rem = s.substr(left, len);
                        have[rem]--;
                        left += len;
                        count--;
                    }
                } else {
                    have.clear();
                    count = 0;
                    left = right + len;
                }
            }
        }

        return ans;
    }
};