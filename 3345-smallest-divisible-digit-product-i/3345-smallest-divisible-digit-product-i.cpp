class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int i=n;;i++){
            int num = i;
            int p = 1;
            while(num > 0){
                int rem = num%10;
                p = p * rem;
                num = num/10;
            }
            if(p%t == 0){
                return i;
            }
        }

        return 0;
        
    }
};