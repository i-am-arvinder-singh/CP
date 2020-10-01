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

void solve()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    int q;
    cin>>q;
    vector<int> arr1(n,-1);
    vector<int> arr2;
    map<int,int> my;
    map<int,int> my_q;
    for(int i=0;i<q;i++){
        int code;
        cin>>code;
        if(code==1){
            int x,y;
            cin>>x>>y;
            arr1[x-1]=i;
            my[i]=y;
        }
        else{
            int x;
            cin>>x;
            arr2.pb(i);
            my_q[i]=x;
        }
    }
    for(int i=(int)arr2.size()-2;i>=0;i--){
        my_q[arr2[i]]=max(my_q[arr2[i]],my_q[arr2[i+1]]);
    }
    vector<int> ans(n,-1);
    for(int i=0;i<n;i++){
        // cout<<"**** "<<arr1[i]<<endl;
        if(arr1[i]==-1){
            my[arr1[i]]=v[i];
            if((int)arr2.size()){
                my[arr1[i]]=max(my[arr1[i]],my_q[arr2[0]]);
            }
            ans[i] = my[arr1[i]];
        }
        else{
            int cur = arr1[i];
            int id = upper_bound(arr2.begin(),arr2.end(),cur) - arr2.begin();
            if(id!=(int)arr2.size()){
                my[arr1[i]]=max(my[arr1[i]],my_q[arr2[id]]);
            }
            ans[i] = my[arr1[i]];
        }
    }
    for(int i=0;i<n;i++) cout<<ans[i]<<" ";
    cout<<endl;
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

