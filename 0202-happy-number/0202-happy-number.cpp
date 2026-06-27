class Solution {
public:
    int happy(int n) {
        int sum = 0;
        while (n > 0) {
            int digit = n%10;
            n = n/10;
            sum += digit*digit; 
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow = n;
        int fast = n;

        while (fast != 1) {
            slow = happy(slow);
            fast = happy(happy(fast)); 

            if(fast==slow && slow != 1){
                return false;
            }
        }
        return true;
    }
};