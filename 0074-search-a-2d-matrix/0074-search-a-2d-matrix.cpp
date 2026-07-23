class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int low = 0;
        int high = m * n - 1;
        int mid = low + (high - low) / 2;

        while (low <= high) {
            int row = mid / n;
            int col = mid % n;

            if(matrix[row][col]==target){
                return true;
            }
            else if(matrix[row][col]<target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
            mid = low + (high - low) / 2;
        }
        return false;
    }
};