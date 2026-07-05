class Solution {
public:
    vector<vector<pair<int,int>>> dp;
    const int M=1e9+7;
    bool isValid(int i, int j, vector<string>&grid){
        int n=grid.size();
        return (i>=0 && i<n && j>=0 && j<n && grid[i][j]!='X');
    }

    int getnum(char ch){
        return ch=='S'?0:ch-'0';
    }
    pair<int,int> solve(int i, int j, vector<string>&grid){
        int n=grid.size();
        if(grid[i][j]=='E') return {0,1};
        if(grid[i][j]=='X') return {0,0};

        if(dp[i][j].first !=-1 && dp[i][j].second!=-1) return dp[i][j];

        int us=0,up=0;
        int ls=0,lp=0;
        int diags=0,diagp=0;
        char ch=grid[i][j];
        if(isValid(i-1,j,grid)){
            auto [score,paths]=solve(i-1,j,grid);
            us=score;
            up=paths;
            if(up>0){
                us+=getnum(ch);
            }
        }

            if(isValid(i,j-1,grid)){
            auto [score,paths]=solve(i,j-1,grid);
            ls=score;
            lp=paths;
            if(lp>0){
                ls+=getnum(ch);
            }
        }

            if(isValid(i-1,j-1,grid)){
            auto [score,paths]=solve(i-1,j-1,grid);
            diags=score;
            diagp=paths;
            if(diagp>0){
                diags+=getnum(ch);
            }
        }

        int bs=0,bp=0;
        if(us==ls && ls==diags){
            bs=us;
            bp=up+lp+diagp;
        }

        else if(us==ls){
            bs=us;
            bp=up+lp;
            if(diags>bs || (diags==bs && diagp>bp)){
                bs=diags;
                bp=diagp;
            }
        }

        else if(ls==diags){
            bs=ls;
            bp=lp+diagp;
            if(us>bs ||(us==bs && up>bp)){
                bs=us;
                bp=up;
            }
        }

        else if(us==diags){
            bs=us;
            bp=up+diagp;
            if(ls>bs || (ls==bs && lp>bp)){
                bs=ls;
                bp=lp;
            }
        }

        else{
            bs=us;
            bp=up;

            if(ls>bs || (ls==bs && lp>bp)){
                bs=ls;
                bp=lp;
            }

            else if(diags>bs || (diags==bs && diagp>bp)){
                bs=diags;
                bp=diagp;
            }
        }

        return dp[i][j]={bs,(bp%M)};
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n=board.size();
        dp.assign(n,vector<pair<int,int>>(n,{-1,-1}));

        pair<int,int> p=solve(n-1,n-1,board);
        return {p.first,p.second};
    }
};