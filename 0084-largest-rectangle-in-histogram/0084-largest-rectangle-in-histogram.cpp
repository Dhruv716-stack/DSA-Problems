class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        int n=nums.size();
        stack<int> st;
        int mxa=INT_MIN;
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[i]<nums[st.top()]){
                int ele_ind=st.top();
                st.pop();
                int nse=i;
                int pse=st.empty()?-1:st.top();
                mxa=max(mxa,(nse-pse-1)*nums[ele_ind]);
            }
            st.push(i);
        }

        while(!st.empty()){
            int nse=n;
            int ele_ind=st.top();
            st.pop();
            int pse=st.empty()?-1:st.top();
            mxa=max(mxa,(nse-pse-1)*nums[ele_ind]);
        }
        return mxa;
    }
};