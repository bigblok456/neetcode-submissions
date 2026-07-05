class Solution {
public:
    vector<vector<string>> res;
    unordered_set <int> col;
    unordered_set <int> posDiag;
    unordered_set <int> negDiag;


    void backtrack(int r,int n,vector <string> & board){
        if(r ==n){
            res.push_back(board);
            return;
        }
        //this is our base case
        //we cant put 2 queens in the same row or colum or along the same + diag
        //or negDiag
        for(int c=0;c<n;c++){
            if(col.count(c) || posDiag.count(r+c) || negDiag.count(r-c)){
                continue;
            }
            col.insert(c);
            posDiag.insert(r+c);
            negDiag.insert(r-c);
            board[r][c]='Q';

            //now call backtrack
            //after placing the Q call backtrack
            //to place the queen in the next row
            backtrack(r+1,n,board);


            col.erase(c);
            posDiag.erase(r+c);
            negDiag.erase(r-c);
            board[r][c]='.';
        }

    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        //here if n=4
        //then each element would be ....
        //all the rows are filled by . here
        backtrack(0,n,board);
        return res;
    }
};
