class Solution {
public:
    bool canDistribute(vector<int> candies, long long k, int guess) {
        long long distribute = 0;
        for (int i = 0; i < candies.size(); i++) {
            distribute = distribute + candies[i]/guess;
        }
        if(distribute>=k){
            return true;
        }
        else{
            return false;
        }
    }

    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        
        long long low = 1;
        long long high = *max_element(candies.begin(),candies.end());
        long long guess = low+(high-low)/2;
        long long res = 0;

        while(low<=high){
            if(canDistribute(candies,k,guess)){
                res = guess;
                low = guess+1;
            }
            else{
                high = guess-1;
            }
            guess = low+(high-low)/2;

        } 
        return res;
    }
};