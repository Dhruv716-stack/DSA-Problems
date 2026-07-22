class LFUCache {
public:
    int cap;
    int size;

    unordered_map<int,list<vector<int>>::iterator> mp;
    map<int,list<vector<int>>> freq;
    LFUCache(int capacity) {
        cap=capacity;
        size=0;
    }

    void makeFrequencyUpdate(int key){
        auto &vec=*(mp[key]);
        int f=vec[2];
        int val=vec[1];

        freq[f].erase(mp[key]);
        if(freq[f].empty()) freq.erase(f);

        f++;
        freq[f].push_front(vector<int>{key,val,f});
        mp[key]=freq[f].begin();
        return;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;

        auto vec=(*(mp[key])); //{key, value, frequncy}
        int val=vec[1];

        makeFrequencyUpdate(key);
        return val;

    }
    
    void put(int key, int value) {
        if(cap==0) return;

        if(mp.find(key)!=mp.end()){
            auto &vec=*(mp[key]);
            vec[1]=value;
            makeFrequencyUpdate(key);
            return;
        }
        else if(size<cap){
            size++;
            freq[1].push_front(vector<int>{key,value,1});
            mp[key]=freq[1].begin();
        }
        else{
            //Time to remove LFU or LRU when there is tie

            auto &kaun_sa_list=freq.begin()->second;
            int key_to_delete=kaun_sa_list.back()[0];

            kaun_sa_list.pop_back();
            if(kaun_sa_list.empty()) freq.erase(freq.begin()->first);

            freq[1].push_front(vector<int>{key,value,1});
            mp.erase(key_to_delete);
            mp[key]=freq[1].begin();
            return;
        }

    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */