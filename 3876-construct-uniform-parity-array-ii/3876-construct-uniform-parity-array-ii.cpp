class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int even = 0,odd = 0;
        for(int i=0;i<n;i++){
            if(nums1[i]%2 == 1) odd++;
            else even++;
        }

        if(even == n || odd == n) return true;
        int miinodd = INT_MAX;
        for(int i=0;i<n;i++){
            if(nums1[i]%2 == 1){
                miinodd = min(miinodd,nums1[i]);
            }
        }

        for(int i=0;i<n;i++){
            if(nums1[i]%2 == 0){
                if(nums1[i] < miinodd){
                    return false;
                }
            }
        }

        return true;
    }
};