#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;//which means policy based DS

#define endl            "\n"
//#define int             long long
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

class KMP
{
private:
    string pattern;
    vi lps;
    int n;
public:
    KMP(string pattern)
        : pattern(pattern)
    {
        n = pattern.length();
        lps.resize(n);
    }
    int find_lps()
    {
        int id = 0;
        lps[0]=0;
        for(int i=1;i<n;){//n->pattern length
            if(pattern[i]==pattern[id]){
                lps[i]=id+1;
                id++;
                i++;
            }
            else{
                if(id!=0){
                    id = lps[id-1];
                }
                else{
                    lps[i]=0;
                    i++;
                }
            }
        }
        return lps[n-1];
    }
};



void solve()
{
    int n;
    cin>>n;
    string ans,w,temp;
    for(int i=0;i<n;i++){
        cin>>w;
        if(ans.size()<=w.size()){
            temp = w + '#' + ans;
        }
        else{
            temp = w + '#' + ans.substr(ans.size()-w.size(),w.size());
        }
        KMP K(temp);
        int id = K.find_lps();
        ans+=w.substr(id,w.size()-id);
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
