class TrieNode{
    public:
        TrieNode *children[26];
        bool isEnd;
        TrieNode(){
            isEnd=false;
            for(int i=0;i<26;i++){
                children[i]=NULL;
            }
        }
};
class PrefixTree {
public:
    TrieNode * root;
    PrefixTree() {
        root =new TrieNode();
        //this is where the initialization takes place 
    }
    
    void insert(string word) {
        TrieNode * curr=root;
        for(char ch: word){
            int index =ch-'a';
            if(curr->children[index]==NULL){
                curr->children[index]=new TrieNode();
            }
            curr=curr->children[index];
        }
        curr->isEnd=true;
        
    }
    
    bool search(string word) {
        TrieNode * curr=root;
        for(char ch: word){
            int index=ch-'a';
            if(curr->children[index]==NULL){
                return false;
            }
            curr=curr->children[index];
        }
        return curr->isEnd;
        
    }
    
    bool startsWith(string prefix) {
        //for checking the prefix we dont need to check
        //the isend as ba is the prefix for bat
        TrieNode * curr=root;
        for(char ch: prefix){
            int index=ch-'a';
            if(curr->children[index]==NULL){
                return false;
            }
            curr=curr->children[index];
        }
        return true;

        
    }
};
