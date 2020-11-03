class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n==0) return 0;
        int i = 0;
        vector<int> v=height;
        int left_max[n], right_max[n];
        left_max[0]=v[0];
        right_max[n-1]=v[n-1];
        for(int i=1;i<n;i++){
            left_max[i]=max(v[i],left_max[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            right_max[i]=max(v[i],right_max[i+1]);
        }
        while(i<n){
            int left = height[i];
            int j=i+1;
            bool f = false;
            if(j<n){
                if(right_max[j]>=left){
                    f=true;
                    while(j<n){
                        if(height[j]>=left){
                            break;
                        }
                        j++;
                    }
                }
            }
            if(f==false){
                i++;
                continue;
            }
            for(int k=i+1;k<j;k++){
                v[k]=max(v[k],left);
            }
            i=j;
        }
        
        i=n-1;
        
        while(i>=0){
            int right = height[i];
            int j=i-1;
            bool f = false;
            if(j>=0){
                if(left_max[j]>=right){
                    f=true;
                    while(j>=0){
                        if(height[j]>=right){
                            break;
                        }
                        j--;
                    }
                }
            }
            if(f==false){
                i--;
                continue;
            }
            for(int k=i-1;k>j;k--){
                v[k]=max(v[k],right);
            }
            i=j;
        }
        
        int ans = 0;
        for(int i=0;i<n;i++){
            ans+=(v[i]-height[i]);
        }
        return ans;
    }
};