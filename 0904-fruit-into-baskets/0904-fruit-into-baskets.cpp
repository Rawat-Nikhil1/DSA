class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int,int>freq;
        int low = 0;
        int res = -1;
        int n = fruits.size();

        for( int high=0 ; high<n ; high++){
            freq[fruits[high]]++;

            while(freq.size() > 2){
                freq[fruits[low]]--;
                 
               if(freq[fruits[low]]==0){
                   freq.erase(fruits[low]);
               }
               low++; 
            }
            if(freq.size() < 2 || freq.size()==2){
                int len = high-low+1;
                res = max(len,res);
            }
        }
        return res;
    }
};