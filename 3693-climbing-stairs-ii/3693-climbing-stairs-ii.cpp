class Solution {
public:
    int climbStairs(int n, vector<int>& cost) {
        vector<int> ans(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
        pq.push({0,0});

        while(!pq.empty()){
            auto [c,u] = pq.top();
            pq.pop();

            if(ans[u] < c) continue;
            if(u+1 <= n){
                if(ans[u+1] > c + cost[u] + 1){
                    ans[u+1] = c + cost[u] + 1;
                    pq.push({ans[u+1],u+1});
                }
            }
            if(u+2 <= n){
                if(ans[u+2] > c + cost[u+1] + 4){
                    ans[u+2] = c + cost[u+1] + 4;
                    pq.push({ans[u+2],u+2});
                }
            }
            if(u+3 <= n){
                if(ans[u+3] > c + cost[u+2] + 9){
                    ans[u+3] = c + cost[u+2] + 9;
                    pq.push({ans[u+3],u+3});
                }
            }
        }
        return ans[n];
    }
};