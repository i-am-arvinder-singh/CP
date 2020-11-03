class Solution {
public:
    int jump(vector<int>& v) {
        int n = v.size();
        int next = 0;
        int trigger = 0;
        int ans = 0;
        for(int i =0 ;i<n-1;i++){
            int next = max(next,i+v[i]);
            if(trigger==i){
                ans++;
                trigger=next;//next trigger
            }
        }
        return ans;
    }
};