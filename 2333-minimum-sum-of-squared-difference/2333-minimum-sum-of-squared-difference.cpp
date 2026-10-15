class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<int> diff;
        for(int i=0;i<n;i++){
            diff.push_back(abs(nums1[i]-nums2[i]));
        }
        sort(diff.rbegin(),diff.rend());
        diff.push_back(0);
        int count = k1+k2;

        for(int i=1;i<=n;i++){
            long long curr = 1LL*(diff[i-1]-diff[i])*i;
            if(curr > count){
               int q = count/i;
               int r = count%i;
               long long ans = 1LL*(diff[i-1]-q)*(diff[i-1]-q)*(i-r) + 1LL*(diff[i-1]-q-1)*(diff[i-1]-q-1)*r;

               for(int j=i;j<n;j++){
                ans += (1LL*diff[j]*diff[j]);
               }
               return ans;
            }
            count -= curr;
        }
        return 0;
        
    }
};