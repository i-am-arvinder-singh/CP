#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;//which means policy based DS

#define endl            "\n"
#define ll              long long
#define int             long long
#define ff              first
#define ss              second
#define fl(i,a,b)       for(int i=(int)a; i<(int)b; i++)
#define bfl(i,a,b)      for(int i=(int)a-1; i>=(int)b; i--)
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
#define mod             998244353
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define pw(b,p)         pow(b,p) + 0.1
#define ini             const int
#define sz(v)           ((int)(v).size())
#define ppii            pair<int,pii>
#define BIT             1

const double pi = acos(-1.0);

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int MAX = 3e5+4;
int n,m,k,q;
int tleft[MAX];
int tright[MAX];
int safeleft[MAX];
int saferight[MAX];
int a[MAX][4];
int b[4];
int ans;
vector<int> safe;

int dis(int a, int b)
{
    return abs(a-b);
}

int f(int i, int pres, int go)
{
    int ans1 = dis(pres,tright[i]);
    ans1+=dis(tright[i],tleft[i]);
    ans1+=dis(tleft[i],go);
    int ans2 = dis(pres,tleft[i]);
    ans2+=dis(tleft[i],tright[i]);
    ans2+=dis(tright[i],go);
    return 1+min(ans1,ans2);
}

int f_last(int x)
{
    int ans1 = dis(x,tleft[n]);
    ans1+=dis(tleft[n],tright[n]);
    int ans2 = dis(x,tright[n]);
    ans2+=dis(tleft[n],tright[n]);
    return 1+min(ans1,ans2);
}

void solve()
{
    cin>>n>>m>>k>>q;
    for(int i=0;i<k;i++){
        int r,c;
        cin>>r>>c;
        if(tleft[r]==0) tleft[r] = c;
        tleft[r] = min(tleft[r],c);
        tright[r] = max(tright[r],c);
    }
    safe.resize(q);
    for(int i=0;i<q;i++) cin>>safe[i];
    sort(safe.begin(),safe.end());
    for(int i=1;i<=safe[0];i++) saferight[i] = safe[0];
    for(int i=safe[0];i<safe[1];i++) safeleft[i] = safe[0];
    for(int i=1;i<(int)safe.size()-1;i++){
        for(int j=safe[i-1]+1;j<=safe[i];j++) saferight[j] = safe[i];
        for(int j=safe[i];j<safe[i+1];j++) safeleft[j] = safe[i];
    }
    for(int i=safe[q-2]+1;i<=safe[q-1];i++) saferight[i] = safe[q-1];
    for(int i=safe[q-1];i<=m;i++) safeleft[i] = safe[q-1];
    while(tleft[n]==0) n--;
    if(n==1){
        cout<<tright[1]-1;
        return;
    }
    if(tright[1]==0){
        a[1][0] = saferight[1]-1;
        b[0] = saferight[1];
    }
    else{
        //See about tright[1];
        if(safeleft[tright[1]]!=0){
            a[1][0] = tright[1]-1 + dis(tright[1],safeleft[tright[1]]);
            b[0] = safeleft[tright[1]];
        }
        if(saferight[tright[1]]!=0){
            a[1][1] = tright[1]-1 + dis(tright[1],saferight[tright[1]]);
            b[1] = saferight[tright[1]];
        }
    }
    //Move to every other row
    for(int i=2;i<n;i++){
        if(tright[i]==0){
            for(int j=0;j<4;j++){
                a[i][j]=a[i-1][j]+1;//Like dp
            }
            continue;
        }
        vector<int> c(4);
        c[0]=safeleft[tleft[i]];
        c[1]=saferight[tleft[i]];
        c[2]=safeleft[tright[i]];
        c[3]=saferight[tright[i]];
        for(int j=0;j<4;j++) a[i][j] = inf;
        for(int k=0;k<4;k++){
            if(b[k]==0) continue;
            for(int p=0;p<4;p++){
                if(c[p]==0) continue;
                a[i][p]=min(a[i][p],a[i-1][k]+f(i,b[k],c[p]));
            }
        }
        for(int k=0;k<4;k++) b[k] = c[k];
    }
    ans = inf;
    for(int i=0;i<4;i++){
        if(b[i]==0) continue;
        ans=min(ans,a[n-1][i]+f_last(b[i]));
    }
    cout<<ans<<endl;
}

int32_t main()
{
	omniphantom
	#if 0
	w(t)
	#endif // 0
    solve();
	return 0;
}

