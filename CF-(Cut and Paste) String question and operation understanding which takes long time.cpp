#include<bits/stdc++.h>
using namespace std;

#define endl            "\n"
#define int             long long
#define ff              first
#define ss              second
#define fl(i,a,b)       for(int i=a; i<b; i++)
#define bfl(i,a,b)      for(int i=a-1; i>=b; i--)
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define vt(type)        vector<type>
#define omniphantom     ios_base::sync_with_stdio(false);   cin.tie(NULL); cout.tie(NULL);
#define mii             map<int,int>
#define pqb             priority_queue<int>
//Below is implementation of min heap
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define pw(b,p)         pow(b,p) + 0.1
#define ini             const int
#define sz(v)           ((int)(v).size())
#define LEFT(n) (2*n)
#define RIGHT(n) (2*n+1)

void solve()
{
    string s;
    int x;
    cin>>x>>s;
    int ans = (int) s.length();
    for(int i=0;i<x;i++){
        int times = s[i]-'1';
        int n = s.length();
//        string t = s.substr(i+1,n-i-1);//Costly operation 
        if(n<=x){
            fl(j,0,times){
                s+=s.substr(i+1,n-i-1);//Place t here
            }
        }
        ans=(ans+times*(ans-i-1))%mod;
    }
    cout<<(ans+mod)%mod<<endl;
}

int32_t main()
{
	omniphantom
	w(t) solve();
	return 0;
}
