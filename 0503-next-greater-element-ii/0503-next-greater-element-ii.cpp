class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> nge(2*n,0);
        stack<int> st;
        for(int i=2*n-1;i>=0;i--){
            if(st.empty()) nge[i]=-1;
            else if(!st.empty() && nums[i%n]<st.top()) nge[i]=st.top();
            else{
                while( !st.empty()&&nums[i%n]>=st.top()){
                    st.pop();
                }
                if(st.empty()) nge[i]=-1;
                else nge[i]=st.top();
            }
            st.push(nums[i%n]);
        }

        vector<int> ans(nge.begin(),nge.begin()+n);
        return ans;
    }
};