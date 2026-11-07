class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n=servers.size();
        int m=tasks.size();

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
        for(int i=0;i<n;i++){
            pq.push({servers[i],i});
        }

        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>> q;
        vector<int> ans(m);
        long long t = 0;

        for(int i=0;i<m;i++){
           t = max(t, (long long)i);

            while(!q.empty() && q.top().first <= t) {
                pq.push({servers[q.top().second], q.top().second});
                q.pop();
            }

            if(!pq.empty()) {
                ans[i] = pq.top().second;
                q.push({t + tasks[i], pq.top().second});
                pq.pop();
            }else{
                long long temp = q.top().first;
                while(!q.empty() && q.top().first == temp){
                pq.push({servers[q.top().second],q.top().second});
                q.pop();
                }
                ans[i] = pq.top().second;
                q.push({temp+tasks[i],pq.top().second});
                pq.pop();
                t = temp;
           }
        }
        return ans;
    }
};