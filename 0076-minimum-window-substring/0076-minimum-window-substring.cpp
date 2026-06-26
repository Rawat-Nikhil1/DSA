class Solution {
public:
    bool isCorrect(vector<int>& have, vector<int>& needed) {
        for (int i = 0; i < 256; i++) {
            if (have[i] < needed[i]) {
                return false;
            }
        }

        return true;
    }
    string minWindow(string s, string t) {
        
        int n = s.size();
        vector<int> have(256, 0);
        vector<int> needed(256, 0);
        for (int i = 0; i < t.size(); i++) {
            needed[t[i]]++;
        }

        int low = 0;
        int high = 0;
        int res = INT_MAX;
        int start = 0;

        for (high = 0; high < n; high++) {
            have[s[high]]++;

            while (isCorrect(have, needed)) {
                int len = high - low + 1;
                if (res > len) {
                    res = len;
                    start = low;
                }

                have[s[low]]--;
                low++;
            }
        }
        if (res == INT_MAX) {
            return "";
        }
        return s.substr(start, res);
    }
};