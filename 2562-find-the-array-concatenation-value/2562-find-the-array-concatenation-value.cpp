class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        int n = nums.size();

        int start = 0;
        int end = n-1;
        
        long long ans = 0;

        while (start < end) {
            string s = to_string(nums[start]) + to_string(nums[end]);
            ans = ans + stoll(s);
            start++;
            end--;
        }
        if (start == end) {
            ans = ans + nums[end];
        }

        return ans;
    }
};