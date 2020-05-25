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
#define LEFT(n) (2*n)
#define RIGHT(n) (2*n+1)
#define PARENT(n) (n/2)

ini mx = 2e5+5;
int tracker[mx][2],cnt=0;//0->start index 1->end index
bool visited[mx];
vi toggle(4*mx),toggle__(4*mx),cust(mx);
vt(vi) edges(mx);

//////////////////////SEGMENT//////////

void propagate(int n,vector<int> &seg_tree, vector<int> &lazy, int ql, int qh, int low, int high)
{
    lazy[n]%=2;

        if(lazy[n])
        {
            seg_tree[n] = high-low+1-seg_tree[n];
            if(low!=high)
            {
                lazy[LEFT(n)] ++;
                lazy[RIGHT(n)] ++;
            }
            lazy[n] = 0;
        }
}

int rangeQuery(int n,vector<int> &seg_tree, vector<int> &lazy, int ql, int qh,int low, int high)
    {


        propagate(n,seg_tree,lazy,ql,qh,low,high);

        if(high<ql || qh<low)
            return 0;

        if(ql<=low && high<=qh)//WRONG
            return seg_tree[n];

        int mid = (low+high)>>1;
        return rangeQuery(LEFT(n),seg_tree,lazy,ql,qh,low,mid)+rangeQuery(RIGHT(n),seg_tree,lazy,ql,qh,mid+1,high);
    }

void updateSegmentTree(int n,vector<int> &seg_tree, vector<int> &lazy, int ql, int qh,int low, int high,int value)
    {

        propagate(n,seg_tree,lazy,ql,qh,low,high);

        if(high<ql || qh<low)
            return;

        if(ql<=low && high<=qh)//CHECK
        {
            seg_tree[n] = high-low+1-seg_tree[n];
            if(low!=high)
            {
                lazy[LEFT(n)] ++;
                lazy[RIGHT(n)] ++;
            }
            return;
        }

        int mid = (low+high)>>1;
        updateSegmentTree(LEFT(n),seg_tree,lazy,ql,qh,low,mid,value);
        updateSegmentTree(RIGHT(n),seg_tree,lazy,ql,qh,mid+1,high,value);
        seg_tree[n]=seg_tree[LEFT(n)]+seg_tree[RIGHT(n)];
    }

void build_tree(int n,vector<int> &seg_tree, vector<int> &v,int low, int high)
    {
        if(low==high){
            seg_tree[n]=v[low];
//            cout<<n<<" "<<seg_tree[n]<<" "<<v[low]<<endl;
            return;
        }
        int mid=(low+high)>>1;
        build_tree(LEFT(n),seg_tree,v,low,mid);
        build_tree(RIGHT(n),seg_tree,v,mid+1,high);
        seg_tree[n]=seg_tree[LEFT(n)]+seg_tree[RIGHT(n)];
    }


/////////////////////////////############


void dfs(int c_node)
{
    visited[c_node] = true;
    cnt++;
    toggle__[cnt] = toggle[c_node];
    cust[c_node] = cnt;
    tracker[c_node][0] = cnt;
    for(auto node: edges[c_node]){
        if(!visited[node]){
            dfs(node);
        }
    }
    tracker[c_node][1] = cnt;
}

int32_t main()
{
	fio;
	fl(i,0,mx) visited[i]=false;
	int t,n,a;
	cin>>n;
	fl(i,2,n+1){
	    cin>>a;
	    edges[i].pb(a);
	    edges[a].pb(i);
	}

	fl(i,1,n+1){
	    cin>>toggle[i];
	}
	dfs(1);
	cin>>t;
	string get="get",pow="pow";
//	cout<<endl;
//	fl(i,1,n+1){
//	    cout<<tracker[i][0]<<" "<<tracker[i][1]<<endl;
//	}
//	cout<<endl;
    int i=0;
    while(n>>i)
            i++;
    i=1<<i;
//    cout<<"i: "<<i<<endl;
    vi seg_tree(4*mx,0), lazy(4*mx,0);
    build_tree(1,seg_tree,toggle__,1,i);
//    cout<<endl;
//    fl(j,1,n+1) cout<<toggle__[j]<<" ";
//    cout<<endl;
//    cout<<endl;
//    fl(j,1,30) cout<<seg_tree[j]<<" ";
//    cout<<endl;
    while(t--){
        string str;
        int k;
        cin>>str>>k;
        if(str==get){
//            cout<<"QUERY:  "<<k<< " "<<k+tracker[k][1]-tracker[k][0]<<endl;
            cout<<rangeQuery(1,seg_tree,lazy,cust[k], cust[k]+tracker[k][1]-tracker[k][0], 1, i)<<endl;
        }
        else{
//            cout<<"UPDATE:   "<<k<<" "<<k+tracker[k][1]-tracker[k][0]<<endl;
            updateSegmentTree(1,seg_tree, lazy, cust[k], cust[k]+tracker[k][1]-tracker[k][0], 1, i,1);
        }
    }
	return 0;
}
