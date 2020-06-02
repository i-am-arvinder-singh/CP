#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;//which means policy based DS

#define endl            "\n"
//#define int             long long
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

ini MAX = 1e5 +5;

struct Query
{
    int l, r, idx;
};

Query qcopy[MAX];

bool cmp(Query x, Query y)
{
    return x.r < y.r;
}

void update(int idx, int val, int bit[], int n)
{
    for (; idx <= n; idx += idx&-idx)
        bit[idx] += val;
}

int query(int idx, int bit[], int n)
{
    int sum = 0;
    for (; idx>0; idx-=idx&-idx)
        sum += bit[idx];
    return sum;
}

void answeringQueries(int arr[], int n, Query queries[], int q)
{
    int bit[n+1];
    memset(bit, 0, sizeof(bit));
    int last_visit[MAX];
    memset(last_visit, -1, sizeof(last_visit));
    int ans[q];
    int query_counter = 0;
    for (int i=0; i<n; i++)
    {
        if (last_visit[arr[i]] !=-1)
            update (last_visit[arr[i]] + 1, -1, bit, n);
        last_visit[arr[i]] = i;
        update(i + 1, 1, bit, n);
        while (query_counter < q && queries[query_counter].r == i)
        {
            ans[queries[query_counter].idx] =
                     query(queries[query_counter].r + 1, bit, n)-
                     query(queries[query_counter].l, bit, n);
            query_counter++;
        }
    }
    for (int i=0; i<q; i++){
        int l = qcopy[i].l ,r = qcopy[i].r;
        int len = r-l+1;
//        cout<<" **** "<<arr[l]<< "  "<<arr[r]<<endl;
        if(len==1) cout<<"Yes"<<endl;
        else if(arr[l]!=arr[r]) cout<<"Yes"<<endl;
        else if(ans[i]>=3) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
//        cout<<ans[i]<<endl;
    }
}

void solve()
{
    string s;
    cin>>s;
    int n=s.length();
    int arr[n];
    fl(i,0,n){
        arr[i]=s[i]-'a'+1;
    }
    int q;
    cin>>q;
    Query queries[q];
    fl(i,0,q){
        cin>>queries[i].l>>queries[i].r;
        queries[i].l--;
        queries[i].r--;
        qcopy[i].l=queries[i].l;
        qcopy[i].r=queries[i].r;
        queries[i].idx=i;
    }
    sort(queries, queries+q, cmp);
    answeringQueries(arr, n, queries, q);
}

int32_t main()
{
	omniphantom
    solve();
	return 0;
}
