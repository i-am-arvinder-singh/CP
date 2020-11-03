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

void solve()
{
    int n;
    cin>>n;
    int a[n+1],pos[n+1];
    set<int> track;
    fl(i,1,n+1){
        track.insert(i);
        cin>>a[i];
        pos[a[i]]=i;
    }
    int mpp=-1;
    auto it=track.lower_bound(pos[1]+1);
    if(it!=track.end()) mpp= *it;
    track.erase(pos[1]);
    fl(i,2,n+1){
        if(mpp!=-1 && pos[i]!=mpp){
            cout<<"No\n";
            return;
        }
        it = track.lower_bound(pos[i]+1);
        if(it!=track.end()) mpp= *it;
        else mpp=-1;
        track.erase(pos[i]);
    }
    cout<<"Yes\n";
}

int32_t main()
{
	fio;
	w(t) solve();
	return 0;
}
