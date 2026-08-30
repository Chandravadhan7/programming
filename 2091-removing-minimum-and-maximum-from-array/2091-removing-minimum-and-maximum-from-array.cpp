class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        set<pair<int,int>> st;
        for(int i=0;i<n;i++){
            st.insert({nums[i],i});
        }

        int id1 = st.begin()->second;

        int id2 = prev(st.end())->second;

        if(id1 == id2){
            return 1;
        }

        int ans = INT_MAX;

        if(id1 > id2){
            ans = min({id1+1,id2+1+n-id1,n-id2});
        }else{
            ans = min({id2+1,id1+1+n-id2,n-id1});
        }
        return ans;
    }
};