class Solution {
public: 
    typedef long long ll;
    vector<int> next_greater(vector<int>& nums){
        int n=nums.size();
        stack<int> st;
        vector<int> nge(n,0);
        for(int i=n-1;i>=0;i--){
            if(st.empty()) nge[i]=n;
            else if (!st.empty() && nums[i]<nums[st.top()]) nge[i]=st.top();
            else
            {
                while(!st.empty() && nums[i]>=nums[st.top()]){
                    st.pop();
                }
                if(st.empty()) nge[i]=n;
                else nge[i]=st.top();
            }
            st.push(i);
        }
        return nge;
    }

    vector<int> next_smaller(vector<int>& nums){
        int n=nums.size();
        stack<int> st;
        vector<int> nse(n,0);
        for(int i=n-1;i>=0;i--){
            if(st.empty()) nse[i]=n;
            else if (!st.empty() && nums[i]>nums[st.top()]) nse[i]=st.top();
            else
            {
                while(!st.empty() && nums[i]<=nums[st.top()]){
                    st.pop();
                }
                if(st.empty()) nse[i]=n;
                else nse[i]=st.top();
            }
            st.push(i);
        }
        return nse;
    }

    vector<int> prev_smaller_equal(vector<int>& nums){
        int n=nums.size();
        stack<int> st;
        vector<int> psee(n,0);
        for(int i=0;i<n;i++){
            if(st.empty()) psee[i]=-1;
            else if (!st.empty() && nums[i]>=nums[st.top()]) psee[i]=st.top();
            else
            {
                while(!st.empty() && nums[i]<nums[st.top()]){
                    st.pop();
                }
                if(st.empty()) psee[i]=-1;
                else psee[i]=st.top();
            }
            st.push(i);
        }
        return psee;
    }

    vector<int> prev_greater_equal(vector<int>& nums){
        int n=nums.size();
        stack<int> st;
        vector<int> pgee(n,0);
        for(int i=0;i<n;i++){
            if(st.empty()) pgee[i]=-1;
            else if (!st.empty() && nums[i]<=nums[st.top()]) pgee[i]=st.top();
            else
            {
                while(!st.empty() && nums[i]>nums[st.top()]){
                    st.pop();
                }
                if(st.empty()) pgee[i]=-1;
                else pgee[i]=st.top();
            }
            st.push(i);
        }
        return pgee;
    }
    long long subArrayRanges(vector<int>& nums) {
        vector<int> nge=next_greater(nums);
        vector<int> pgee=prev_greater_equal(nums);
        vector<int> nse=next_smaller(nums);
        vector<int> psee=prev_smaller_equal(nums);
        int n=nums.size();
        ll ans=0;
        for(int i=0;i<n;i++){
            int lmx=i-pgee[i];
            int rmx=nge[i]-i;
            int lmn=i-psee[i];
            int rmn=nse[i]-i;
            ll mx=(1LL*lmx*rmx*nums[i]);
            ll mn=(1LL*lmn*rmn*nums[i]);
            ans+=(mx-mn);
        }

        return ans;
        
    }
};