class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        int i = 0;
        stack<int> s;
        int ans = 0;
        while(i<n){
            if(s.empty()|| h[i]>=h[s.top()]) s.push(i++);
            else{
                int val = s.top();
                s.pop();
                ans=max(ans,h[val]*(s.empty()?i:(i-s.top()-1)));
            }
        }
        while(!s.empty()){
            int val = s.top();
            s.pop();
            ans=max(ans,h[val]*(s.empty()?i:(i-s.top()-1)));
        }
        return ans;
    }
};