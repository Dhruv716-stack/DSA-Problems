class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int n=word.size();
        int ans=0;
        for(auto &w:patterns){
            int sz=w.size();
            
            int j=0;
            for(int i=0;i<n;i++){
                if(word[i]==w[j]){
                    int k=i;
                    while(k<n && j<sz){
                        if(word[k]==w[j]){
                            k++;
                            j++;
                        }
                        else{
                            j=0;
                            break;
                        }
                    }

                    if(j==sz) ans++;
                }
            }
        }

        return ans;
    }
};