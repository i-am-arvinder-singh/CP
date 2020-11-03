#include<bits/stdc++.h>
using namespace std;

#define endl            "\n"
#define ff              first
#define int             long long
#define ss              second
#define fl(i,a,b)       for(int i=a; i<b; i++)
#define bfl(i,a,b)      for(int i=a-1; i>=b; i--)
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define vt(type)        vector<type>
#define fio          ios_base::sync_with_stdio(false);   cin.tie(NULL); cout.tie(NULL);
#define mii             map<int,int>
#define pqb             priority_queue<int>
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
#define LEFT(n) (2*n)dfs
#define RIGHT(n) (2*n+1)
#define PARENT(n) (n/2)

int32_t main()
{
	fio;
	int n,k;
	string s;
	cin>>n>>k>>s;
	int len=0;
	vt(vi) store;
	while(1){
            store.pb({});
            for(int i=0;i+1<n;i++){
                if(s[i]=='R'&&s[i+1]=='L'){
                    store.back().pb(i);
                    len++;
                }
            }
            for(auto i: store.back()){
                swap(s[i],s[i+1]);
            }
            if(store.back().empty()){
                store.pop_back();
                break;
            }
        }

	if(k<store.size() || k>len){
        cout<<-1<<endl;
        return 0;
	}

	for(int i=0;i<store.size();i++){
        while(store[i].size()>1 && k>store.size()){
            k--;
            cout<<"1 "<<store[i].back()+1<<endl;
            store[i].pop_back();
        }
        cout<<store[i].size();
        for(auto j :store[i])
            cout<<" "<<j+1;
        cout<<endl;
	}
	return 0;
}
