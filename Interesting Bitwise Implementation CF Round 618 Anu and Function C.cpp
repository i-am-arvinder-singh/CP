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

ini mx=1e5+5;
vi track[mx],ans;
int mark[mx];

int32_t main()
{
	fio;
	int n;
	cin>>n;
	int a[n];
	fl(i,0,n) cin>> a[i];
	fl(i,0,n)
        fl(j,0,31)
            if((a[i]>>j)&(int)1)
                track[j].pb(i);
    bfl(i,31,0)
        if(track[i].size()==1 && mark[track[i][0]]==0){
            ans.pb(a[track[i][0]]),mark[track[i][0]]=1;
            break;
        }
    fl(i,0,n)
        if(!mark[i])
            ans.pb(a[i]);
    for(auto x: ans)
        cout<<x<<" ";
	return 0;
}
