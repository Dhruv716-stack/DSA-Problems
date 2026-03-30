class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        bool flag=true;
        for(int i=0;i<4;i++)
        {
            if(s1[i]==s2[(i+2)%4] || s1[i]==s2[i]) continue;
            else
            {
                flag=false;
                break;
            }
        }
        return flag;
    }
};