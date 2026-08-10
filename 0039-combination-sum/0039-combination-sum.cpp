class Solution {
public:
    void fun(vector<int>&candidates,int n,int target,int sum,int idx,vector<int>&temp,vector<vector<int>>&res){
        if(idx == n){
            if(sum==target){
                res.push_back(temp);
            }
            return;
        }
        fun(candidates,n,target,sum,idx+1,temp,res);

        if(sum+candidates[idx]<=target){
            temp.push_back(candidates[idx]);
            sum += candidates[idx];
            fun(candidates,n,target,sum,idx,temp,res);
            temp.pop_back();
            sum -= candidates[idx];
        }
        return;

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<int> temp;
        vector<vector<int>>res;
        int sum = 0;
        int idx = 0;

        fun(candidates,n,target,sum,idx,temp,res);
        return res;
    }
};