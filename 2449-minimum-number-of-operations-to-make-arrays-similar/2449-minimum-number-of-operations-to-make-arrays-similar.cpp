class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        vector<int> e1,o1,e2,o2;
        for(auto x : nums){
            if(x%2){
                o1.push_back(x);
            }else{
                e1.push_back(x);
            }
        }

        for(auto x : target){
            if(x%2){
                o2.push_back(x);
            }else{
                e2.push_back(x);
            }
        }

        sort(o1.begin(),o1.end());
        sort(o2.begin(),o2.end());
        sort(e1.begin(),e1.end());
        sort(e2.begin(),e2.end());

        long long ans = 0;
        for(int i=0;i<e1.size();i++){
            ans += abs(e1[i]-e2[i])/2;
        }
        for(int i=0;i<o1.size();i++){
            ans += abs(o1[i]-o2[i])/2;
        }
        return ans/2;
    }
};