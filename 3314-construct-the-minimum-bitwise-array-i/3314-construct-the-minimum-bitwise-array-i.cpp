class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            bool flag=false;
            if(nums[i]==2)
            {
                ans.push_back(-1);
                continue;
            }
            for(int j=1;j<32;j++)
            {
                if((nums[i]& (1<<j))>0) continue; //Checking jth bit is 1 or not
                int prev=j-1;
                int x=(nums[i]^(1<<prev)); //Making j-1th set bit to zero bit
                ans.push_back(x);
                flag=true;
                break;
            }
            if(flag==false) ans.push_back(-1);
        }
        return ans;
    }
};