class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> ans(n,-1);
        for( int i = 2*n-1; i>=0 ; i--){
            int idx = i%n;
            while(st.size()>0 && nums[st.top()]<=nums[idx]){
                st.pop();
            }
            if(st.size()==0){
                ans[idx]=-1;
            }
            else{
                ans[idx]= nums[st.top()];
            }
            st.push(idx);
        }
        return ans;
        
    }
};