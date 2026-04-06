class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string> st;
        for(int i=0;i<obstacles.size();i++)
        {
            string key=to_string(obstacles[i][0])+"_"+to_string(obstacles[i][1]);
            st.insert(key);
        }

        int x=0,y=0;
        int mxd=0;

        pair<int,int> dir={0,1};

        for(int i=0;i<commands.size();i++)
        {
            if(commands[i]==-2) dir={-dir.second,dir.first};
            else if(commands[i]==-1) dir={dir.second,-dir.first};
            else
            {
                for(int k=0;k<commands[i];k++)
                {
                    int nx=x+dir.first;
                    int ny=y+dir.second;

                    string key=to_string(nx)+"_"+to_string(ny);
                    if(st.find(key)!=st.end()) break;

                    x=nx;
                    y=ny;
                }
            }
            mxd=max(mxd,x*x +y*y);
        }

        return mxd;
    }
};