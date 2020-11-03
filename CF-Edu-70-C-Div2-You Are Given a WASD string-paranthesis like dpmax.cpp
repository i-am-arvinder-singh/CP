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
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define pw(b,p)         pow(b,p) + 0.1
#define ini             const int
#define sz(v)           ((int)(v).size())
#define ppii            pair<int,pii>

const double pi = acos(-1.0);

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int max_pos_y, max_neg_y, max_pos_x, max_neg_x;

void solve()
{
    //Thank You Harshit Bhaiya :) @harshit15
    string s;
    cin>>s;
    int n = s.length();
    int x=0, y=0;
    int maxy=0, miny=0, maxx=0, minx=0;
    vector<int> dpmaxx(n),dpminx(n),dpmaxy(n),dpminy(n);
    for(int i=0;i<n;i++){
        if(s[i]=='W') y++;
        else if(s[i]=='S') y--;
        else if(s[i]=='D') x++;
        else if(s[i]=='A') x--;
        maxy=max(maxy,y);
        miny=min(miny,y);
        maxx=max(maxx,x);
        minx=min(minx,x);
        dpmaxx[i] = x;
        dpminx[i] = x;
        dpmaxy[i] = y;
        dpminy[i] = y;
    }
    for(int i=n-2;i>=0;i--){
        dpmaxx[i]=max(dpmaxx[i+1],dpmaxx[i]);
        dpminx[i]=min(dpminx[i+1],dpminx[i]);
        dpmaxy[i]=max(dpmaxy[i+1],dpmaxy[i]);
        dpminy[i]=min(dpminy[i+1],dpminy[i]);
    }
    int a = maxx -minx +1;
    int b = maxy -miny +1;
    int ans = a*b;
    x=0,y=0;
    maxy=0, miny=0, maxx=0, minx=0;
    for(int i=0;i<n;i++){
        int val = max({x-1,maxx,dpmaxx[i]-1}) - min({x-1,minx,dpminx[i]-1}) + 1;
        ans = min(ans,val*b);
        val = max({x+1,maxx,dpmaxx[i]+1}) - min({x+1,minx,dpminx[i]+1}) + 1;
        ans = min(ans,val*b);
        val = max({y-1,maxy,dpmaxy[i]-1}) - min({y-1,miny,dpminy[i]-1}) + 1;
        ans = min(ans,a*val);
        val = max({y+1,maxy,dpmaxy[i]+1}) - min({y+1,miny,dpminy[i]+1}) + 1;
        ans = min(ans,a*val);
        if(s[i]=='W') y++;
        else if(s[i]=='S') y--;
        else if(s[i]=='D') x++;
        else if(s[i]=='A') x--;
        maxy=max(maxy,y);
        miny=min(miny,y);
        maxx=max(maxx,x);
        minx=min(minx,x);
    }
    cout<<ans<<endl;
}

int32_t main()
{
	omniphantom
	#if 1
	w(t)
	#endif // 0
    solve();
	return 0;
}

