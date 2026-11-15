class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int mod = 1e9+7;
        int odd = 0,even = 1;
        int sum = 0;
        int ans = 0;

        for(int i=0;i<n;i++){
           sum += arr[i];
           if(sum%2 != 0){
              ans = (ans+even)%mod;
              odd++;
           }else{
              if(odd != 0){
                ans = (ans+odd)%mod;
              }
              even++;
           }
        }
        return ans;
    }
};