class Solution {
public:
    int find_max(vector<int> f) {
        int n = f.size();
        int max_count = INT_MIN;
        for (int i = 0; i < n; i++) {
            max_count = max(f[i], max_count);
        }
        return max_count;
    }

    int characterReplacement(string s, int k) {
        int n = s.length();

        vector<int> f(256, 0);
        int low = 0;
        int res = 0;

        for (int high = 0; high < n; high++) {
            f[s[high]]++;
            int len = high - low + 1;
            int max_count = find_max(f);

            int diff = len - max_count;

            while (diff > k) {
                f[s[low]]--;
                low++;
                len = high - low + 1;
                max_count = find_max(f);

                diff = len - max_count;
            }
            if (diff <= k) {
                res = max(res, len);
            }
        }
        return res;
    }
};