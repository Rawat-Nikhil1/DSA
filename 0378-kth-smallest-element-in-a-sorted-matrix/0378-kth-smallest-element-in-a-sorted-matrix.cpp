class Solution {
public:
    int total(vector<vector<int>> &arr , int n , int m , int guess){
        int row = n-1;
        int col = 0;
        int count = 0;

        while(row>=0 && col<m){
            if(arr[row][col]<=guess){
                count = count + row+1;
                col++;
            }
            else{
                row--;
            }
        }
        return count;
    }


    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();

        int low = matrix[0][0];
        int high = matrix[m-1][n-1];
        int guess = low+(high-low)/2;
        int res = -1;

        while(low<=high){
            int ans = total(matrix,n,m,guess);

            if(ans<k){
                low = guess+1;
            }
            else{
                res = guess;
                high = guess-1;
            }
            guess = low+(high-low)/2;

        }
        return res;
    }
};