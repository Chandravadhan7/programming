class Solution {
public:
    int findColoredRoot(vector<vector<int>>& edges, string colors) {
        int n = colors.length();
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0),outdegree(n,0);

        for(auto e : edges){
            int u = e[0];
            int v = e[1];

            if((colors[u] == 'R' && colors[v] == 'B') || (colors[u] == 'B' && colors[v] == 'W') || (colors[u] == 'W' && colors[v] == 'R')){
                indegree[v]++;
                outdegree[u]++;
            }else if((colors[v] == 'R' && colors[u] == 'B') || (colors[v] == 'B' && colors[u] == 'W') || (colors[v] == 'W' && colors[u] == 'R')){
                indegree[u]++;
                outdegree[v]++;
            }else{
                return -1;
            }
        }
        
        
        int ans = -1;
        for(int i=0;i<n;i++){
            if(outdegree[i] > 2) return -1;

            if(indegree[i] > 1){
                return -1;
            }

            if(indegree[i] == 0){
                ans = i;
            }
        }
        return ans;
    }
};