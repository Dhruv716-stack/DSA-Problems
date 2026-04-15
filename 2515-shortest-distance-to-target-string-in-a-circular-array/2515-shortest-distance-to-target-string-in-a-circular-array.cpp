class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n=words.size();
        for(int i=0;i<n;i++)
        {
            int ni=(startIndex+i)%n;
            int pi=(startIndex-i+n)%n;
            if(words[ni]==target || words[pi]==target) return i;
        }
        return -1;
    }
};