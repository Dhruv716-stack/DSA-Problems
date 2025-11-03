class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> ans;
        int i=0;
        int j=1;
        while(i<n && j<n)
        {
            int x=nums[j]-nums[i];
            if(x!=1)
            {
                x--;
                while(x>0)
                {
                    nums[i]++;
                    ans.push_back(nums[i]);
                    x--;
                }
            }
            i++;
            j++;
        }
        return ans;
    }
};