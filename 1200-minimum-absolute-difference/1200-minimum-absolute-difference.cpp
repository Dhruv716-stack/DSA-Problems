class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int i=0,j=1;
        int mini=INT_MAX;
        while(j<n)
        {
            mini=min(mini,abs(arr[j]-arr[i]));
            i++;
            j++;
        }
        vector<vector<int>> v;
        for(int i=0;i<n-1;i++)
        {
            if(abs(arr[i]-arr[i+1])==mini) v.push_back({arr[i],arr[i+1]});
        }
        return v;
    }
};