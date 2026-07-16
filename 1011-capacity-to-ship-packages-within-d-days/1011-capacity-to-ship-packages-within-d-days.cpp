class Solution {
public:
    bool possible(vector<int>& arr, int k, int guess) {
        int n = arr.size();
        int day = 1;
        int weight = 0;
        for (int i = 0; i < n; i++) {
            if (weight + arr[i] <= guess) {
                weight = weight + arr[i];
            } else {
                day++;
                weight = arr[i];
                if (day > k) {
                    return false;
                }
            }
        }
        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();

        int low = *max_element(weights.begin(), weights.end());
        int high = 0;
        for (int i = 0; i < n; i++) {
            high = high + weights[i];
        }

        int guess = low + (high - low) / 2;
        int res = -1;

        while (low <= high) {
            if (possible(weights, days, guess)) {
                res = guess;
                high = guess - 1;
            } else {
                low = guess + 1;
            }
            guess = low + (high - low) / 2;
        }
        return res;
    }
};