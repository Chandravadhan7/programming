class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        int l=1,r=*max_element(candies.begin(),candies.end());

        int ans=0;

        while(l <= r){
            int mid = l + (r-l)/2;

            long long count = 0;

            for(int i=0;i<n;i++){
                count += (long long)(candies[i]/mid);
            }

            if(count >= k){
                ans = mid;
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }

        return ans;
    }
};