class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int best_sum = nums[0];
        int ans = nums[0];
        int n = nums.size();
        
        for (int i = 1; i < n; i++) {
            int v1 = nums[i]+best_sum;
            int v2 = nums[i];
            best_sum = max(v1,v2);
            ans = max(ans,best_sum);
        }
        return ans;
    }
};