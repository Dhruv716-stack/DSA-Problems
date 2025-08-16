#include <bits/stdc++.h>
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        unordered_set<string> st(wordList.begin(),wordList.end());
        if(st.find(beginWord)!=st.end())st.erase(beginWord);
        while(!q.empty())
        {
            auto p=q.front();
            string word=p.first;
            int steps=p.second;
            q.pop();
            if(word==endWord) return steps;
            for(int i=0;i<word.size();i++)
            {
                char ori=word[i];
                for(char ch='a';ch<='z';ch++)
                {
                    word[i]=ch;
                    if(st.find(word)!=st.end())
                    {
                        st.erase(word);
                        q.push({word,steps+1});
                    }
                }
                word[i]=ori;
            }
        }
        return 0;
    }
};