class Solution {
public:
    int numSteps(string s) {
        int n=s.size();
        int carry=0,op=0;
        for(int i=n-1;i>=1;i--)
        {
            if(((s[i]-'0')+carry)%2==1)
            {
                op+=2;
                carry=1;
            }
            else op++;
        }
        return op+carry;
    }
};