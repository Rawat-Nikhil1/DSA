class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> mpp;
        int n = s.length();
        int low = 0;
        int res = 0;
        int len;

        for (int high = 0; high < n; high++) {
            mpp[s[high]]++;

            while (mpp[s[high]] > 1) {
                len = high - low;
                mpp[s[low]]--;
                low++;
            }
            res = max(res, high - low + 1);
            
        }
        return res;
    }
};