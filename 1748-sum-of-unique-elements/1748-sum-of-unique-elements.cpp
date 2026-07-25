class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            mpp[nums[i]]++;
        }

        int sum = 0;
        for (auto it : mpp) {
            if (it.second == 1) {
                sum += it.first;
            }
        }
        return sum;
    }
};