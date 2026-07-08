class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            if (st.empty()) {
                st.push({s[i], 1});
            } else if (st.top().first == s[i]) {
                if (st.top().second < k - 1) {
                    st.top().second++;
                } else {
                    st.pop();
                    continue;
                }
            } else {
                st.push({s[i], 1});
            }
        }
        string ans;
        while (!st.empty()) {
            char ch = st.top().first;
            int charCount = st.top().second;

            for (int i = 0; i < charCount; i++) {
                ans += ch;
            }

            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};