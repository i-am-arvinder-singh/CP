class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> ans(n,1);
        for(int i=0;i<n;i++){
            bool hasLeftNeighbor = false, hasRightNeighbor = false;
            if(i-1>=0){
                hasLeftNeighbor = true;
            }
            if(i+1<n){
                hasRightNeighbor = true;
            }
            if(hasLeftNeighbor && hasRightNeighbor){
                if(ratings[i]>ratings[i-1] && ratings[i]>ratings[i+1]){
                    ans[i]=max(ans[i-1],ans[i+1])+1;
                }
                else if(ratings[i]>ratings[i-1]){
                    ans[i]=1+ans[i-1];
                }
                else if(ratings[i]>ratings[i+1]){
                    ans[i]=1+ans[i+1];
                }
            }
            else if(hasLeftNeighbor){
                if(ratings[i]>ratings[i-1]){
                    ans[i]=1+ans[i-1];
                }
            }
            else if(hasRightNeighbor){
                if(ratings[i]>ratings[i+1]){
                    ans[i]=1+ans[i+1];
                }
            }
        }
        for(int i=n-1;i>=0;i--){
            bool hasLeftNeighbor = false, hasRightNeighbor = false;
            if(i-1>=0){
                hasLeftNeighbor = true;
            }
            if(i+1<n){
                hasRightNeighbor = true;
            }
            if(hasLeftNeighbor && hasRightNeighbor){
                if(ratings[i]>ratings[i-1] && ratings[i]>ratings[i+1]){
                    ans[i]=max(ans[i-1],ans[i+1])+1;
                }
                else if(ratings[i]>ratings[i-1]){
                    ans[i]=1+ans[i-1];
                }
                else if(ratings[i]>ratings[i+1]){
                    ans[i]=1+ans[i+1];
                }
            }
            else if(hasLeftNeighbor){
                if(ratings[i]>ratings[i-1]){
                    ans[i]=1+ans[i-1];
                }
                else ans[i]=1;
            }
            else if(hasRightNeighbor){
                if(ratings[i]>ratings[i+1]){
                    ans[i]=1+ans[i+1];
                }
            }
        }
        int res = 0;
        for(auto ele:ans) res+=ele;
        return res;
    }
};