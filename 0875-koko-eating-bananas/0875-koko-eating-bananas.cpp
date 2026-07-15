class Solution {
public:
    long long int timeToEat(vector<int>& arr, int s) {
        long long h = 0;
        for (int i = 0; i < arr.size(); i++) {
            h = h + arr[i] / s;
            if (arr[i] % s != 0) {
                h++;
            }
        }
        return h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        int low = 1;
        int high = INT_MIN;
        for (int i = 0; i < n; i++) {
            high = max(high, piles[i]);
        }
        int guess = low + (high - low) / 2;
        int ans = -1;

        while (low <= high) {
            if (timeToEat(piles, guess) > h) {
                low = guess + 1;
            } else if (timeToEat(piles, guess) <= h) {
                ans = guess;
                high = guess - 1;
            }
            guess = low + (high - low) / 2;
        }
        return ans;
    }
};