class Solution {
public:
    int digit_product(int n){
        int p=1;
        while(n>0){
            int r=n%10;
            p*=r;
            n=n/10;
        }
        return p;
    }
    int smallestNumber(int n, int t) {
        for(int i=n;i<=100;i++){
            int p=digit_product(i);
            if(p%t==0) return i;
        }
        return 0;
    }
};