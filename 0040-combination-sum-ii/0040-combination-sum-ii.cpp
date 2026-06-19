class Solution {
public:
    vector<vector<int>> ans;
    vector<int> cur;

    void solve(vector<int>& candidates, int target, int idx) {
        if (target == 0) {
            ans.push_back(cur);
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {
            if (i > idx && candidates[i] == candidates[i - 1]) continue;
            if (candidates[i] > target) break;

            cur.push_back(candidates[i]);
            solve(candidates, target - candidates[i], i + 1);
            cur.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        solve(candidates, target, 0);
        return ans;
    }
};