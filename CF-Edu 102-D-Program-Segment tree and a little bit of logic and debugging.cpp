#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
// using namespace __gnu_pbds;

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

/////// \|/ \|/ Credits: okwedook for template below \|/ \|/ ////////
template<class T, class U> inline void checkmin(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void checkmax(T &x, U y) { if (y > x) x = y; }
template<class T, class U> inline bool ifmax(T &x, U y) { if (y > x) return x = y, true; return false; }
template<class T, class U> inline bool ifmin(T &x, U y) { if (y < x) return x = y, true; return false; }
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T, class U> inline istream& operator>>(istream& str, pair<T, U> &p) { return str >> p.ff >> p.ss; }
template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }
/////////////////////////////////////////////////////////////////////


class segTree{
private:
    int n;  
    vector<int> seg; 
    vector<int> v;
    int getMid(int x, int y){
        return x+(y-x)/2;
    }
public: 
    segTree(int n, vector<int> &v) : n(n), seg(4*n+1), v(v) {}

    int init(int segStart, int segEnd, int segId)
    {
        if(segStart==segEnd){
            seg[segId] = v[segStart];
            return seg[segId]; 
        }
        int mid = getMid(segStart,segEnd);
        seg[segId] = init(segStart,mid,LEFT(segId)) + init(mid+1,segEnd,RIGHT(segId));
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
        return query(segStart,mid,LEFT(segId),qStart,qEnd) + query(mid+1,segEnd,RIGHT(segId),qStart,qEnd);
    }
};


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
        if(qEnd < segStart || segEnd < qStart) return -inf;
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
	int n,m;
	read(n,m);
	string s;
	cin>>s;
	vector<pii> v;
	vector<int> segVec(n);
	for(int i=0;i<m;i++){
		int x,y;
		read(x,y);
		x--,y--;
		v.pb({x,y});
	}
	int cnt = 0;
	vector<int> track(n);
	for(int i=0;i<n;i++){
		if(s[i]=='+') cnt++,segVec[i]=1;
		else cnt--,segVec[i]=-1;
		track[i] = cnt;
	}
	segTree seg(n,segVec);
	seg.init(0,n-1,0);
	cnt = 0;
	segTreeMax smax(n,track);
	smax.init(0,n-1,0);
	segTreeMin smin(n,track);
	smin.init(0,n-1,0);
	std::function<pii(pii,pii)> findIntersection = [&](pii p1,pii p2){
		if(p1.ff>p2.ff) swap(p1,p2);
		int right = min(p1.ss,p2.ss);
		int left = max(p1.ff,p2.ff);
		if(left>right) return pii{-inf,-inf};
		else return pii{left,right};
	};
	for(auto &[x,y]:v){
		int sum = seg.query(0,n-1,0,x,y);
		if(0<x && y<n-1){
			int rightMx = smax.query(0,n-1,0,y+1,n-1)-sum;
			int rightMn = smin.query(0,n-1,0,y+1,n-1)-sum;
			int leftMx = smax.query(0,n-1,0,0,x-1);
			leftMx = max(leftMx,0ll);
			int leftMn = smin.query(0,n-1,0,0,x-1);
			leftMn = min(leftMn,0ll);
			auto p = findIntersection({leftMn,leftMx},{rightMn,rightMx});
			if(p==pair<int,int>(-inf,-inf)) cout<<rightMx-rightMn+1+leftMx-leftMn+1<<endl;
			else{
				int val = max({rightMx,leftMx}) - min({rightMn,leftMn}) + 1;
				cout<<val<<endl;
			}
		}
		else if(0<x){
			int leftMx = smax.query(0,n-1,0,0,x-1);
			leftMx = max(leftMx,0ll);
			int leftMn = smin.query(0,n-1,0,0,x-1);
			leftMn = min(leftMn,0ll);
			cout<<leftMx - leftMn + 1<<endl;
		}
		else if(y<n-1){
			int rightMx = smax.query(0,n-1,0,y+1,n-1)-sum;
			int rightMn = smin.query(0,n-1,0,y+1,n-1)-sum;
			int add = 1;
			if(rightMx<0 || 0<rightMn) add++;
			cout<<rightMx - rightMn + add<<endl;
		}
		else cout<<1<<endl;
	}
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