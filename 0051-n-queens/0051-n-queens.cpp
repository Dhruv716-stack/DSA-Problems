class Solution {
public:
    vector<vector<string>> res;
    unordered_set<int> columns,diag,antidiag;
    void solve(vector<string>&board,int row)
    {
        int n=board.size();
        if(row>=n)
        {
            res.push_back(board);
            return;
        }

        for(int col=0;col<n;col++)
        {
            int diag_const=row+col;
            int antidiag_const=row-col;
            if(columns.find(col)!=columns.end() || diag.find(diag_const)!=diag.end() || antidiag.find(antidiag_const)!=antidiag.end()) continue;
            columns.insert(col);
            diag.insert(diag_const);
            antidiag.insert(antidiag_const);

            board[row][col]='Q';
            solve(board,row+1);

            columns.erase(col);
            diag.erase(diag_const);
            antidiag.erase(antidiag_const);
            board[row][col]='.';
        }
        return;
    }


    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        solve(board,0);
        return res;
    }
};