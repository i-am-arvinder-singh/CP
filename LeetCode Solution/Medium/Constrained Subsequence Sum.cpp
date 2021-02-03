const int inf = 1e9;
#define LEFT(i) 2*i+1
#define RIGHT(i) 2*i+2

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

    int init(int segStart, int segEnd, int segId){
        if(segStart==segEnd){
            seg[segId] = v[segStart];
            return seg[segId]; 
        }
        int mid = getMid(segStart,segEnd);
        seg[segId] = max(init(segStart,mid,LEFT(segId)),init(mid+1,segEnd,RIGHT(segId)));
        return seg[segId];
    }

    void Update(int segStart, int segEnd, int segId, int id, int value){
        if(id < segStart || segEnd < id) return;
        if(id <= segStart && segEnd <= id){
            seg[segId] = value;
            return;
        }
        int mid = getMid(segStart,segEnd);
        Update(segStart,mid,LEFT(segId),id,value);
        Update(mid+1,segEnd,RIGHT(segId),id,value);
        seg[segId] = max(seg[LEFT(segId)] , seg[RIGHT(segId)]);
    }

    int query(int segStart, int segEnd, int segId, int qStart, int qEnd){
        if(qEnd < segStart || segEnd < qStart) return -inf;
        if(qStart <= segStart && segEnd <= qEnd){
            if(segStart==segEnd) return seg[segId];
            return seg[segId];
        }
        int mid = getMid(segStart,segEnd);
        return max(query(segStart,mid,LEFT(segId),qStart,qEnd),query(mid+1,segEnd,RIGHT(segId),qStart,qEnd));
    }
};




class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        segTree seg(n,nums);
        seg.init(0,n-1,0);
        int ans = 0;
        for(int i=0;i<n;i++){
            if(k>0 && i-1>=0){
                int val =seg.query(0,n-1,0,max(0,i-1-(k-1)),i-1);
                // cout<<val<<endl;
                int newVal = val+nums[i];
                newVal = max(newVal,nums[i]);
                seg.Update(0,n-1,0,i,newVal);
            }
        }
        return seg.query(0,n-1,0,0,n-1);
    }
};



