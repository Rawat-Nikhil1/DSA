class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int, int> freq;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;

            if (freq[nums[i]] > 2) {
                continue;
            }

            nums[count] = nums[i];
            count++;
        }

        return count;
    }
};