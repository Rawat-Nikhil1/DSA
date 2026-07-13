class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        int e = n - 1;
        int mid = s + (e - s) / 2;
        int res = -1;

        while (s <= e) {

            if (nums[0] <= nums[n - 1]) {
                return nums[0];
            }
            else if (nums[mid] > nums[n - 1]) {
                s = mid + 1;
            } 
            else {
                res = nums[mid];
                e = mid - 1;
            }
            mid = s + (e - s) / 2;
        }
        return res;
    }
};