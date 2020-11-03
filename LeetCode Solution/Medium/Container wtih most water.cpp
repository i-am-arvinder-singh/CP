class Solution {
public:
    
    int f(vector<int>&h, int i, int j){
        int left = h[i];
        int right = h[j];
        if(i==j) return 0;
        if(left<right)
            return max({(j-i)*min(left,right),f(h,i+1,j)});
        else{
            return max({(j-i)*min(left,right),f(h,i,j-1)});
        }
    }
    
    int maxArea(vector<int>& height) {
        int n = height.size();
        return f(height,0,n-1);
    }
};