class Solution {
    int fact[10];
public:
    string getPermutation(int n, int k) {
        precompute();
        set<int> s;
        for(int i=1;i<=n;i++) s.insert(i);
        int t = 0;
        string ans;
        while(k){
            int w=(k+fact[n-1]-1)/fact[n-1];
            auto it = s.begin();
            int cnt=1;
            while(cnt!=w){
                it++;
                cnt++;
            }
            int val = *it;
            s.erase(it);
            char ch = val+'0';
            ans+=ch; 
            n--;
            k-=((w-1)*fact[n]);            
            if(k<=0 || n<=0) break;
        }
        if(!s.empty()){
            for(auto x:s){
                char ch = x+'0';
                ans+=ch;
            }
        }
        return ans;
    }
    
    void precompute()
    {
        fact[0]=1;
        fact[1]=1;
        for(int i=2;i<=9;i++){
            fact[i]=i*fact[i-1];
        }
    }
    
};