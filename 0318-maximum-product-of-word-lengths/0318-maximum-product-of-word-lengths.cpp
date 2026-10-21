class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<string> bin(n,string(26,'0'));
        for(int i=0;i<n;i++){
            for(auto x : words[i]){
                int id = x - 'a';
                bin[i][id] = '1';
            }
        }
        
        int mx = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int a = stoi(bin[i],nullptr,2);
                int b = stoi(bin[j],nullptr,2);

                if(!(a & b)){
                    mx = max(mx,(int)words[i].length() * (int)words[j].length());
                }
            }
        }
        return mx;
    }
};