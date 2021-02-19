#define pb push_back

class Solution {
public:
    
    long long mod = 1000000007;
    
    long long add(long long x, long long y){
        x%=mod;
        y%=mod;
        return (x+y)%mod;
    }
    
    long long mul(long long x, long long y){
        x%=mod;
        y%=mod;
        return (x*y)%mod;
    }
    
    long long power(long long x, long long y){
        long long ans = 1;
        while(y){
            if(y&1){
                ans*=x;
                ans%=mod;
            }
            x*=x;
            x%=mod;
            y>>=1;
        }
        return ans;
    }
    
    long long sub(long long x, long long y){
        x=(x+mod)%mod;
        y=(y+mod)%mod;
        return (x-y+mod)%mod;
    }
    
    string longestDupSubstring(string s) {
        int n = s.length();
        int left = 1, right = s.length();
        int ans;
        string ans_string;
        while(left<=right){
            long long mid = left + (right-left)/2;
            
            
            
            bool val = false;
            string temp;
            unordered_map<long long,vector<int>> my;
            long long hash = 0;
            for(int i=mid-1;i>=0;i--){
                int ch_no = s[i] - 'a' + 1;
                hash=add(hash,mul(ch_no,power(26,mid-1-i)));
            }
            my[hash].pb(0);
            queue<char> q;
            for(int i=0;i<mid;i++) q.push(s[i]);
            for(int i=1;i<n-mid+1;i++){
                char ch = q.front();
                int ch_no_front = ch - 'a' + 1;
                hash=sub(hash,mul(ch_no_front,power(26,mid-1)));
                hash=mul(hash,26);
                q.pop();
                q.push(s[i+mid-1]);
                hash=add(hash,s[i+mid-1]-'a'+1);
                my[hash].pb(i);
                if(my[hash].size()>1){
                    bool ff = false;
                    string cur = s.substr(i,mid);
                    for(auto ele:my[hash]){
                        if(i==ele) continue;
                        string tt = s.substr(ele,mid);
                        if(tt==cur){
                            temp=s.substr(i,mid);
                            val=true;
                            ff = true;
                            break;
                        }
                    }
                    if(ff) break;
                }
            }
            
            
            
            
            if(val){
                ans = mid;
                ans_string = temp;
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        return ans_string;
    }
};