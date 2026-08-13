class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_map<int, int> mp;

        for (int x : candyType) {
            mp[x]++;
        }

        int unique = mp.size();
        int n = candyType.size();

        return min(unique, n / 2);
    }
};