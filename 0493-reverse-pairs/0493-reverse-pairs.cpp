class Solution {
public:
    int merge(int low,int mid,int high,vector<int> &nums){
        int j = mid + 1;
        int ans = 0;

        for(int i=low;i<=mid;i++){
            while(j <= high && (long long)nums[i] > 2LL*nums[j]){
                j++;
            }
            ans += (j-mid-1);
        }
        int left = low,right = mid + 1;
        vector<int> temp(high-low+1);
        int k = 0;

        while(left <= mid && right <= high){
            if(nums[left] <= nums[right]){
                temp[k++] = nums[left++];
            }else{
                temp[k++] = nums[right++];
            }
        }
        while(left <= mid){
            temp[k++] = nums[left++];
        }

        while(right <= high){
            temp[k++] = nums[right++];
        }

        k = 0;

        for(int i=low;i<=high;i++){
           nums[i] = temp[k++];
        }
        return ans;
    }
    int mergesort(int low,int high,vector<int> &nums){
        int count = 0;
        if(low >= high) return count;

        int mid = (high+low)/2;

        count += mergesort(low,mid,nums);
        count += mergesort(mid+1,high,nums);
        count += merge(low,mid,high,nums);

        return count;
    }
    int reversePairs(vector<int>& nums) {
        return mergesort(0,nums.size()-1,nums);
    }
};