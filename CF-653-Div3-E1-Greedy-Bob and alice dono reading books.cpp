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
#define ppii            pair<int,pii>

const double pi = acos(-1.0);

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve()
{
    int n,k,cnta=0,cntb=0;
    cin>>n>>k;
    multiset<int> a,b,d;
    fl(i,0,n){
        int t,a_,b_;
        cin>>t>>a_>>b_;
        if(a_&&b_) d.insert(t);
        else if(a_) a.insert(t);
        else if(b_) b.insert(t);
        a_?cnta++:0;
        b_?cntb++:0;
    }
    if(cnta<k||cntb<k){
        cout<<-1<<endl;
        return;
    }
    int a_=k,b_=k;
    auto ita = a.begin();
    auto itb = b.begin();
    auto itd = d.begin();
    int ans = 0;
    while(a_>0||b_>0){
        if(a_>0 && b_>0){
            if(ita==a.end() || itb==b.end()){//No choice except to choose answer from both the set
                ans+= *itd;
                itd++;
                a_--;
                b_--;
            }
            else{
                if(*ita + *itb < *itd){
                    ans+= (*ita+*itb);
                    ita++;
                    itb++;
                    a_--;
                    b_--;
                }
                else{
                    ans+= *itd;
                    itd++;
                    a_--;
                    b_--;
                }
            }
        }
        else if(a_>0){
            if(itd==d.end()){
                ans+= *ita;
                ita++;
                a_--;
            }
            else if(ita==a.end()){
                ans+= *itd;
                itd++;
                a_--;
            }
            else{
                if(*ita<*itd){
                    ans+= *ita;
                    ita++;
                    a_--;
                }
                else{
                    ans+= *itd;
                    itd++;
                    a_--;
                }
            }
        }
        else{
            if(itd==d.end()){
                ans+= *itb;
                itb++;
                b_--;
            }
            else if(ita==b.end()){
                ans+= *itd;
                itd++;
                b_--;
            }
            else{
                if(*itb<*itd){
                    ans+= *itb;
                    itb++;
                    b_--;
                }
                else{
                    ans+= *itd;
                    itd++;
                    b_--;
                }
            }
        }
    }
    cout<<ans<<endl;
}

int32_t main()
{
	omniphantom
    solve();
	return 0;
}
