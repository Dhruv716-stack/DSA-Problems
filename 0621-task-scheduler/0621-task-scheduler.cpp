class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int m=tasks.size();
        vector<int>mp (26,0);
        for(auto &ch:tasks){
            mp[ch-'A']++;
        }

        priority_queue<int> pq;
        for(int i=0;i<26;i++){
            if(mp[i]>0) pq.push(mp[i]);
        }

        int time=0;
        while(!pq.empty()){
            vector<int> temp;
            for(int i=1;i<=n+1;i++){
                if(!pq.empty()){
                int freq=pq.top();
                pq.pop();
                freq--;
                temp.push_back(freq);}
            }

            for(int f:temp){
                if(f>0) pq.push(f);
            }

            if(pq.empty()){
                time+=temp.size();
            }
            else time+=n+1;
        }

        return time;
    }
};