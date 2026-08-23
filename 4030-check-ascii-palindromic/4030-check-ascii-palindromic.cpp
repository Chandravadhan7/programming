class Solution {
public:
    string tobinary(int num){
        string str = "";
        while(num > 0){
            if(num%2 == 0){
                str += "0";
            }else{
                str += "1";
            }
            num = num/2;
        }
        reverse(str.begin(),str.end());
        while(str.length() < 8){
            str = "0" + str;
        }
        return str;
    }
    bool isPalindromic(string s) {
        int n = s.length();
        string ans = "";

        int i = 0;

        while(i < n){
            string temp = tobinary((int)s[i]);
            ans += temp;
            i++;
        }

        i = 0;
        int m = ans.size();
        while(i < m/2){
            if(ans[i] != ans[m-i-1]){
                return false;
            }
            i++;
        }

        return true;

    }
};