class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        unordered_set<int> st;
        vector<int> c(n,0);
        for(int i=0;i<n;i++)
        {
            st.insert(A[i]);
        }
        c[n-1]=n;
        if(st.find(A[n-1])!=st.end())st.erase(A[n-1]);
        if(st.find(B[n-1])!=st.end())st.erase(B[n-1]);
        for(int i=n-2;i>=0;i--)
        {
            c[i]=st.size();
            if(st.find(A[i])!=st.end()) st.erase(A[i]);
            if(st.find(B[i])!=st.end()) st.erase(B[i]);
        }
        return c;
    }
};