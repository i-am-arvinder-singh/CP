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

void solve()
{
    int n;
    cin>>n;
    vector<int> pos(n),neg(n),dp(n);
    for(int i=0;i<n;i++){
        cin>>pos[i];
        neg[i]=-pos[i];
    }
    dp[n-1]=0;
    stack<int> st_pos, st_neg;
    st_pos.push(n-1), st_neg.push(n-1);
    for(int i=n-2;i>=0;i--){
        dp[i]=n-i;
        while(!st_pos.empty() && pos[st_pos.top()]<pos[i]){
            dp[i]=min(dp[i],1+dp[st_pos.top()]);
            st_pos.pop();
        }
        if(!st_pos.empty()){
            dp[i]=min(dp[i],1+dp[st_pos.top()]);
            if(!st_pos.empty() && pos[i]==pos[st_pos.top()]) st_pos.pop();
        }
        st_pos.push(i);
        while(!st_neg.empty() && neg[st_neg.top()]<neg[i]){
            dp[i]=min(dp[i],1+dp[st_neg.top()]);
            st_neg.pop();
        }
        if(!st_neg.empty()){
            dp[i]=min(dp[i],1+dp[st_neg.top()]);
            if(!st_neg.empty() && neg[i]==neg[st_neg.top()]) st_neg.pop();
        }
        st_neg.push(i);
    }
    cout<<dp[0]<<endl;
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

