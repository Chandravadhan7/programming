class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string str = "";
        int curr = sum;
        for(int i=0;i<num;i++){
            if(curr >= 9){
                str += "9";
                curr -= 9;
            }else if(curr == 0){
                str += "0";
            }else{
                str += to_string(curr);
                curr = 0;
            }
        }
        if(curr > 0){
            return "";
        }
        return str;
    }
};