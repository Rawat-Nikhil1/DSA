class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        bool res = false;
        int n = s1.length();
        int m = s2.length();

        if (n > m) return false;

        unordered_map<char, int> s1freq;
        unordered_map<char, int> window;

        for (char c : s1) {
            s1freq[c]++;
        }

        int low = 0;
        int high = n - 1;

        for (int i = 0; i <= high; i++) {
            window[s2[i]]++;
        }
        if (window == s1freq) {
            return true;
        }

        while (high < m) {
            high++;
            low++;
            window[s2[low - 1]]--;
            if (window[s2[low - 1]] == 0) {
                window.erase(s2[low - 1]);
            }
            if (high >= m) {
                break;
            }
            window[s2[high]]++;
            if (window == s1freq) {
                return true;
            }
        }
        return res;
    }
};