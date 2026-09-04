class Solution {
public:
    int find_max(vector<int>&f) {
        int max_count = -1;
        for (int i = 0; i < 256; i++) {
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
                max_count = find_max(f);
                len = high - low + 1;

                diff = len - max_count;
            }
            res = max(res, len);
        }
        return res;
    }
};