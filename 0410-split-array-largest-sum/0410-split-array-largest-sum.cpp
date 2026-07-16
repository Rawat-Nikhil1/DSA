class Solution {
public:
    int fun(vector<int>& arr, int k, int guess) {
        int subarr = 1;
        int sum = 0;

        for (int i = 0; i < arr.size(); i++) {
            if (sum + arr[i] <= guess) {
                sum = sum + arr[i];
            } else {
                subarr++;
                sum = arr[i];
                if (subarr > k) {
                    return false;
                }
            }
        }
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();

        int low = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > low) {
                low = nums[i];
            }
        }

        int high = 0;
        for (int i = 0; i < n; i++) {
            int sum = nums[i] + high;
            high = sum;
        }
        int ans = -1;

        if (k > n) {
            return ans;
        }
        int guess = low + (high - low) / 2;

        while (low <= high) {
            if (fun(nums, k, guess)) {
                ans = guess;
                high = guess - 1;
            } else {
                low = guess + 1;
            }
            guess = low + (high - low) / 2;
        }
        return ans;
    }
};