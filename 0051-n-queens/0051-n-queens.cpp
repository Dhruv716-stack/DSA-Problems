class Solution {
public:
    vector<vector<string>> res;

    bool isvalid(vector<string>&board, int row, int col)
    {
        int n=board.size();
        //Check Upward
        for(int i=row-1;i>=0;i--)
        {
            if(board[i][col]=='Q') return false;
        }

        //Check Upward left
        for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--)
        {
            if(board[i][j]=='Q') return false;
        }

        //Check upward right
        for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++)
        {
            if(board[i][j]=='Q') return false;
        }

        return true;
    }

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
            if(isvalid(board,row,col)==true)
            {
                board[row][col]='Q';
                solve(board,row+1);
                board[row][col]='.';
            }
        }
        return;
    }


    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        solve(board,0);
        return res;
    }
};