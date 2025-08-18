class Solution {
public:
    unordered_map<string,int> mp;
    vector<vector<string>> ans;

    void dfs(vector<string>&seq, string word,string beginWord)
    {
        if(word==beginWord)
        {
            reverse(seq.begin(),seq.end());
            ans.push_back(seq);
            reverse(seq.begin(),seq.end());
        }
        int steps=mp[word];
        for(int i=0;i<word.size();i++)
        {
            char ori=word[i];
            for(char ch='a';ch<='z';ch++)
            {
                word[i]=ch;
                if(mp.find(word)!=mp.end() && mp[word]+1==steps)
                {
                    seq.push_back(word);
                    dfs(seq,word,beginWord);
                    seq.pop_back();
                }
            }
            word[i]=ori;
        }
        return;

    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        q.push(beginWord);
        unordered_set<string> st(wordList.begin(),wordList.end());
        st.erase(beginWord);
        mp[beginWord]=1;
        while(!q.empty())
        {
            string word=q.front();
            q.pop();
            int steps=mp[word];
            int sz=word.size();
            if(word==endWord) break;
            for(int i=0;i<sz;i++)
            {
                char ori=word[i];
                for(char ch='a';ch<='z';ch++)
                {
                    word[i]=ch;
                    if(st.count(word))
                    {
                        q.push(word);
                        st.erase(word);
                        mp[word]=steps+1;
                    }
                    word[i]=ori;
                }
            }
        }
        vector<string> seq;
        seq.push_back(endWord);
        dfs(seq,endWord,beginWord);
        return ans;
    }
};