class Solution {
public:
    bool checkDivisibility(int n) {
        long long sum = 0;
        long long pro = 1;
        int temp = n;
        while(temp > 0){
            int rem = temp%10;
            sum += (long long)rem;
            pro *= 1LL*rem;
            temp = temp/10;
        }
        if(n%(sum+pro) == 0){
            return true;
        }
        return false;
    }
};