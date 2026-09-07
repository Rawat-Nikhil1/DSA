class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        int low = 0;
        int count = 0;
        int res = 0;

        for (int high = 0; high < nums.size(); high++) {

            if (nums[high] % 2 == 1) {
                count++;
            }

            while (count > k) {
                if (nums[low] % 2 == 1) {
                    count--;
                }
                low++;
            }
            res += high - low + 1;
        }

        return res;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};