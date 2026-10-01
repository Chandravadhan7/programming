class Solution {
public:
    bool dfs(int i,int j,int id,vector<vector<int>> &vis,string &word,vector<vector<char>> &board){
        int m = board.size();
        int n = board[0].size();

        if(id == word.size()) return true;
        
        if(i < 0 || i >= m || j < 0 || j >= n || word[id] != board[i][j] || vis[i][j]) return false;
        
        int dx[4] = {1,0,-1,0};
        int dy[4] = {0,1,0,-1};
        vis[i][j] = 1;

        for(int k=0;k<4;k++){
            int nx = i + dx[k];
            int ny = j + dy[k];

            if(dfs(nx,ny,id+1,vis,word,board)){
                return true;
            }
        }
        
        vis[i][j] = 0;
        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(word[0] == board[i][j]){
                    vector<vector<int>> vis(m,vector<int>(n,0));
                    if(dfs(i,j,0,vis,word,board)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};