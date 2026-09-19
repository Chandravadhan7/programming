class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> ans(n,-1);
        vector<pair<int,int>> arr;

        for(int i=0;i<n;i++){
            arr.push_back({nums2[i],i});
        }
        sort(arr.begin(),arr.end());
        sort(nums1.begin(),nums1.end());

        for(int i=0;i<n;i++){
            auto [val,id] = arr[i];

            int it = upper_bound(nums1.begin(),nums1.end(),val)-nums1.begin();
            if(it < n){
                ans[id] = nums1[it];
                nums1[it] = INT_MIN;
            }
        }
        vector<int> temp;
        for(int i=0;i<n;i++){
            if(nums1[i] != INT_MIN){
                temp.push_back(nums1[i]);
            }
        }
        int j = 0;
        for(int i=0;i<n;i++){
            if(ans[i] == -1){
                ans[i] = temp[j++];
            }
        }
        return ans;
    }
};