#define pb push_back

class Solution {
public:
    int nthUglyNumber(int n) {
        if(n<=0) return 0;
        if(n==1) return 1;
        vector<int> v(n);
        v[0]=1;
        int var1=0,var2=0,var3=0;
        int ans = 1000000000;
        for(int i=1;i<n;i++){
            v[i]=min({v[var1]*2,v[var2]*3,v[var3]*5});
            if(v[i]==v[var1]*2) var1++;
            if(v[i]==v[var2]*3) var2++;
            if(v[i]==v[var3]*5) var3++;
        }
        return v[n-1];
    }
};