class Solution {
public:
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       priority_queue<int,vector<int>,greater<>> minheap;
       priority_queue<int> maxheap;
       
        for(int i=0;i<nums1.size();i++){
          if(maxheap.empty() || maxheap.top() >= nums1[i]){
            maxheap.push(nums1[i]);
          }else{
            minheap.push(nums1[i]);
          }  

          if(maxheap.size() < minheap.size()){
            maxheap.push(minheap.top());
            minheap.pop();
          }

          if(maxheap.size() > minheap.size()+1){
            minheap.push(maxheap.top());
            maxheap.pop();
          }
        } 
        for(int i=0;i<nums2.size();i++){
          if(maxheap.empty() || maxheap.top() >= nums2[i]){
            maxheap.push(nums2[i]);
          }else{
            minheap.push(nums2[i]);
          }  

          if(maxheap.size() < minheap.size()){
            maxheap.push(minheap.top());
            minheap.pop();
          }

          if(maxheap.size() > minheap.size()+1){
            minheap.push(maxheap.top());
            maxheap.pop();
          }
        } 
       
        if(maxheap.size() == minheap.size()){
            return (double)(maxheap.top()+minheap.top())/2;
        }

        return maxheap.top(); 
    }
};