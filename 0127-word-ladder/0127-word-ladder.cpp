class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        if(st.find(beginWord)!=st.end()) st.erase(beginWord);

        while(!q.empty()){
            auto [word,d]=q.front();
            q.pop();

            if(word==endWord) return d;

            for(int i=0;i<word.size();i++){
                char original=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        q.push({word,d+1});
                        st.erase(word);
                    }
                }
                word[i]=original;
            }
        }

        return 0;
    }
};