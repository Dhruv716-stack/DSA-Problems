class Solution {
public:
    int majorityElement(vector<int>& nums) {
       //Moores Voting Algo
       int n=nums.size();
       int ele=0,cnt=0;
       for(int i=0;i<n;i++)
       {
        if(cnt==0) ele=nums[i];
        if(ele==nums[i]) cnt++;
        else cnt--;
       } 
       int cnt1=0;
       for(int i=0;i<n;i++)
       {
        if(nums[i]==ele) cnt1++;
       }
       return cnt1>(n/2)? ele:0;
    }
};