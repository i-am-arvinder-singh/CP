class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int sum = 0;
        int n = weights.size();
        int mx = 0;
        for(auto x:weights) sum+= x;
        int l = sum/D;
        int r = sum;
        vector<int> pref(n);
        pref[0]=weights[0];
        for(int i=1;i<n;i++) pref[i]=pref[i-1]+weights[i];
        int mid;
        int ans ;
        while(l<=r){
            mid = (l+r)>>1;
            if(f(pref,mid,D,n)) {
                r=mid-1;
                ans = mid;//****
            }
            else l=mid+1;
        }
        return ans;
    }
    
    bool f(vector<int> &pref,int mid, int D, int n){
        int j=-1;
        bool f=false;
        int cnt = 0;
        int i;
        for(i=0;i<n;i++){
            if(!f && pref[i]<=mid){
                continue;
            }
            else if(!f){
                j=i-1;
                if(pref[0]>mid) return false;//****
                i--;//****
                f=true;
                cnt++;
                continue;
            }
            if(pref[i]-pref[j]<=mid) {
                continue;
            }
            else{
                cnt++;
                j=i-1;
                if(pref[i]-pref[i-1]>mid) return false;//****
                i--;//****
            }
        }
        if(j!=i) cnt++;//****
        return cnt<=D;
    }
};