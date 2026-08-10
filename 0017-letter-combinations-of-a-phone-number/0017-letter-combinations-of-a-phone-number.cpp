class Solution {
public:
    void combinations(string& digits, int n, int idx, string& temp,
                      vector<string>& res) {
        unordered_map<char, string> mpp = {
            {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

        if (idx == n) {
            res.push_back(temp);
            return;
        }

        string choice = mpp[digits[idx]];
        for (int i = 0; i < choice.size(); i++) {
            temp.push_back(choice[i]);
            combinations(digits, n, idx + 1, temp, res);
            temp.pop_back();
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        int idx = 0;
        string temp = "";
        vector<string> res;

        combinations(digits,n,idx,temp,res);
        return res;
    }
};