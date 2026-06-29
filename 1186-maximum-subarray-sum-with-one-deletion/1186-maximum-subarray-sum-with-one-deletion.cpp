class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        int res = arr[0];
        int power = 0;
        int noPower = arr[0];

        for(int i=1;i<n;i++){
            int v1 = arr[i];
            int v2 = noPower + arr[i];
            int v3 = power + arr[i];
            int v4 = noPower;

            res = max(res, max(max(v1, v2), max(v3, v4)));

            noPower = max(v1,v2);
            power = max(v3,v4);
        }
        return res;
    }
};