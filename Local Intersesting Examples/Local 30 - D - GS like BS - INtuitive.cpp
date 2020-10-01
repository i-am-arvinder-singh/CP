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
    int n;
    cin>>n;
    int P[n],Q[n],R[n];
    for(int i=0;i<n;i++) cin>>P[i]>>Q[i]>>R[i];
    int lowp=P[0],lowq=Q[0],lowr=R[0];
    int id = 0;
    for(int i=1;i<n;i++){
        if((P[i]<lowp && Q[i]<lowq) || (R[i]<lowr && Q[i]<lowq) || (R[i]<lowr && P[i]<lowp)){
            lowp = P[i], lowq = Q[i], lowr = R[i];
            id = i;
        }
    }
    for(int i=0;i<n;i++){
        if(id==i) continue;
        if((P[i]<lowp && Q[i]<lowq) || (R[i]<lowr && Q[i]<lowq) || (R[i]<lowr && P[i]<lowp)){
            cout<<-1<<endl;
            return;
        }
    }
    cout<<id+1<<endl;
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

