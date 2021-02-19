class Solution {
public:
    int mod = 1e9 + 7;
    
    int findBits(int t){
        int cnt = 0;
        while(t){
            t/=2;
            cnt++;
        }
        return cnt;
    }
    
    int concatenatedBinary(int n) {
        long long ans=0;
        for(int i=1;i<=n;i++)
        {
            int len=findBits(i);
            ans=((ans<<len)+i)%mod;
        }
        return (int)ans;
    }
};