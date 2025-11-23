class Solution {
public:
    int totalMoney(int n) {
        int weeks = n / 7;
        int days = n % 7;

        int total = 0;

        for (int w = 0; w < weeks; w++) {
            total += 7 * (w + 1) + 21;
        }

        int start = weeks + 1;
        for (int d = 0; d < days; d++) {
            total += start + d;
        }

        return total;
    }
};
