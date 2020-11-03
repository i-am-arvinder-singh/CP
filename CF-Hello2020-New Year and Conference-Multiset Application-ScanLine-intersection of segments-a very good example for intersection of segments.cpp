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
int inp[mx][4];
int n;

bool check(int sa, int ea, int sb, int eb)
{
    vector<tuple<int,int,int>> srt;
    fl(i,0,n){//0->indicates start, i->index of lecture, 1->indicates end
        srt.pb(make_tuple(inp[i][sa],0,i));
        srt.pb(make_tuple(inp[i][ea],1,i));
    }
    sort(srt.begin(),srt.end());
    //Multiset is require otherwise we lose the track in case of multiple elements
    multiset<int> sbSet;
    multiset<int> ebSet;
    fl(i,0,srt.size()){
        int id = get<2>(srt[i]);
        int typ = get<1>(srt[i]);
        if(typ==0){
            sbSet.insert(inp[id][sb]);
            ebSet.insert(inp[id][eb]);
            //Max of start <= Min of end
            //Overlap exists for multiple segments
            //Else atleast one overlap of two segments/
            //does not exist
            if(*prev(sbSet.end())>*ebSet.begin()) return false;
        }
        else{
            sbSet.erase(sbSet.find(inp[id][sb]));
            ebSet.erase(ebSet.find(inp[id][eb]));
        }
    }
    return true;
}

void solve()
{
    cin>>n;
    fl(i,0,n) fl(j,0,4) cin>>inp[i][j];
    bool val = check(0,1,2,3);
    val = val && check(2,3,0,1);
    if(val) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int32_t main()
{
	omniphantom
    solve();
	return 0;
}
