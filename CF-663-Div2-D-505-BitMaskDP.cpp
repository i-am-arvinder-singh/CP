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
    int n,m;
    cin>>n>>m;
    string s[n];
    for(int i=0;i<n;i++) cin>>s[i];
    if(n>=4){
        cout<<-1<<endl;
        return;
    }
    if(n==1){
        cout<<0<<endl;
        return;
    }
    vector<int> v(m);
    auto cnt = [&](int col){
        int ans = 0;
        int t = 1;
        for(int i=0;i<n;i++){
            ans+=(t * (s[i][col]=='1'));
            t<<=1ll;
        }
        return ans;
    };
    for(int i=0;i<m;i++) v[i] = cnt(i);
    vector<vector<bool>> ok3(8,vector<bool> (8,false));//ok3[prevmask][mask]
    ok3[5][0]=ok3[2][0]=true;
    ok3[4][1]=ok3[3][1]=true;
    ok3[7][2]=ok3[0][2]=true;
    ok3[6][3]=ok3[1][3]=true;
    ok3[1][4]=ok3[6][4]=true;
    ok3[7][5]=ok3[0][5]=true;
    ok3[4][6]=ok3[3][6]=true;
    ok3[5][7]=ok3[2][7]=true;
    vector<vector<bool>> ok2(4,vector<bool> (4,false));
    ok2[2][0]=ok2[1][0]=true;
    ok2[0][1]=ok2[3][1]=true;
    ok2[3][2]=ok2[0][2]=true;
    ok2[2][3]=ok2[1][3]=true;
    if(n==3){
        vector<vector<int>> dp(8,vector<int>(m,inf));//dp[mask][j];
        for(int i=0;i<m;i++){
            if(i-1<0){
                for(int mask=0;mask<8;mask++){
                    dp[mask][i] = setbits(v[i]^mask);
                }
                continue;
            }
            for(int mask1 = 0;mask1<8;mask1++){
                for(int mask2 = 0;mask2<8;mask2++){
                    if(!ok3[mask2][mask1]) continue;
                    dp[mask1][i]=min(dp[mask1][i],dp[mask2][i-1]+setbits(mask1^v[i]));
                }
            }
        }
        int ans = inf;
        for(int i=0;i<8;i++){
            ans=min(ans,dp[i][m-1]);
        }
        cout<<ans<<endl;
    }
    else{
        vector<vector<int>> dp(4,vector<int>(m,inf));//dp[mask][j];
        for(int i=0;i<m;i++){
            if(i-1<0){
                for(int mask=0;mask<4;mask++){
                    dp[mask][i] = setbits(v[i]^mask);
                }
                continue;
            }
            for(int mask1 = 0;mask1<4;mask1++){
                for(int mask2 = 0;mask2<4;mask2++){
                    if(!ok2[mask2][mask1]) continue;
                    dp[mask1][i]=min(dp[mask1][i],dp[mask2][i-1]+setbits(mask1^v[i]));
                }
            }
        }
        int ans = inf;
        for(int i=0;i<4;i++){
            ans=min(ans,dp[i][m-1]);
        }
        cout<<ans<<endl;
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

