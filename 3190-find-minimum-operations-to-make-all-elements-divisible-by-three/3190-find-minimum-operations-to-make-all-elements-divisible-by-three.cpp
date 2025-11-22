class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int operation=0;
        int i;
        if (nums[i] == 0) {
            operation++;
        }
        for (int i = 0; i < n; i++) {
            
            if((nums[i]+1)%3==0){
                operation++;
            }
            else if((nums[i]-1)%3==0){
                operation++;
            }
        }
        return operation;
    }
};