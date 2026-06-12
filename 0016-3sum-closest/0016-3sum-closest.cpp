class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        int bestDiff = INT_MAX;
        int bestSum = 0;

        for (int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];
                int currentDiff = abs(target - currentSum);

                if (currentDiff < bestDiff) {

                    bestDiff = currentDiff;
                    bestSum = currentSum;
                }

                if (currentSum == target) {
                    return bestSum;
                }

                else if (currentSum < target) {
                    left++;
                } 
                
                else{
                    right--;
                }
            }
        }

        return bestSum;
    }
};