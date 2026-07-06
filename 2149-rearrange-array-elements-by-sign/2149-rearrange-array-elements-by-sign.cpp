class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> positive;
        vector<int> negative;

        for (int num : nums) {
            if (num > 0) {
                positive.push_back(num);
            } 
            else {
                negative.push_back(num);
            }
        }

        vector<int> ans;
        for (int i = 0; i < positive.size(); i++) {
            ans.push_back(positive[i]);
            ans.push_back(negative[i]);
        }

        return ans;
    }
};