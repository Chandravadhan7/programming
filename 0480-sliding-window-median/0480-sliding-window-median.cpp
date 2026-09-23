class Solution {
public:
    
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> mx,mn;
        vector<double> result;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(mx.empty() || nums[i]<=*prev(mx.end())){
                mx.insert(nums[i]);
            }else{
                mn.insert(nums[i]);
            }

            if(mx.size() > mn.size()+1){
                mn.insert(*prev(mx.end()));
                mx.erase(prev(mx.end()));
            }else if(mn.size() > mx.size()){
                mx.insert(*mn.begin());
                mn.erase(mn.begin());
            }
            if(i >= k-1){
                if(k%2 == 0){
                   double med = ((double)*prev(mx.end())+*mn.begin())/2;
                   result.push_back(med);
                }else{
                    result.push_back(*prev(mx.end()));
                }
                int val = nums[i-k+1];
                auto it = mx.find(val);
                if(it != mx.end()){
                    mx.erase(it);
                }else{
                    auto it = mn.find(val);
                    if(it != mn.end()){
                        mn.erase(it);
                    }
                }

                if(mx.size() > mn.size()+1){
                    mn.insert(*prev(mx.end()));
                    mx.erase(prev(mx.end()));
                }else if(mn.size() > mx.size()){
                    mx.insert(*mn.begin());
                    mn.erase(mn.begin());
                }
            }

        }
        return result;
    }
};