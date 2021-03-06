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
#define you_can_do_it     ios_base::sync_with_stdio(false);   cin.tie(NULL); cout.tie(NULL);
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
#define LEFT(x)         2*x
#define RIGHT(x)        2*x+1
#define all(v)            v.begin(),v.end()
#define rall(v)            v.rbegin(),v.rend()

const double pi = acos(-1.0);

#define PRINT(x)        {print(x); return;}
#define FOR(v)            fl(i,0,(int)v.size())   read(v[i]);
#define FOR1(v)            fl(i,1,(int)v.size()+1) read(v[i]);

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); cout<<endl;}


//void err(istream_iterator<string> it) {}
//template<typename T, typename... Args>
//void err(istream_iterator<string> it, T a, Args... args) {
//    cerr << *it << " = " << a << "  , ";
//    err(++it, args...);
//}
//
//template<typename... T>
//void print(T...args){
//    ((cout<<args<<" "),...);
//}
//
//template<typename... T>
//void read(T&...args){
//    ((cin>>args),...);
//}

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

/*

Credits : owen_up

SOME BITMASK KNOWLEDGE
1)x & (x - 1):sets the last one bit of x to zero
power of two exactly when x & (x - 1) = 0.
2)x & -x:sets all the one bits to zero, except last one bit
3)x | (x - 1):inverts all the bits after the last one bit

*/


//1,2 ,3  ,4,  ,5     ,6      ,7       ,8        ,9         ,10 digit prime
//1,11,101,1187, 11489, 109229, 1000003, 10000019, 100000007, 1000000007
//1,13,127,1009, 10007, 100003, 1000033, 10000079, 100000037, 1000000009

class Node{
public:
    int sum,A,D;
    Node(){
        sum=A=D=0;
    }
    void reset(){
        A=D=0;
    }
};

class segTree{
    int N;
    vector<Node> tree;
public:
    segTree(int N) : N(N), tree(8*N+2) {}

    void propagate(int segId, int left, int right){
        int mid = left + (right - left)/2;
        if(tree[segId].A){
            int n = (right-left+1);
            tree[segId].sum+=(n*(2*tree[segId].A+(n-1)*tree[segId].D))/2;
            if(left!=right){
                tree[LEFT(segId)].A+=tree[segId].A;
                tree[LEFT(segId)].D+=tree[segId].D;
                tree[RIGHT(segId)].A+=tree[segId].A+(mid-left+1)*tree[segId].D;
                tree[RIGHT(segId)].D+=tree[segId].D;
            }
        }
        tree[segId].reset();
    }

    void update(int segStart, int segEnd, int qStart, int qEnd, int segId, int start_val){
        propagate(segId,segStart,segEnd);
        if(qStart>segEnd || qEnd<segStart || segStart>segEnd || qStart>qEnd) return;
        int mid = segStart + (segEnd - segStart)/2;
        if(qStart<=segStart && segEnd<=qEnd){
            int n = (segEnd-segStart+1);
            tree[segId].sum+=(n*(2*(segStart-qStart+start_val)+(n-1)))/2;
//            cout<<"******* "<<segId<<" "<<tree[segId].sum<<endl;
            if(qStart!=qEnd){
                assert(segId>0);
                tree[LEFT(segId)].A+=(segStart-qStart+start_val);
                tree[LEFT(segId)].D++;
                tree[RIGHT(segId)].A+=(mid-qStart+1+start_val);/////
                tree[RIGHT(segId)].D++;
            }
            return;
        }
        update(segStart,mid,qStart,qEnd,LEFT(segId),start_val);
        update(mid+1,segEnd,qStart,qEnd,RIGHT(segId),start_val);
        tree[segId].sum = tree[LEFT(segId)].sum + tree[RIGHT(segId)].sum;
//        cout<<"******* "<<segId<<" "<<tree[segId].sum<<endl;
    }

    int query(int segStart, int segEnd, int qStart, int qEnd, int segId){
        propagate(segId,segStart,segEnd);
        if(qStart>segEnd || qEnd<segStart || segStart>segEnd || qStart>qEnd) return 0;
        if(qStart<=segStart && segEnd<=qEnd) return tree[segId].sum;
        int mid = segStart + (segEnd-segStart)/2;
        return query(segStart,mid,qStart,qEnd,LEFT(segId)) +
                    query(mid+1,segEnd,qStart,qEnd,RIGHT(segId));
    }

};


void solve(int tc)
{
    int n,q;
    cin>>n>>q;
    int o_n=n,e_n=n;
//    if(n&1){
//        e_n=n;
//        o_n=n;
//    }
    segTree even(n+10),odd(n+10);


    for(int i=0;i<q;i++){
        int t;
        cin>>t;
        if(t == 1) {
            int x, y, k ; cin >> x >> y >> k ;

            if(x&1){
                odd.update(1,o_n,(x+1)/2,(x+1)/2+y-1,1,1);
                if(k&1){
                    odd.update(1,o_n,(x+2*y+k)/2,(n+1)/2,1,y+1);
                }
                else{
                    even.update(1,e_n,(x+2*y+k)/2, (n+1)/2,1, y+1) ;
                }
            }
            else{
                even.update(1,e_n,(x+1)/2,(x+1)/2+y-1,1,1);
                if(k&1){
                    even.update(1,e_n,(x+2*y+k)/2,(n+1)/2,1,y+1);
                }
                else{
                    odd.update(1,o_n,(x+2*y+k)/2, (n+1)/2,1, y+1) ;
                }
            }

//            update((x+1)/2, (x+1)/2+y-1, 1, x&1) ;
//             if(k&1) {
//                update((x+2*y+k)/2, (n+1)/2, y+1, x&1) ;
//            }
//            else {
//                update((x+2*y+k)/2, (n+1)/2, y+1, !(x&1)) ;
//            }
        }
        else {
            int l, r; cin >> l >> r ;
            cout << odd.query(1,o_n,(l+1)/2 + !(l&1), (r+1)/2,1) + even.query(1,e_n,(l+1)/2, r/2,1) << '\n' ;
        }
    }


//    even.update(0,e_n,0,e_n,0);
//    cout<<"### "<<e_n<<endl;
//    cout<<even.query(0,e_n,0,e_n,0);
//    for(int i=0;i<q;i++){
//        int t;
//        cin>>t;
//        if(t==1){
//            int x,y,k;
//            cin>>x>>y>>k;
//            x--;
//            if(x&1){
//                odd.update(0,o_n,(x-1)/2,(x-1)/2+y-1,0,1);
////                cout<<"# UPDATE ODD --> "<<(x-1)/2<<" "<<(x-1)/2+y-1<<endl;
//                if(k&1){
//                    int t = (k-1)/2+1;
//                    odd.update(0,o_n,(x-1)/2+y-1+t,o_n,0,y+1);
////                    cout<<"# UPDATE ODD --> "<<(x-1)/2+y-1+t<<" "<<o_n<<endl;
//                }
//                else{
//                    int t = (x-1)/2+y-1+k/2+1;
//                    even.update(0,e_n,t,e_n,0,y+1);
////                    cout<<"# UPDATE EVEN --> "<<t<<" "<<e_n<<endl;
//                }
//            }
//            else{
//                even.update(0,e_n,x/2,x/2+y-1,0,1);
////                cout<<"$ UPDATE EVEN --> "<<x/2<<" "<<x/2+y-1<<endl;
//                if(k&1){
//                    int t = (k-1)/2+1;
//                    even.update(0,e_n,x/2+y-1+t,e_n,0,y+1);
////                    cout<<"$ UPDATE EVEN --> "<<x/2+y-1+t<<" "<<e_n<<endl;
//                }
//                else{
//                    int t = x/2+y-1+k/2;
//                    odd.update(0,o_n,t,o_n,0,y+1);
////                    cout<<"$ UPDATE ODD --> "<<t<<" "<<o_n<<endl;
//                }
////                cout<<"############ "<<even.query(0,e_n,0,2,0)<<endl;
//            }
//        }
//        else{
//            int l,r;
//            cin>>l>>r;
//            l--,r--;
//            int dis = r-l+1;
//            if(dis&1){
//                if((l&1)==0){
//                    //e e e
//                    // o o
//                    cout<<even.query(0,e_n,l,l+(dis+1)/2-1,0)+odd.query(0,o_n,l,l+(dis+1)/2-2,0);
//                }
//                else{
//                    //o o o
//                    // e e
//                    cout<<odd.query(0,o_n,l,l+(dis+1)/2-1,0)+even.query(0,e_n,l,l+(dis+1)/2-2,0);
//                }
//            }
//            else{
//                //e e
//                // o o
//                cout<<even.query(0,e_n,l,l+dis/2-1,0)+odd.query(0,o_n,l,l+dis/2-1,0);
//            }
//            cout<<endl;
//        }
//    }
}

int32_t main()
{
    you_can_do_it
    int t=1;
//    cin>>t;
    for(int i=1;i<=t;i++){
        solve(i);
    }
    return 0;
}
