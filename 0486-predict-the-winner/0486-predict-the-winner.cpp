class Solution {
public:

    int fun(vector<int>& nums, int l, int r) {

        if (l == r) {
            return nums[l];
        }
        int left = nums[l] - fun(nums, l + 1, r);
        int right = nums[r] - fun(nums, l, r - 1);
        return max(left, right);
    }

    bool predictTheWinner(vector<int>& nums) {

        int n = nums.size();
        int diff = fun(nums, 0, n - 1);

        return diff >= 0;
    }
};