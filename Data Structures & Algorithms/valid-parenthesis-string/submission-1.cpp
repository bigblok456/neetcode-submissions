class Solution {
public:
    bool checkValidString(string s) {
        stack<int> left;
        stack<int> star;
        if(s.size()==1 && s[0]=='*') return true;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                left.push(i);
            }
            else if(s[i]=='*'){
                star.push(i);
            }
            else{
                if(!left.empty()){
                    left.pop();
                }
                else if(!star.empty()){
                    star.pop();
                }
                else{
                    return false;
                }
            }
        }
        while(!left.empty() && !star.empty()){
            //here the * can act as an openning parentheses only when i have an index greater than left.top
            //as close comes after open
            if(left.top()>star.top()){
                return false;
            }
            left.pop();
            star.pop();
        }
        if(!left.empty()){
            return false;
        }
        return true;
        
    }
};
