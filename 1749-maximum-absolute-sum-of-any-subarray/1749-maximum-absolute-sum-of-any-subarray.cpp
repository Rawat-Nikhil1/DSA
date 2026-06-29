class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int maxSum = nums[0];
        int minSum = nums[0];
        int res1 = nums[0];
        int res2 = nums[0];
        int res = nums[0];

        for(int i=1;i<n;i++){
            int v1 = nums[i];
            int v2 = nums[i]+maxSum;

            maxSum = max(v1,v2);
            res1 = max(res1,maxSum);
        }
        for(int i=1;i<n;i++){
            int v1 = nums[i];
            int v2 = nums[i]+minSum;

            minSum = min(v1,v2);
            res2 = min(res2,minSum);
        }
        res = max(res1,abs(res2));
        return res;
    }
};