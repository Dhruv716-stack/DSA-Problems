class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0]+1;
        int mx_sum=nums[0];
        int j=1;
        while(j<n){
             if(nums[j]==nums[j-1]+1){
                mx_sum+=nums[j];
                j++;
             }
             else break;
        }

        for(int x=mx_sum;x<=1e4;x++){
            bool flag=false;
            for(int i=0;i<n;i++){
                if(nums[i]==x){
                    flag=true;
                    break;
                }
            }

            if(flag==true) continue;
            else return x;
        }

        return 0;

    }
};