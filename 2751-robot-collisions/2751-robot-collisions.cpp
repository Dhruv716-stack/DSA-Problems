class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();

        map<int,pair<int,pair<char,int>>> mp;
        for(int i=0;i<n;i++)
        {
            mp[positions[i]] = {i,{directions[i],healths[i]}};
        }

        stack<pair<int,pair<int,int>>> st;
        vector<int> ans(n,0);

        for(auto &it:mp)
        {
            char dir = it.second.second.first;
            int health = it.second.second.second;
            int pos = it.first;
            int ind = it.second.first;

            if(dir == 'R')
            {
                st.push({pos,{ind,health}});
            }
            else // L
            {
                while(!st.empty() && health > 0)
                {
                    int Rh = st.top().second.second;
                    int pind = st.top().second.first;
                    int p = st.top().first;
                    st.pop();

                    if(Rh > health)
                    {
                        Rh--;
                        st.push({p,{pind,Rh}});
                        health = 0;
                    }
                    else if(Rh == health)
                    {
                        health = 0;
                    }
                    else
                    {
                        health--;
                    }
                }

                if(health > 0)
                {
                    ans[ind] = health;
                }
            }
        }

        while(!st.empty())
        {
            int health = st.top().second.second;
            int ind = st.top().second.first;
            st.pop();
            ans[ind] = health;
        }

        vector<int> ans2;
        for(int i=0;i<n;i++)
        {
            if(ans[i] > 0) ans2.push_back(ans[i]);
        }

        return ans2;
    }
};