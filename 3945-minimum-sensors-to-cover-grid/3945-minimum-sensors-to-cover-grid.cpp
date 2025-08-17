class Solution {
public:
    int minSensors(int n, int m, int k) {
      int s=2*k+1;
      int ans= (ceil(float(n)/float(s)))*(ceil(float(m)/float(s)));
      return ans;  
    }
};