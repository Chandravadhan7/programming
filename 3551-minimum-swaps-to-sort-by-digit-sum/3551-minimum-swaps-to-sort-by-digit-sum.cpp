class Solution {
public:
    int digsum(int num){
        int sum = 0;
        while(num > 0){
            int d = num%10;
            sum += d;
            num = num/10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]] = i;
        }
        vector<int> temp = nums;
        sort(temp.begin(),temp.end(),[&](const int &a,const int &b){
            if(digsum(a) == digsum(b)){
                return a < b;
            }
            return digsum(a) < digsum(b);
        });
        
        int count = 0;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(vis[i] && temp[i] == nums[i]){
              continue;
            }
            int j=i;
            int cycle = 0;
            while(!vis[j]){
                cycle++;
                vis[j] = 1;
                j = mp[temp[j]];
            }

            if(cycle > 1){
                count += cycle-1;
            }
        }
        return count;
    }
};