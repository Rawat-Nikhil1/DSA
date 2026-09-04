class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int low = 0;
        int zero_count = 0;
        int res = 0;

        for (int high = 0; high < n; high++) {
            if (nums[high] == 0) {
                zero_count++;
            }
            while (zero_count > k) {
                if (nums[low] == 0) {
                    zero_count--;
                }
                low++;
            }
            res = max(res, high - low + 1);
        }
        return res;
    }
};