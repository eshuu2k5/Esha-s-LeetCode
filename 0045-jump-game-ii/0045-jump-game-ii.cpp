class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0;
        int cur = 0;
        int far = 0;

        for (int i = 0; i < nums.size() - 1; i++) {
            far = max(far, i + nums[i]);
            if (i == cur) {
                ans++;
                cur = far;
            }
        }

        return ans;
    }
};