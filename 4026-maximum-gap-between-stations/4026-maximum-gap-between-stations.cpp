class Solution {
public:
    int maximumGap(string sk, string st) {
        int n=sk.size();
        int m=st.size();
        map<int,int> mp1,mp2;
        if(n==1) return 0;
        int ind1=-1, ind2=-1;
        for(int i=0;i<m;i++){
            if(st[i]==sk[0]){
                ind1=i;
                break;
            }
        }

        for(int i=m-1;i>=0;i--){
            if(st[i]==sk[n-1]){
                ind2=i;
                break;
            }
        }
        mp1[0]=ind1;
        mp2[n-1]=ind2;
        int j1=m-1;
        int i1=n-1;
        while(j1>ind1 && i1>0){
            if(st[j1]==sk[i1]){
                mp1[i1]=j1;
                i1--;
            }
            j1--;
        }

        int j2=0,i2=0;
        while(j2<ind2 && i2<n-1){
            if(st[j2]==sk[i2]){
                mp2[i2]=j2;
                i2++;
            }
            j2++;
        }



        int ans=INT_MIN;
        for(int i=1;i<n;i++){
            int diff1=mp1[i]-mp1[i-1];
            int diff2=mp2[i]-mp2[i-1];
            int diff3=mp1[i]-mp2[i-1];
            ans=max({ans,diff1,diff2,diff3});
        }

        return ans;
    }
};