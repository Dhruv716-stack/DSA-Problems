class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int ele=0,cnt=0;
        for(int i=0;i<n;i++){
            if(cnt==0) ele=nums[i];
            if(nums[i]==ele) cnt++;
            else cnt--;
        }

        cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]==ele) cnt++;
        }

        return cnt>n/2?ele:-1;
    }
};