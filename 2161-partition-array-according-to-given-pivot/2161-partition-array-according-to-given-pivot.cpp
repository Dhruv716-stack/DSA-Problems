class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        vector<pair<int,int>> st1,st2,st3;
        for(int i=0;i<n;i++)
        {
            if(nums[i]<pivot){
                st1.push_back({i,nums[i]});
            }
            else if(nums[i]==pivot){
                st2.push_back({i,nums[i]});
            }
            else{
                st3.push_back({i,nums[i]});
            }
        }

        vector<int> ans;

        for(auto &it:st1)
        {
            ans.push_back(it.second);
        }

        for(auto &it:st2)
        {
            ans.push_back(it.second);
        }

        for(auto &it:st3)
        {
            ans.push_back(it.second);
        }
        return ans;


        
    }
};