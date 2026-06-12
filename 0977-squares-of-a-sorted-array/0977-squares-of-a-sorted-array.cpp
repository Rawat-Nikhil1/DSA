class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        vector<int> ans(n);
        vector<int> negativeArray;
        vector<int> positiveArray;

        for (int i = 0; i < n; i++) {
            if (nums[i] < 0) {
                negativeArray.push_back(nums[i]);
            } else {
                positiveArray.push_back(nums[i]);
            }
        }

        for (int i = 0; i < negativeArray.size(); i++) {
            negativeArray[i] = negativeArray[i] * negativeArray[i];
        }

        for (int i = 0; i < positiveArray.size(); i++) {
            positiveArray[i] = positiveArray[i] * positiveArray[i];
        }

        reverse(negativeArray.begin(), negativeArray.end());

        int i = 0;
        int j = 0;

        while (i < negativeArray.size() && j < positiveArray.size()) {
            if (negativeArray[i] > positiveArray[j]) {
                ans[res] = positiveArray[j];
                j++;
                res++;
            } else {
                ans[res] = negativeArray[i];
                i++;
                res++;
            }
        }

        while (i < negativeArray.size()) {
            ans[res] = negativeArray[i];
            i++;
            res++;
        }

        while (j < positiveArray.size()) {
            ans[res] = positiveArray[j];
            j++;
            res++;
        }
        return ans;
    }
    
};