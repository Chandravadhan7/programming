class Solution {
public:
    bool search(vector<int>& arr, int x) {
       int low = 0, end = arr.size() - 1;
       while (low <= end) {
        int mid = low + (end - low) / 2;
        
        if (arr[mid] == x) {
            return true;
        }
        
        // Edge case: all three are equal, we cannot determine which side is sorted
        if (arr[low] == arr[mid] && arr[mid] == arr[end]) {
            ++low;
            --end;
        } 
        else if (arr[low] <= arr[mid]) { 
            if (arr[low] <= x && x < arr[mid]) {
                end = mid - 1;
            } else {
                low = mid + 1; 
            }
        } 
        else {
            if (arr[mid] < x && x <= arr[end]) {
                low = mid + 1;
            } else {
                end = mid - 1;
            }
        }
    }
    
    return false;
    }
};