class Solution {
public:
    vector<int> primefactors(int num){
        vector<int> primes;
        for(int i=2;i*i<=num;i++){
            if(num%i == 0){
               primes.push_back(i);
            }
            while(num%i == 0){
                num = num/i;
            }
        }

        if(num > 1){
            primes.push_back(num);
        }
        return primes;
    }
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;

        int ans = 0;
        int l = 0;

        for(int i=0;i<n;i++){
            vector<int> temp = primefactors(nums[i]);
            for(auto x : temp){
                mp[x]++;
            }
            while(mp.size() > k && l < n){
                vector<int> temp = primefactors(nums[l]);
                for(auto x : temp){
                    mp[x]--;
                    if(mp[x] == 0){
                        mp.erase(x);
                    }
                }
                l++;
            }

            ans = max(ans,(i-l+1));
        }
        return ans;
    }
};