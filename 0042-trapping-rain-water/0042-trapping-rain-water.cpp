class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l=0,r=n-1;
        int mxl=0,mxr=0;

        int ans = 0;

        while(l <= r){
            if(height[l] <= height[r]){
                mxl = max(mxl,height[l]);
                
                ans += mxl-height[l];
                l++;
            }else{
                mxr = max(mxr,height[r]);

                ans += mxr-height[r];
                r--;
            }
        }
        return ans;
    }
};