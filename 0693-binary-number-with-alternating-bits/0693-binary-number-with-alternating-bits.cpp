class Solution {
public:
    bool hasAlternatingBits(int n) {
        int highest_set_bit=log2(n);
        int x=n>>1;
        int z=x^n;
        if(__builtin_popcount(z)==highest_set_bit+1) return true;
        return false;

    }
};