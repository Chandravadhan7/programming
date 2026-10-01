class Solution {
    bool myCmp(char a,char b){
        if(a=='{' && b=='}'){
            return true;
        }
        else if(a=='[' && b==']'){
            return true;
        }
        if(a=='(' && b==')'){
            return true;
        }
        else{
            return false;
        }
        
    }
public:
    bool isValid(string s) {
      stack<char> s1;
      for(int i=0;i<s.length();i++){
        if(s[i]=='{' || s[i]=='[' || s[i]=='('){
            s1.push(s[i]);
        }
        else{
            if(s1.empty()){
                return false;
            }
          else if(!myCmp(s1.top(),s[i])){
            return false;
          }
          else{
          s1.pop();
          }
        }
      }  
        return s1.empty();;
      
    }
};