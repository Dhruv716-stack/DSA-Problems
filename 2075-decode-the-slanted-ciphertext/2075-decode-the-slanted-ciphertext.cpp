class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n=encodedText.size(),r=rows;
        int c=n/rows;
        int tr=0,tc=0;
        vector<vector<char>> grid(r,vector<char>(c,' '));
        for(int i=0;i<n;i++)
        {
            while(tc<c)
            {
                grid[tr][tc]=encodedText[i];
                tc++;
                i++;
            }
            i--;
            tr++;
            tc=0;
        }

        string ans="";
        for(int j=0;j<c;j++)
        {
            for(int k=0;k<r;k++)
            {
                if(j+k<c) ans+=grid[k][j+k];
            }
        }

        int ind=ans.size()-1;
        while(ind>=0 && ans[ind]==' ')
        {
            ind--;
        }
        ans=ans.substr(0,ind+1);
        return ans;

    }
};