class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int s = 0;
        int e = n - 1;
        int mid = s + (e - s) / 2;

        while (s <= e) {
            if (nums[mid] > nums[n - 1]) { // PART 1
                if (nums[mid] == target) {
                    return mid;
                }
                else if (nums[mid] < target) {
                    s = mid + 1;
                }
                else {
                    if (nums[0] > target) {
                        s = mid + 1;
                    } else {
                        e = mid - 1;
                    }
                }
            } 
            
            else { // PART 2
                if (nums[mid] == target) {
                    return mid;
                }
                else if (nums[mid] > target) {
                    e = mid-1;;
                }
                else {
                    if (nums[n-1] < target) {
                        e = mid-1;
                    } else {
                        s = mid+1;
                    }
                }
            }
            mid = s + (e - s) / 2;
        }
        return -1;
    }
};