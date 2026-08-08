class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<int> seq;
        vector<int> right_Hand_SideMatch_Length(n,0);
        int rightMatched=0;
        int i=n-1,j=m-1;
        while(i>=0){
            if(j>=0 && word1[i]==word2[j]){
                rightMatched++;
                j--;
            }
            right_Hand_SideMatch_Length[i]=rightMatched;
            i--;
        }

        int y=0,z=0;
        bool PowerChange=true;
        while(y<n && z<m){
            if(word1[y]==word2[z]){
                seq.push_back(y);
                z++;
            }
            else{
                if(y+1<n){
                    if(PowerChange==true && right_Hand_SideMatch_Length[y+1]>=m-z-1){
                        seq.push_back(y);
                        z++;
                        PowerChange=false;
                    }
                }
            }
            y++;
        }

        return z==m?seq:vector<int>();
    }
};