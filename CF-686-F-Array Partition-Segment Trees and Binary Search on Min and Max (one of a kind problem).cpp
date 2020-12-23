#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;

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
#define mod             998244353  
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
#define all(v)			v.begin(),v.end()

const double pi = acos(-1.0); 

#define PRINT(x)		{print(x); return;}
#define FOR(v)			fl(i,0,(int)v.size())   read(v[i]);
#define FOR1(v)			fl(i,1,(int)v.size()+1) read(v[i]);

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); cout<<endl;}


void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << "  , ";
	err(++it, args...);
}

template<typename... T>
void print(T...args){
	((cout<<args<<" "),...);
}

template<typename... T>
void read(T&...args){
	((cin>>args),...);
}

class segTreeMax{
private:
    int n;  
    vector<int> seg; 
    vector<int> v;
    int getMid(int x, int y){
        return x+(y-x)/2;
    }
public: 
    segTreeMax(int n, vector<int> &v) : n(n), seg(4*n+1), v(v) {}

    int init(int segStart, int segEnd, int segId)
    {
        if(segStart==segEnd){
            seg[segId] = v[segStart];
            return seg[segId]; 
        }
        int mid = getMid(segStart,segEnd);
        seg[segId] = max(init(segStart,mid,LEFT(segId)),init(mid+1,segEnd,RIGHT(segId)));
        return seg[segId];
    }

    int query(int segStart, int segEnd, int segId, int qStart, int qEnd)
    {
        if(qEnd < segStart || segEnd < qStart) return 0;
        if(qStart <= segStart && segEnd <= qEnd){
            if(segStart==segEnd) return seg[segId];
            return seg[segId];
        }
        int mid = getMid(segStart,segEnd);
        return max(query(segStart,mid,LEFT(segId),qStart,qEnd),query(mid+1,segEnd,RIGHT(segId),qStart,qEnd));
    }
};

class segTreeMin{
private:
    int n;  
    vector<int> seg; 
    vector<int> v;
    int getMid(int x, int y){
        return x+(y-x)/2;
    }
public: 
    segTreeMin(int n, vector<int> &v) : n(n), seg(4*n+1), v(v) {}

    int init(int segStart, int segEnd, int segId)
    {
        if(segStart==segEnd){
            seg[segId] = v[segStart];
            return seg[segId]; 
        }
        int mid = getMid(segStart,segEnd);
        seg[segId] = min(init(segStart,mid,LEFT(segId)),init(mid+1,segEnd,RIGHT(segId)));
        return seg[segId];
    }

    int query(int segStart, int segEnd, int segId, int qStart, int qEnd)
    {
        if(qEnd < segStart || segEnd < qStart) return inf;
        if(qStart <= segStart && segEnd <= qEnd){
            if(segStart==segEnd) return seg[segId];
            return seg[segId];
        }
        int mid = getMid(segStart,segEnd);
        return min(query(segStart,mid,LEFT(segId),qStart,qEnd),query(mid+1,segEnd,RIGHT(segId),qStart,qEnd));
    }
};

void solve()
{
	int n;
	read(n);
	vector<int> v(n);
	map<int,vector<int>> my;
	for(int i=0;i<n;i++){
		cin>>v[i];
		my[v[i]].pb(i);
	}
	segTreeMax smax(n,v);
	smax.init(0,n-1,0);
	segTreeMin smin(n,v);
	smin.init(0,n-1,0);
	for(int i=0;i<n-2;i++){
		int val = smax.query(0,n-1,0,0,i);
		int left = i+1, right = n-1, flag = 0;
		while((right-left)>1){
			int mid = left+(right-left)/2;
			int mnFirst = smin.query(0,n-1,0,i+1,mid);
			int mxLast = smax.query(0,n-1,0,mid,n-1);
			if(val>=mnFirst && mxLast<=val) right = mid;
            else if(val<=mnFirst && mxLast>=val) left = mid;
            else{
                flag = 1;
                break;
            }
		}
        if(flag) continue;
        if(smin.query(0,n-1,0,i+1,left)!=val || smax.query(0,n-1,0,left+1,n-1)!=val) left++;
        if(smin.query(0,n-1,0,i+1,left)!=val || smax.query(0,n-1,0,left+1,n-1)!=val) continue;
        cout<<"YES"<<endl;
        cout<<i+1<<" "<<left-i<<" "<<n-(left+1)<<endl;
        return;
	}
	cout<<"NO"<<endl;
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