class Solution {
    int mod = 1000000007;
    
    int power(int x, int y){
        int ans = 1;
        while(y){
            if(y&1) {
                ans=mul(ans,x);
                ans%=mod;
            }
            y>>=1;
            x=mul(x,x);
            x%=mod;
        }
        return ans;
    }
    
    int inv(int x){
        return power(x,mod-2)%mod;
    }
    
    int add(int x, int y){
        x%=mod;
        y%=mod;
        return (x+y)%mod;
    }
    
    int mul(int x, int y){
        x%=mod;
        y%=mod;
        return (((long long)x*(long long)y)%mod);
    }
    
public:
    int makeStringSorted(string s) {
        int n = s.length();
        vector<int> cnt(26);
        for(auto ele:s) cnt[ele-'a']++;
        vector<int> fact(n+2);
        vector<int> invfact(n+2);
        fact[0]=1;
        invfact[0]=inv(fact[0]);
        for(int i=1;i<n+2;i++){
            fact[i]=mul(i,fact[i-1]);
            fact[i]%=mod;
            invfact[i]=inv(fact[i]);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<(s[i]-'a');j++){
                if(cnt[j]==0) continue;
                cnt[j]--;
                int t = fact[n-i-1];
                for(int k=0;k<26;k++){
                    t=mul(t,invfact[cnt[k]]);
                }
                ans=add(ans,t);
                cnt[j]++;
            }
            cnt[s[i]-'a']--;
        }
        return ans;
    }
};







