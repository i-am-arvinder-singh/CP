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
#define inf             1e18+1000
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define pw(b,p)         pow(b,p) + 0.1
#define ini             const int
#define sz(v)           ((int)(v).size())
#define ppii            pair<int,pii>
#define tup             tuple<int,int,int>
#define LEFT(x)         2*x+1
#define RIGHT(x)        2*x+2
#define MAX_SIZE        100003
#define all(v)          v.begin(),v.end()

const double pi = acos(-1.0);

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}

vector<int> serialize(vector<vector<int>> &interm){
    vector<int> temp;
    for(auto vec:interm){
        for(auto x:vec) temp.pb(x);
    }
    return temp;
}

vector<vector<int>> frontGroup(vector<int> &v){
    vector<vector<int>> retVal;
    int i = 0;
    int n = v.size();
    int cnt = 1;
    while(i<n){
        vector<int> temp;
        if(v[i]==cnt){
            temp.pb(v[i]);
            retVal.pb(temp);
            cnt++;
            i++;
        }
        else{
            while(i<n && v[i]!=cnt){
                temp.pb(v[i]);
                i++;
            }
            temp.pb(v[i]);
            i++;
            retVal.pb(temp);
            if(i==n) break;
            temp.clear();
            while(i<n) temp.pb(v[i++]);
            retVal.pb(temp);
        }
    }
    return retVal;
}

vector<vector<int>> backGroup(vector<int> &v){
    vector<vector<int>> retVal;
    int n = v.size();
    int i = n-1;
    int cnt = 1;
    while(i>=0){
        vector<int> temp;
        if(v[i]==cnt){
            temp.pb(v[i]);
            reverse(all(temp));
            retVal.pb(temp);
            cnt++;
            i--;
        }
        else{
            while(i>=0 && v[i]!=cnt){
                temp.pb(v[i]);
                i--;
            }
            temp.pb(v[i]);
            i--;
            reverse(all(temp));
            retVal.pb(temp);
            if(i==-1) break;
            temp.clear();
            while(i>=0) temp.pb(v[i--]);
            reverse(all(temp));
            retVal.pb(temp);
        }
    }
    reverse(all(retVal));
    return retVal;
}

void solve()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    vector<vector<int>> ans;
    if(v[0]!=1){
        int i = 0;
        vector<int> v1;
        vector<vector<int>> interm;
        while(i<n && v[i]!=1){
            v1.pb(v[i]);
            i++;    
        }
        interm.pb(v1);
        v1.clear();
        vector<int> temp;
        temp.pb(i);
        temp.pb(n-i);
        while(i<n) v1.pb(v[i++]);
        interm.pb(v1);
        reverse(all(interm));
        v = serialize(interm);
        ans.pb(temp);
    }
    int t = 1;
    while(!is_sorted(all(v))){
        if(t){
            vector<vector<int>> interm = frontGroup(v);
            vector<int> temp;
            for(auto vec:interm) temp.pb(vec.size());
            ans.pb(temp);
            reverse(all(interm));
            v = serialize(interm);
            t^=1;
        }
        else{
            vector<vector<int>> interm = backGroup(v);
            vector<int> temp;
            for(auto vec:interm) temp.pb(vec.size());
            ans.pb(temp);
            reverse(all(interm));
            v = serialize(interm);
            t^=1;
        }
    }
    cout<<ans.size()<<endl;
    for(auto vec:ans){
        cout<<vec.size()<<" ";
        for(auto ele:vec) cout<<ele<<" ";
        cout<<endl;
    }
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

