class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> res;

        if (n == 0) {
            return {newInterval};
        }

        bool inserted = false;

        for (int i = 0; i < n; i++) {

            if (!inserted && newInterval[0] <= intervals[i][0]) {
                res.push_back(newInterval);
                inserted = true;
            }

            res.push_back(intervals[i]);
        }

        if(inserted != true) {
            res.push_back(newInterval);
        }

        vector<vector<int>> ans;

        int start1 = res[0][0];
        int end1 = res[0][1];

        for (int i = 1; i < res.size(); i++) {
            int start2 = res[i][0];
            int end2 = res[i][1];

            if (end1 >= start2) {
                end1 = max(end1, end2);

            } else {
                ans.push_back({start1, end1});
                start1 = start2;
                end1 = end2;
            }
        }
        ans.push_back({start1, end1});
        return ans;
    }
};