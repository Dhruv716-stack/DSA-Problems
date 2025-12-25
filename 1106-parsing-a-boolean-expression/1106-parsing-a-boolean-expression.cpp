class Solution {
public:
    char solve(vector<char>&values,char op)
    {
        if(op=='!')
        {
            if(values[0]=='t') return 'f';
            else return 't';
        }

        else if(op=='&')
        {
            int n=values.size();
            int flag=0;
            for(int i=0;i<n;i++)
            {
                if(values[i]=='f')
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1) return 'f';
            else return 't';
        }
        else
        {
            int n=values.size();
            int flag=0;
            for(int i=0;i<n;i++)
            {
                if(values[i]=='t')
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1) return 't';
            else return 'f';
        }
        return 't';
    }
    bool parseBoolExpr(string s) {
        int n=s.size();
        stack<char> st;
        for(int i=0;i<n;i++)
        {
            if(s[i]==',') continue;
            if(s[i]==')')
            {
                vector<char> values;
                while(st.top()!='(')
                {
                    char c=st.top();
                    st.pop();
                    values.push_back(c);
                }
                st.pop();
                char op=st.top();
                st.pop();
                st.push(solve(values,op));
            }
            else st.push(s[i]);
        }
        return st.top()=='t' ? true:false;
    }
};