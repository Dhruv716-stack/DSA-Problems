class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int j=1;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {   
            mp[nums[i]]++;
        }
        int i=0;
        while(mp[0]!=0)
            {
                nums[i]=0;
                mp[0]--;
                i++;
            }
        while(mp[1]!=0)
            {
                nums[i]=1;
                mp[1]--;
                i++;
            }
        while(mp[2]!=0)
            {
                nums[i]=2;
                mp[2]--;
                i++;
            }
        }
    
};