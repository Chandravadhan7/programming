class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        int e = min(need1,need2);
        long long ans = 0;
        ans = e*min(1LL*costBoth,1LL*(cost1+cost2));
        

        ans += (need1-e)*min(1LL*cost1,1LL*costBoth);
        ans += (need2-e)*min(1LL*cost2,1LL*costBoth);

        return ans;
    }
};