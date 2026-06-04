class Solution {
public:
    long long wave(int num)
    {
        string s=to_string(num);
        int n=s.size();
        long long w=0;
        for(int i=1;i<n-1;i++)
        {
            if((s[i]>s[i-1] && s[i]>s[i+1]) || (s[i]<s[i-1] &&s[i]<s[i+1])) w++;
        }
        return w;
    }
    int totalWaviness(int num1, int num2) {
        long long ans=0;
        for(int i=num1;i<=num2;i++)
        {
            long long w=wave(i);
            ans+=w;
        }
        return ans;
    }
};