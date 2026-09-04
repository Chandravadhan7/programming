class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        vector<pair<int,int>> temp;
        for(int i=0;i<n;i++){
            temp.push_back({aliceValues[i],bobValues[i]});
        }

        sort(temp.begin(),temp.end(),[](const pair<int,int> &a,const pair<int,int> &b){
            return a.first+a.second > b.first+b.second;
        });
        
        int s1 = 0,s2 = 0;

        for(int i=0;i<n;i++){
            if(i%2 == 0){
                s1 += temp[i].first;
            }else{
                s2 += temp[i].second;
            }
        }

        if(s1 > s2){
            return 1;
        }else if(s1 < s2){
            return -1;
        }

        return 0;
    }
};