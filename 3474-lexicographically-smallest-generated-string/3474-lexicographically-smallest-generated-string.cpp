class Solution {
public:
    bool issame(string &word, string &str2, int i, int m)
    {
        for(int k=i;k<i+m;k++)
        {
            if(word[k]!=str2[k-i]) return false; 
        }
        return true;
    }
    string generateString(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();
        int t=n+m-1;
        string word(t,'#');
        vector<bool> can_change(t,false);
        for(int i=0;i<n;i++)
        {
            if(str1[i]=='T')
            {
                int i_=i;
                for(int j=0;j<m;j++)
                {
                    if(word[i_]!='#' && word[i_]!=str2[j])
                    {
                        return "";
                    }
                    word[i_]=str2[j];
                    i_++;
                }
            }
        }

        for(int i=0;i<t;i++)
        {
            if(word[i]=='#')
            {
                word[i]='a';
                can_change[i]=true;
            }
        }

        for(int i=0;i<n;i++)
        {
            if(str1[i]=='F')
            {
                if(issame(word,str2,i,m))
                {
                    bool changed=false;
                    for(int k=i+m-1;k>=i;k--)
                    {
                        if(can_change[k]==true)
                        {
                            word[k]='b';
                            changed=true;
                            break;
                        }
                    }
                    if(changed==false) return "";
                }
            }
        }

        return word;
    }
};