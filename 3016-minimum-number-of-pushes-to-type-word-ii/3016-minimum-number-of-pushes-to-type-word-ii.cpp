class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++){
            mp[word[i]]++;
        }

        priority_queue<pair<int,char>> pq;

        for(auto x : mp){
            pq.push({x.second,x.first});
        }

        int ans = 0;
        int counter = 1;
        int count = 0;
        while(!pq.empty()){
            auto [x,ch] = pq.top();
            pq.pop();

            ans += counter*x;
            count++;
            if(count == 8 || count == 16 || count == 24){
                counter++;
            }
        }
        return ans;
    }
};