class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp;
        temp.push_back(nums[0]);
        for(int i=1;i<n;i++)
        {
            int x=nums[i];
            if(x>temp[temp.size()-1]) temp.push_back(x);
            else
            {int ind=lower_bound(temp.begin(),temp.end(),x)-temp.begin();
            temp[ind]=x;
            }
        }
        return temp.size();
    }
};