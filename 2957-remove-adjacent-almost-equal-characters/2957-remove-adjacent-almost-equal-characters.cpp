class Solution {
public:
    int removeAlmostEqualCharacters(string word) {
        int n = word.length();
        int count = 0;
        for(int i=0;i<n-1;i++){
            if(abs(word[i]-word[i+1]) <= 1){
                count++;
                i++;
            }
        }
        return count;
    }
};