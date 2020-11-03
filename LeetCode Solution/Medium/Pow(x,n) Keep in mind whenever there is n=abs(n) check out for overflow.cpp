class Solution {
public:
    double myPow(double x, int n) {
        double temp = 1.0;
        if(n>=0){
            while(n){
                if(n&1) temp*=x;
                x*=x;
                n>>=1;
            }
            return temp;
        }
        else{
            long long nn = n;
            nn=abs(nn);
            while(nn){
                if(nn&1) temp*=x;
                x*=x;
                nn>>=1;
            }
            return 1/temp;
        }
    }
};