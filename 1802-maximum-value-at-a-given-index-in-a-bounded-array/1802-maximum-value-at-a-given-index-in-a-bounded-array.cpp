class Solution {
public:
    long long remSum(int count,int available){
        if(count <= available){
            return 1LL*available*(available+1)/2 - 1LL*(available-count)*(available-count+1)/2;
        }

        return  1LL*available*(available+1)/2 + (count-available);
    }
    int maxValue(int n, int index, int maxSum) {
        int l = 1,r = maxSum;
        int ans = l;

        while(l <= r){
            int mid = l + (r-l)/2;
            long long sum = mid;
            long long left = remSum(index,mid-1);
            long long right = remSum(n-index-1,mid-1);
            
            sum += (left+right);
            
            if(sum <= maxSum){
                ans = mid;
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return ans;
    }
};