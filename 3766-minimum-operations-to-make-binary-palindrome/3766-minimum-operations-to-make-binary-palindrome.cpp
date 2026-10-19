class Solution {
public:
    bool isPalin(int num){
        string str = "";
        while(num > 0){
            str += (num%2) + '0';
            num = num/2;
        }
        int l = str.length();
        for(int i=0;i<l/2;i++){
            if(str[i] != str[l-i-1]){
               return false;
            }
        }
        return true;
    }
    vector<int> minOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> vec;
        for(int i=1;i<=5000;i++){
            if(isPalin(i)){
                vec.push_back(i);
            }
        }

        vector<int> ans(n);
        for(int i=0;i<n;i++){
            int idx = lower_bound(vec.begin(),vec.end(),nums[i])-vec.begin();
            if(idx<vec.size() && vec[idx] == nums[i]){
                ans[i] = 0;
            }else{
                if(idx == vec.size()){
                    ans[i] = abs(vec[idx-1]-nums[i]);
                }else if(idx == 0){
                    ans[i] = vec[idx]-nums[i];
                }else{
                    ans[i] = min(vec[idx]-nums[i],nums[i]-vec[idx-1]);
                }
            }
        }
        return ans;
    }
};