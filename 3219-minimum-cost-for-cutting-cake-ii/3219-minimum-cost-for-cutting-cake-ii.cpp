class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& hc, vector<int>& vc) {
        int h=1,v=1;
        sort(hc.rbegin(),hc.rend());
        sort(vc.rbegin(),vc.rend());
        int i=0,j=0;
        long long ans = 0;

        while(i<hc.size() || j<vc.size()){
            int hor = INT_MIN;
            int ver = INT_MIN;
            if(i < hc.size()){
                hor = hc[i];
            }
            if(j < vc.size()){
                ver = vc[j];
            }

            if(hor > ver){
                i++;
                ans += 1LL*hor*v;
                h++;
            }else{
                j++;
                ans += 1LL*ver*h;
                v++;
            }
        }
        return ans;
    }
};