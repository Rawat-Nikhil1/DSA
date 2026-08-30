class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;

        unordered_map<char, int> pFreq;
        unordered_map<char, int> window;

        for (char c : p) {
            pFreq[c]++;
        }

        int n = s.size();
        int m = p.size();

        if (m > n)
            return ans;

        int low = 0;
        int high = m - 1;

        for (int i = 0; i <= high; i++) {
            window[s[i]]++;
        }
        if (window == pFreq) {
            ans.push_back(low);
        }

        while (high < n) {
            high++;
            low++;
            
            window[s[low - 1]]--;
            if (window[s[low - 1]] == 0) {
                window.erase(s[low - 1]);
            }

            if (high >= n) {
                break;
            }
            window[s[high]]++;

            if (window == pFreq) {
                ans.push_back(low);
            }
        }
        return ans;
    }
};