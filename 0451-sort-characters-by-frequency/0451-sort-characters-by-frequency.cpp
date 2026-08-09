class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char, int> freq;

        for (int i = 0; i < s.length(); i++) {
            freq[s[i]]++;
        }

        priority_queue<pair<int, char>> pq;

        for (auto p : freq) {
            pq.push({p.second, p.first});
        }

        string ans = "";
        while (!pq.empty()) {

            int count = pq.top().first;
            char ch = pq.top().second;

            pq.pop();

            while (count--) {
                ans += ch;
            }
        }

        return ans;
    }
};