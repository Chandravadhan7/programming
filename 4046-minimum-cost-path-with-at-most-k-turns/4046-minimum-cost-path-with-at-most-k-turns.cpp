class Solution {
public:
    int cost[75][75][76][5];
    int minCost(vector<vector<int>>& grid, int k) {
        int  m = grid.size();
        int n = grid[0].size();

        if(m == 1){
            return accumulate(grid[0].begin(),grid[0].end(),0);
        }

            
        // memset(cost,INT_MAX,sizeof(cost));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                for(int i1=0;i1<=k;i1++){
                    for(int j1=0;j1<=4;j1++){
                    cost[i][j][i1][j1]=INT_MAX;
                    }
                }
            }
        }
        
        priority_queue<vector<int>,vector<vector<int>>,greater<>> pq;
        cost[0][0][0][0] = grid[0][0];

        pq.push({grid[0][0],0,0,0,0});
        int dx[4] = {1,0,-1,0};
        int dy[4] = {0,1,0,-1};

        while(!pq.empty()){
            auto x = pq.top();
            pq.pop();

            int c = x[0],u=x[1],v = x[2],turn = x[3],dir=x[4];

            if(cost[u][v][turn][dir] < c) continue;

            for(int i=0;i<4;i++){
                int nx = u + dx[i];
                int ny = v + dy[i];

                if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;

                    if(dir == 0){
                        if(cost[nx][ny][turn][i+1] > c + grid[nx][ny]){
                            cost[nx][ny][turn][i+1] = c + grid[nx][ny];
                            pq.push({cost[nx][ny][turn][i+1],nx,ny,turn,i+1});
                        }
                        continue;
                    }
                    if(i+1 != dir){
                        if(turn>=k) continue;
                        if(cost[nx][ny][turn+1][i+1] > c + grid[nx][ny]){
                            cost[nx][ny][turn+1][i+1] = c + grid[nx][ny];
                            pq.push({cost[nx][ny][turn+1][i+1],nx,ny,turn+1,i+1});
                        }
                    }else{
                        if(cost[nx][ny][turn][i+1] > c + grid[nx][ny]){
                            cost[nx][ny][turn][i+1] = c + grid[nx][ny];
                            pq.push({cost[nx][ny][turn][i+1],nx,ny,turn,i+1});
                        }
                    }
                
            }
        }

        int ans = INT_MAX;
    //   for(int i1=0;i1<m;i1++){
    //     for(int j1=0;j1<n;j1++){
    //         for(int i=0;i<=k;i++){
    //         //    ans = min(ans,cost[m-1][n-1][i]);
    //            cout<<cost[i1][j1][i]<<" ";
    //          }
    //          cout<<endl;
    //      }
    //    }
    for(int i=0;i<=k;i++){
        for(int j=1;j<=4;j++){
            ans = min(ans,cost[m-1][n-1][i][j]);
        }
    }
        return (ans==INT_MAX)?-1:ans;
    }
};