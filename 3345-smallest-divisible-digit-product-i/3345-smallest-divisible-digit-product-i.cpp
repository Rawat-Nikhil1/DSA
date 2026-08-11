class Solution {
public:
    int fun(int n) {
        int prod = 1;
        while (n > 0) {
            int digit = n % 10;
            n = n / 10;

            prod = prod * digit;
        }
        return prod;
    }
    int smallestNumber(int n, int t) {

        while (true) {
            int ans = fun(n);
            if (ans % t == 0) {
                return n;
            }
            n = n + 1;
        }
    }
};