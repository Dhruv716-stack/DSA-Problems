class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        map<int,int> mp;
        if(n%groupSize!=0) return false;
        for(int i=0;i<n;i++){
            mp[hand[i]]++;
        }

        while(!mp.empty()){
            int curr=mp.begin()->first;
            mp[curr]--;
            if(mp[curr]==0) mp.erase(curr);
            int i=1;
            while(i<groupSize){
                curr++;
                if(mp.find(curr)==mp.end()) return false;
                mp[curr]--;
                if(mp[curr]==0) mp.erase(curr);
                i++;
            }
        }

        return true;
    }
};