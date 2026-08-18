class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0,j=0;
        unordered_map<int,int> mp;
        unordered_set<int> st;
        while(i<n && j<n){
            if(j-i+1 ==k){
                for(int l=i;l<=j;l++){
                    st.insert(nums[l]);
                }

                for(auto &x:st){
                    mp[x]++;
                }

                st.erase(nums[i]);
                i++;
            }
            j++;
        }

        int res=-1;
        for(auto &it:mp){
            if(it.second==1 && it.first>res){
                res=it.first;
            }
        }
        return res;
    }
};