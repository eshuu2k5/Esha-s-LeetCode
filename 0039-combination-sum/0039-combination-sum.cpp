class Solution {
public:
    vector<vector<int>> ans;
    vector<int> cur;

    void dfs(vector<int>& candidates, int target, int idx) {
        if (target == 0) {
            ans.push_back(cur);
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {
            if (candidates[i] > target) continue;

            cur.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i);
            cur.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, target, 0);
        return ans;
    }
};