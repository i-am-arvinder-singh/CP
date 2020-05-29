#include<bits/stdc++.h>
using namespace std;

#define endl            "\n"
#define ff              first
#define int             long long
#define ss              second
#define fl(i,a,b)       for(int i=a; i<b; i++)
#define bfl(i,a,b)      for(int i=a-1; i>=b; i--)
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define vt(type)        vector<type>
#define fio          ios_base::sync_with_stdio(false);   cin.tie(NULL); cout.tie(NULL);
#define mii             map<int,int>
#define pqb             priority_queue<int>
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

void solve()
{
    int n;
    cin>>n;
    set<int> s,v;
    int sq = sqrt(n);
    for(int i=1;i*i<=sq;i++)
        if(n%i==0) s.insert(i),s.insert(n/i);
    for(auto i:s)
        for(auto j:s)
            v.insert(i*j);
    int ans1=0,ans2=(n-1)*(n-1);
    for(auto i:v){
        if(i==n)
            break;
        else{
            ans1+=((n/i)-i)*((n/i)-i);
            ans2-=((n/i)-i)*((n/i)-i);
            swap(ans1,ans2);
        }
    }
    if(ans1<ans2) swap(ans1,ans2);
    cout<<ans1<< " "<<ans2<<endl;
}

int32_t main()
{
	fio;
	w(t){
	    solve();
	}
	return 0;
}