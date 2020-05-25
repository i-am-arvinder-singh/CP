#include<bits/stdc++.h>
using namespace std;

#define endl            "\n"
#define ff              first
#define ss              second
#define int             long long
#define fl(i,a,b)       for(int i=a; i<b; i++)
#define bfl(i,a,b)      for(int i=a-1; i>=b; i--)
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define vt(type)        vector<type>
#define fio             ios_base::sync_with_stdio(false);   cin.tie(NULL); cout.tie(NULL);
#define mii             map<int,int>
#define pqb             priority_queue<int>
//Below is implementation of min heap
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             998244353
#define inf             LLONG_MAX
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define pw(b,p)         pow(b,p) + 0.1
#define ini             const int
#define LEFT(n) (2*n)
#define RIGHT(n) (2*n+1)
#define PARENT(n) (n/2)

int32_t main()
{
	fio;
	int n;
	cin>>n;
	int inp[n];
	map<int,int> dp;
	fl(i,0,n) cin>>inp[i];
	int cnt=0,val;
	fl(i,0,n){
	    dp[inp[i]]=dp[inp[i]-1]+1;
	    if(dp[inp[i]]>cnt){
            cnt=dp[inp[i]];
            val=inp[i];
	    }
	}
	val=val-cnt+1;
	cout<<cnt<<endl;
	fl(i,0,n){
	    if(inp[i]==val){
            cout<<i+1<<" ";
            val++;
	    }
	}
	return 0;
}
