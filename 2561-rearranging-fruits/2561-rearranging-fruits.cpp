class Solution {
public:
    long long minCost(vector<int>& b1, vector<int>& b2) {
        int n = b1.size();
        unordered_map<int,int> freq,f1,f2;
        int miin = INT_MAX;
        for(int i=0;i<n;i++){
            miin = min({miin,b1[i],b2[i]});
            f1[b1[i]]++;
            f2[b2[i]]++;
            freq[b1[i]]++;
            freq[b2[i]]++;
        }

        for(auto x : freq){
            if(x.second%2){
                return -1;
            }
        }
        vector<int> temp;
        for(auto x:freq){
            int req = x.second/2;
            if(f1[x.first] > req){
                for(int i=0;i<f1[x.first]-req;i++){
                    temp.push_back(x.first);
                }
            }else if(f2[x.first] > req){
                for(int i=0;i<f2[x.first]-req;i++){
                    temp.push_back(x.first);
                }
            }
        }
        sort(temp.begin(),temp.end());
        long long ans = 0;
        for(int i=0;i<temp.size()/2;i++){
           ans += min(2LL*miin,(long long)temp[i]);
        }

        return ans;

        
    }
};