class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList,
                                             vector<vector<int>>& secondList) {
        vector<vector<int>> res;
        if (firstList.empty() || secondList.empty()) {
            return {};
        }
        int m = firstList.size();
        int n = secondList.size();

        int i = 0;
        int j = 0;
        while (i < m and j < n) {

            int startTime1 = firstList[i][0];
            int endTime1 = firstList[i][1];
            int startTime2 = secondList[j][0];
            int endTime2 = secondList[j][1];

            if (startTime1 <= startTime2) {
                if (endTime1 >= startTime2)
                    res.push_back({max(startTime1, startTime2), min(endTime1, endTime2)});
            }
            else {
                if (endTime2 >= startTime1) {
                    res.push_back({max(startTime1, startTime2), min(endTime1, endTime2)});
                }
            }
            if (endTime2 >= endTime1) {
                i++;
            } else {
                j++;
            }
        }
        return res;
    }
};