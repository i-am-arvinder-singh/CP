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
#define tup             tuple<int,int,int>
#define LEFT(x)         2*x+1
#define RIGHT(x)        2*x+2

const double pi = acos(-1.0);

class Tarjan{
    int n;
    vector<int> disc,low;
    vector<bool> presentInStack;
    stack<int> myStack;
    unordered_map<int,vector<int>> my;
    vector<vector<int>> ans;
public:
    Tarjan(unordered_map<int,vector<int>> edges, int n){
        this->n = n;
        disc = vector<int> (n,-1);
        low  = vector<int> (n,-1);
        presentInStack = vector<bool> (n,false);
        this->my = edges;
    }

    vector<vector<int>> findSCC(){
        for(int i=0;i<n;i++){
            if(disc[i]==-1){
                dfs(i);
            }
        }
        return ans;
    }

    void dfs(int node){
        static int timer = 0;
        disc[node] = low[node] = timer++;
        myStack.push(node);
        presentInStack[node] = true;
        
        for(auto next : my[node]){
            if(disc[next]==-1){
                dfs(next);
                low[node] = min(low[node],low[next]);
            }
            else if(presentInStack[next]){
                low[node] = min(low[node],disc[next]);
            }
        }

        if(low[node]==disc[node]){
            vector<int> temp;
            while(myStack.top()!=node){
                temp.pb(myStack.top());
                presentInStack[myStack.top()] = false;
                myStack.pop();
            }
            temp.pb(myStack.top());
            presentInStack[myStack.top()] = false;
            myStack.pop();
            ans.pb(temp);
        }
    }
};

void solve()
{
    int n;
    cin>>n;
    string s;
	cin>>s;
    unordered_map<int,vector<int>> edges;

    for(int i=0;i<n;i++){
        if(s[i]=='-'){
            edges[i].pb((i+1)%n);
            edges[(i+1)%n].pb(i);
        }
        else if(s[i]=='>'){
            edges[i].pb((i+1)%n);
        }
        else if(s[i]=='<'){
            edges[(i+1)%n].pb(i);
        }
    }



    Tarjan T(edges,n);
    vector<vector<int>> ans = T.findSCC();
	int res = 0;
    for(auto vec:ans){
		if(vec.size()>1) res+=(int)vec.size();
    }
    cout<<res<<endl;
}

int32_t main()
{
	omniphantom
	#if 1
	w(t)
	#endif // 0
    solve();
	return 0;
}