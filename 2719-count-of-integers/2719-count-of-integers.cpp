class Solution {
public:
    int mod = 1e9+7;
    int dp[23][2][2][200];
    int mn,mx;
    int countNum(int pos,bool tight,bool leadingZero,int sum,string &s){
        if(sum > mx){
            return 0;
        }
        if(pos == s.length()){
            if(sum >= mn && sum <= mx){
              return 1;
            }else{
                return 0;
            }
        }

        if(dp[pos][tight][leadingZero][sum] != -1){
            return dp[pos][tight][leadingZero][sum];
        }

        int count = 0;

        int limit = tight?s[pos] - '0':9;

        for(int i=0;i<=limit;i++){
            if(i == 0 && leadingZero){
                count = (count + countNum(pos+1,tight && i == limit,1,sum,s))%mod;
            }else{
                count = (count + countNum(pos+1,tight && i == limit,0,sum+i,s))%mod;
            }
        }
        return dp[pos][tight][leadingZero][sum] = count;
    }

    string subtractOne(string s){
        int n = s.length();

        int i = n-1;

        while(i >= 0 && s[i] == '0'){
            s[i] = '9';
            i--;
        }

        if(i >= 0){
            s[i]--;
        }
        i=0;
        while(i < n && s[i] == '0'){
            i++;
        }
        return s.substr(i);
    }
    int solve(string s){
        memset(dp,-1,sizeof(dp));
        return countNum(0,true,true,0,s);
    }
    int count(string num1, string num2, int min_sum, int max_sum) {
        mn = min_sum;
        mx = max_sum;
        long long right = solve(num2);

        string s = subtractOne(num1);

        long long left = solve(s);

        long long ans = right - left;
        ans = (ans + mod) % mod;

        return ans;
    }
};