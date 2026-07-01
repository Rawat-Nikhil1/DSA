class Solution {
public:
    int pivotInteger(int n) {

        int left = 0;
        int right = 0;
        int sum = 0;

        for (int i = 1; i <= n; i++) {
            sum = sum + i;
        }

        for (int i = 1; i <= n; i++) {
            right = sum - i - left;

            if (left == right) {
                return i;
            }

            left = left + i;
        }

        return -1;
    }
};