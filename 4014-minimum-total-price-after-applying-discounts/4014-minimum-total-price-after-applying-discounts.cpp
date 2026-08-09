class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.rbegin(),prices.rend());
        sort(discounts.rbegin(),discounts.rend());

        int i=0,j=0;

        double ans = 0.0;

        while(i < prices.size() && j < discounts.size()){
            ans += 1.0 * prices[i] * ((double)(100-discounts[j])/100);
            i++;
            j++;
        }

        while(i < prices.size()){
            ans += (double)prices[i];
            i++;
        }

        return ans;
    }
};