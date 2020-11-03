#include<bits/stdc++.h>
#define LEFT(n) (2*n)
#define RIGHT(n) (2*n+1)
#define PARENT(n) (n/2)
using namespace std;

int rangeQuery(int n,vector<int> &seg_tree, vector<int> &lazy, int ql, int qr,int low, int high)
    {
        if(low>high)//Unreal
            return INT_MAX;
        
        if(!lazy[n])
        {
            seg_tree[n] += lazy[n];
            if(low!=high)
            {
                lazy[LEFT(n)] += lazy[n];
                lazy[RIGHT(n)] += lazy[n];
            }
            lazy[n] = 0;
        }
        
        if(qr<left && right<ql)
            return INT_MAX;
        
        if(low<=ql && qr<=high)//WRONG
            return seg_tree[n];
        
        int mid = (low+high)>>1;
        return min(rangeQuery(LEFT(n),seg_tree,lazy,ql,qr,low,mid),rangeQuery(RIGHT(n),seg_tree,lazy,ql,qr,mid+1,high));
    }

void updateSegmentTree(int n,vector<int> &seg_tree, vector<int> &lazy, int ql, int qr,int low, int high,int value)
    {
        if(low>high)
            return;
        
        if(!lazy[n])
        {
            seg_tree[n]+=lazy[n];
            if(low!=high)
            {
                lazy[LEFT(n)]+=lazy[n];
                lazy[RIGHT(n)]+=lazy[n];
            }
            lazy[n]=0;
        }
        
        if(qr<left || right<ql)
            return;
        
        if(left<=ql && qr<=right)//CHECK
        {
            seg_tree[n] += value;
            if(low!=high)
            {
                lazy[LEFT(n)] += value;
                lazy[RIGHT(n)] += value;
            }
            return;
        }
        
        int mid = (low+high)>>1;
        updateSegmentTree(LEFT(n),seg_tree,lazy,ql,qr,low,mid,value);
        updateSegmentTree(RIGHT(n),seg_tree,lazy,ql,qr,mid+1,high,value);
        seg_tree[n]=min(seg_tree[LEFT(n)],seg_tree[RIGHT(n)]);
    }

int range_min_query(int n,vector<int> &seg_tree, int ql, int qr,int low, int high)
    {
    if(qr<low || ql>high)
        return INT_MAX;
     if(ql<=low && qr>=high)
        return seg_tree[n];
     int mid = (low+high)>>1;
     return min(range_min_query(LEFT(n),seg_tree,ql,qr,low,mid),range_min_query(RIGHT(n),seg_tree,ql,qr,mid+1,high));
    }

void build_tree(int n,vector<int> &seg_tree, vector<int> v,int low, int high)
    {
        if(low==high){
            seg_tree[n]=v[low];
//            cout<<n<<" "<<seg_tree[n]<<" "<<v[low]<<endl;
            return;
        }
        int mid;
        mid=(low+high)>>1;
        build_tree(LEFT(n),seg_tree,v,low,mid);
        build_tree(RIGHT(n),seg_tree,v,mid+1,high);
        seg_tree[n]=min(seg_tree[LEFT(n)],seg_tree[RIGHT(n)]);
    }
int main()
    {
        int n,t,i=0;
        cin>>n;
        while(n>>i)
            i++;
        vector<int> v(n+1), seg_tree(2*(i+1),INT_MAX), lazy(2*(i+1),0);
        for(i=1;i<=n;i++)
            cin>>v[i];
        build_tree(1,seg_tree,v,1,n);
        for(i=1;i<seg_tree.size();i++)
            cout<<seg_tree[i]<<endl;
        cout<<endl<<endl;
        cout<<range_min_query(1,seg_tree,2,3,1,n)<<endl;
        cout<<range_min_query(1,seg_tree,1,2,1,n)<<endl;
        cout<<range_min_query(1,seg_tree,2,4,1,n)<<endl;
        return 0;
    }
