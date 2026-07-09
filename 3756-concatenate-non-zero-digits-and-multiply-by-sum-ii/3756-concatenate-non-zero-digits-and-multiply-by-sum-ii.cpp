class Solution {
public:
    typedef long long ll;
    const int M=1e9+7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int m=s.size();
        vector<int> ans;
        vector<ll> ds(m,0);
        ds[0]=1LL*(s[0]-'0');
        vector<ll> numbers_up_to(m,0);
        numbers_up_to[0]=1LL*(s[0]-'0');
        vector<ll> non_zero_digits(m,0);
        if(s[0]!='0') non_zero_digits[0]=1;
        else if(s[0]=='0') non_zero_digits[0]=0;
        vector<ll> pow10(m+1,0);
        pow10[0]=1;
        
        for(int i=1;i<m;i++){
            pow10[i]=(pow10[i-1]*10)%M;
            if(s[i]=='0'){
                ds[i]=ds[i-1];
                numbers_up_to[i]=numbers_up_to[i-1];
                non_zero_digits[i]=non_zero_digits[i-1];
            }
            else{
                ds[i]=ds[i-1]+1LL*(s[i]-'0');
                numbers_up_to[i]=(numbers_up_to[i-1]*10+1LL*(s[i]-'0'))%M;
                non_zero_digits[i]=non_zero_digits[i-1]+1;
            }
        }
        pow10[m]=(pow10[m-1]*10)%M;

        cout << numbers_up_to[m-1] << "\n";
        cout << ds[m-1] << "\n";
        for(auto &it:queries){
            int l=it[0];
            int r=it[1];
            ll sum=0,x=0;
            if(l==0){
                sum=ds[r];
                x=numbers_up_to[r];
            }
            else{
                sum=ds[r]-ds[l-1];
                x=(numbers_up_to[r]-((((numbers_up_to[l-1])*pow10[non_zero_digits[r]-non_zero_digits[l-1]]))%M)+M)%M;
            }
            ans.push_back((int)((x*sum)%M));
        }
        return ans;
    }
};