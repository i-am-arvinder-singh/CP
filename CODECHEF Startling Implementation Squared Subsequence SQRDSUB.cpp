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

void solve()
{
    int n;
    cin>>n;
    int a[n];
    fl(i,0,n) cin>>a[i];
    int cnt=0,l=-1,r=-1,ans=0;
    fl(i,0,n){
        if(a[i]%2==0){
            cnt=0;
            if(a[i]%4==0){
                l=i;
                r=i;
            }
            else{
                l=r;
                r=i;
            }
            ans+=(l+1);
        }
        else{
            cnt++;
            ans+=cnt;
            ans+=(l+1);
        }
    }
    cout<<ans<<endl;
}

int32_t main()
{
	fio;
	w(t) solve();
	return 0;
}
