class Solution {
public:
    typedef long long ll;
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        ll sum = 0;
        sort(nums.begin(),nums.end(),[&](const int &a,const int &b){
            if(abs(a) == abs(b)){
                return a > b;
            }
            return abs(a) > abs(b);
            
        });
        for(int i=0;i<(n+1)/2;i++){
            sum += (1LL*nums[i]*nums[i]);
        }
        for(int i=(n+1)/2;i<n;i++){
            sum -= (1LL*nums[i]*nums[i]);
        }
        return sum;
    }
};