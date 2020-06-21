#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;//which means policy based DS

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

const double pi = acos(-1.0);

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

ini mx = 1e5+5;
set<int> x_axis[mx];
set<int> y_axis[mx];
set<int> vis_x, vis_y;
int cnt = 1;

int dir_c(int d)
{
    return d%4+1;
}

void f(int x, int y, int dir)
{
    if(dir==1){
        auto it = x_axis[x].upper_bound(y);
        int lim = *it;
        if(!vis_y.empty()){//Since we are in x-dir
            auto it_ = vis_y.upper_bound(y);
            if(it_!=vis_y.end()){//it won't reach the end but anyways
                if(*it_<lim) lim=*it_;
            }
        }
        cnt+=(lim-y)-1;
        if((lim-y)==1 && (x!=1 || y!=1)) return;
        //Above statement returns when x==1 || y==1
        vis_x.insert(x);
        f(x,lim-1,dir_c(dir));
    }

    if(dir==2){
        auto it = y_axis[y].upper_bound(x);
        int lim = *it;
        if(!vis_x.empty()){
            auto it_ = vis_x.upper_bound(x);
            if(it_!=vis_x.end()){//it won't reach the end but anyways
                if(*it_<lim) lim=*it_;
            }
        }
        cnt+=(lim-x)-1;
        if((lim-x)==1) return;//Previous extra condition here was unnecessary
        //Above statement returns when x==1 || y==1
        vis_y.insert(y);
        f(lim-1,y,dir_c(dir));
    }

    if(dir==3){
        auto it = x_axis[x].upper_bound(y-1);
        it--;
        int lim = *it;
        if(!vis_y.empty()){//Since we are in x-dir
            auto it_ = vis_y.upper_bound(y-1);
            if(it_!=vis_y.begin()){//it won't reach the begin but anyways
                it_--;
                if(*it_>lim) lim=*it_;
            }
        }
        cnt+=abs(lim-y)-1;
        if(abs(lim-y)==1) return;
        //Above statement returns when x==1 || y==1
        vis_x.insert(x);
        f(x,lim+1,dir_c(dir));
    }

    if(dir==4){
        auto it = y_axis[y].upper_bound(x-1);
        it--;
        int lim = *it;
        if(!vis_x.empty()){//Since we are in x-dir
            auto it_ = vis_x.upper_bound(x-1);
            if(it_!=vis_x.begin()){//it won't reach the begin but anyways
                it_--;
                if(*it_>lim) lim=*it_;
            }
        }
        cnt+=abs(lim-x)-1;
        if(abs(lim-x)==1) return;
        //Above statement returns when x==1 || y==1
        vis_y.insert(y);
        f(lim+1,y,dir_c(dir));
    }
}

void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    fl(i,0,k){
        int x,y;
        cin>>x>>y;
        x_axis[x].insert(y);
        y_axis[y].insert(x);
    }
    fl(i,1,m+1){
        y_axis[i].insert(n+1);
        y_axis[i].insert(0);
    }
    fl(i,1,n+1){
        x_axis[i].insert(m+1);
        x_axis[i].insert(0);
    }
    f(1,1,1);//( <x> , <y> , <direction> )
//    cout<<cnt<<endl;
    if(n*m-k==cnt) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

int32_t main()
{
	omniphantom
    solve();
	return 0;
}
