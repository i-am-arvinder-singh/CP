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

void solve()
{
    //Instead of using array use map this
    //will help in better handle corner cases
    map<int,int> inp;
    cin>>inp[0]>>inp[1]>>inp[2]>>inp[3];
    int total = inp[0]+inp[1]+inp[2]+inp[3];
    for(int st=0;st<4;st++){
        if(inp[st]){
            vi res;
            auto temp = inp;
            temp[st]--;
            res.pb(st);
            int last = st;
            fl(i,0,total-1){
                if(temp[last-1]){
                    temp[last-1]--;
                    res.pb(last-1);
                    last--;
                }
                else if(temp[last+1]){
                    temp[last+1]--;
                    res.pb(last+1);
                    last++;
                }
                else break;
            }
            if((int)res.size()==total){
                cout<<"YES"<<endl;
                for(auto x:res) cout<<x<<" ";
                cout<<endl;
                return;
            }
        }
    }
    cout<<"NO"<<endl;
}

int32_t main()
{
	omniphantom
	solve();
	return 0;
}
