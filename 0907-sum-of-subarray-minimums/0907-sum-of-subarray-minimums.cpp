class Solution {
public:
    typedef long long ll;
    const int M=1e9+7;
    vector<int> next_smaller(vector<int>&arr){
        int n=arr.size();
        vector<int> nse(n,0);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            if(st.empty()) nse[i]=n;
            else if(!st.empty() && arr[i]>arr[st.top()]) nse[i]=st.top();
            else{
                while(!st.empty() && arr[i]<arr[st.top()]) st.pop();
                if(st.empty()) nse[i]=n;
                else nse[i]=st.top();
            }
            st.push(i);
        }
        return nse;
    }

    vector<int> prev_smaller(vector<int>&arr){
        int n=arr.size();
        vector<int> pse(n,0);
        stack<int> st;
        for(int i=0;i<n;i++){
            if(st.empty()) pse[i]=-1;
            else if(!st.empty() && arr[i]>arr[st.top()]) pse[i]=st.top();
            else{
                while(!st.empty() && arr[i]<=arr[st.top()]) st.pop();
                if(st.empty()) pse[i]=-1;
                else pse[i]=st.top();
            }
            st.push(i);
        }
        return pse;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int> pse=prev_smaller(arr);
        vector<int> nse=next_smaller(arr);
        ll ans=0;
        for(int i=0;i<n;i++){
            ll l=i-pse[i];
            ll r=nse[i]-i;
            ans=(ans+(1LL*arr[i]*l*r))%M;
        }
        return ans;

    }
};