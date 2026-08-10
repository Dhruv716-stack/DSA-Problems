class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        if(n==1) return nums;
        else if(n==2){
            if(nums[0]==nums[1]) return {nums[0]};
            else return {nums[0],nums[1]};
        }

        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            int j=i+1;
            bool flag=false;
            while(j<n && nums[i]==nums[j]){
                j++;
                flag=true;
            }
            if(flag==true){
                if((j-i)>n/3) ans.push_back(nums[i]);
                i=j-1;
            }
        }

        return ans;
    }
};