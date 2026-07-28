class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        int mid = (n-1)/2;
        if(n%2 == 0){
          sort(s.begin(),s.begin()+mid+1);
          sort(s.begin()+mid+1,s.end(),greater<char>());
        }else{
          sort(s.begin(),s.begin()+mid);
          sort(s.begin()+mid+1,s.end(),greater<char>());  
        }

        return s;
    }
};