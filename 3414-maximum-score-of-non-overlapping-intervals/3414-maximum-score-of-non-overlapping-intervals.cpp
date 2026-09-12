class Solution {
public:
    vector<int> left;
    pair<long long,vector<int>> topdown(int i,int k,vector<vector<int>> &intervals,vector<vector<pair<long long,vector<int>>>> &dp){
        if(k == 0 || i == intervals.size()){
            return {0LL,{}};
        }

        if(dp[i][k].first != -1){
            return dp[i][k];
        }
        
        pair<long long,vector<int>> best;

        pair<long long,vector<int>> skip = topdown(i+1,k,intervals,dp);

        int next = upper_bound(left.begin(),left.end(),intervals[i][1])-left.begin();

        pair<long long,vector<int>> take = topdown(next,k-1,intervals,dp);
        take.first += intervals[i][2];
        take.second.push_back(intervals[i][3]);

        sort(take.second.begin(),take.second.end());

        if(take.first > skip.first){
            best = take;
        }else if(take.first < skip.first){
            best = skip;
        }else{
            if(take.second < skip.second){
                best = take;
            }else{
                best = skip;
            }
        }

        return dp[i][k] = best;

    }
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        for(int i=0;i<n;i++){
            intervals[i].push_back(i);
        }
        sort(intervals.begin(),intervals.end(),[&](const vector<int> &a,const vector<int> &b){
            return a[0] < b[0];
        });

        for(int i=0;i<n;i++){
            left.push_back(intervals[i][0]);
        }

        vector<vector<pair<long long,vector<int>>>> dp(n,vector<pair<long long,vector<int>>>(5,{-1, {}}));

        return topdown(0,4,intervals,dp).second;

    }
};