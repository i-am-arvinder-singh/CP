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

vi gems[3];
vt(pii) total;

int evaluate(int x, int y, int z)
{
    return (x-y)*(x-y) + (y-z)*(y-z) + (z-x)*(z-x);
}

void solve()
{
    int nr,ng,nb,x;//r=0 g=1 b=2
    cin>>nr>>ng>>nb;
    fl(i,0,nr){
        cin>>x;
        gems[0].pb(x);
        total.pb({x,0});
    }
    fl(i,0,ng){
        cin>>x;
        gems[1].pb(x);
        total.pb({x,1});
    }
    fl(i,0,nb){
        cin>>x;
        gems[2].pb(x);
        total.pb({x,2});
    }
    fl(i,0,3)  sort(gems[i].begin(),gems[i].end());
    sort(total.begin(),total.end());
    vi last(3,-1);
    int ans=LLONG_MAX;
    fl(i,0,total.size()){
        int color=total[i].second;
        int j=min(last[(color+1)%3],last[(color+2)%3]);
        //If the above is not assigned as -1 it means that
        //both the colors are found and we can proceed
        if(j>-1){
            int x=total[j].first;
            int z=total[i].first;
            int y_color=3-color-total[j].second;
            int y;
            int p=lower_bound(gems[y_color].begin(),gems[y_color].end(),(x+z)/2)-gems[y_color].begin();
            if(p==gems[y_color].size())
                y=*(--gems[y_color].end());
            else{
                if(p==0){
                    y=*(gems[y_color].begin());
                }
                else{
                    int y1=gems[y_color][p];
                    int y2=gems[y_color][p-1];
                    int k=(x+z)/2;
                    if(abs(y1-k)<=abs(y2-k))
                        y=y1;
                    else
                        y=y2;
                }
            }
            ans=min(ans,evaluate(x,y,z));
        }
        last[color]=i;
    }
    cout<<ans<<endl;
    fl(i,0,3) gems[i].clear();
    total.clear();
}

int32_t main()
{
	fio;
	w(t) solve();
	return 0;
}