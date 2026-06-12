class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int n = nums.size();
        int i = 0;
        int j = 1;

        while(j<n){
            if(nums[i]==nums[j]){
                j++;
            }
            else{
                nums[i+1]= nums[j];
                i++;
            }
        }
        return (i+1);
    }
};

