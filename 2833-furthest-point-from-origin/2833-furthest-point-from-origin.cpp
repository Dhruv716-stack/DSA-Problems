class Solution {
public:
    int furthestDistanceFromOrigin(string s) {
        int n=s.size();
        int d1=0,d2=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='L' || s[i]=='_') d1--;
            else d1++;
        }

        for(int i=0;i<n;i++)
        {
            if(s[i]=='R' || s[i]=='_') d2++;
            else d2--;
        }

        return max(abs(d1),abs(d2));
    }
};