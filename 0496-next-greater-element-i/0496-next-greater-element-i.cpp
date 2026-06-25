class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        int m=nums1.size();
        unordered_map<int,int> mp;
        stack<int> st;

        for(int i=n-1;i>=0;i--)
        {
            if(st.empty()) mp[nums2[i]]=-1;
            else if(!st.empty() && nums2[i]<st.top()) mp[nums2[i]]=st.top();
            else{
                while(!st.empty() && nums2[i]>=st.top()){
                    st.pop();
                }

                if(st.empty()) mp[nums2[i]]=-1;
                else mp[nums2[i]]=st.top();
            }
            st.push(nums2[i]);
        }
        vector<int> ans(m);
        for(int i=0;i<m;i++)
        {
            ans[i]=mp[nums1[i]];
        }
        return ans;
    }
};