class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        int mx=0;
        for(int i=0;i<n;i++) mx=max(mx,nums[i]);
        int T=1;
        while(T<=mx){
            T*=2;
        }
        vector<int> v1(T,0),v2(T,0);
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                v1[nums[i]^nums[j]]=1;
            }
        }

        for(int i=0;i<T;i++){
            if(v1[i]==0) continue;
            for(int j=0;j<n;j++){
                v2[nums[j]^i]=1;
            }
        }

        int ans=0;
        for(int i=0;i<T;i++){
            if(v2[i]==1) ans++;
        }

        return ans;
    }
};