class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int low = 0;
        int high = k - 1;
        int avg;

        int sum = 0;
        int ans = 0;

        for (int i = 0; i <= high; i++) {
            sum = sum + arr[i];
        }
        avg = sum / k;
        if (avg >= threshold) {
            ans++;
        }

        while (high < n) {

            low++;
            high++;
            if (high == n) {
                break;
            }
            
            sum = sum - arr[low - 1] + arr[high];
            avg = sum / k;
            if (avg >= threshold) {
                ans++;
            }
        }
        return ans;
    }
};