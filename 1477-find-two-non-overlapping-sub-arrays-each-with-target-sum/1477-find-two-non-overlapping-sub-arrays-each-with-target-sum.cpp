class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> prefix(n);
        vector<int> suffix(n);
        int miin = INT_MAX;
        unordered_map<int,int> mp;
        mp[0] = -1;
        int sum = 0;
        for(int i=0;i<n;i++){
          sum += arr[i];
          if(mp.count(sum-target)){
            miin = min(miin,i-mp[sum-target]);
          }
          mp[sum] = i;
          prefix[i] = miin;
        }
        mp.clear();
        mp[0] = n;
         sum = 0;
        miin = INT_MAX;
        for(int i=n-1;i>=0;i--){
            sum += arr[i];
            if(mp.count(sum-target)){
                miin = min(miin,mp[sum-target]-i);
            }
            mp[sum] = i;
            suffix[i] = miin;
        }
        int ans = INT_MAX;
        for(int i=0;i<n-1;i++){
            if(prefix[i] == INT_MAX || suffix[i+1] == INT_MAX){
                continue;
            }
            ans = min(prefix[i]+suffix[i+1],ans);
        }

        return ans==INT_MAX?-1:ans;
    }
};