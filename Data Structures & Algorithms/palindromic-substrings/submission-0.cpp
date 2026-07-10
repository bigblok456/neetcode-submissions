class Solution {
public:
    int num(string s,int l,int r){
        int res=0;
        while(l>=0 && r<s.size() && s[l]==s[r]){
            //keep expanding
            res+=1;
            l--;
            r++;
        }
        return res;
    }
    int countSubstrings(string s) {
        int res=0;
        for(int i=0;i<s.size();i++){
            res+=num(s,i,i);
            //for odd length strings
            res+=num(s,i,i+1);
            //for even length strings
            
        }
        return res;
        
    }
};
