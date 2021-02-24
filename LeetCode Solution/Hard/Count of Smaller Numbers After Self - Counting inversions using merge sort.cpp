// class Solution {
// public:
//     vector<int> countSmaller(vector<int>& nums) {
//         // int n = nums.size();
//         unordered_map<int,int> my;
        
//         // reverse(nums.begin(),nums.end());
        
//         std::function<vector<int>(vector<int>&,vector<int>&)> merge = [&](vector<int> &a, vector<int> &b) {
//             // swap(a,b);
//             int n = a.size();
//             int m = b.size();
//             int i = 0, j = 0;
//             vector<int> res;
//             cout<<"###### "<<endl;
//             for(auto ele:a) cout<<ele<<" ";
//             cout<<endl<<"###### "<<endl;
//             cout<<"$$$$$$ "<<endl;
//             for(auto ele:b) cout<<ele<<" ";
//             cout<<endl<<"$$$$$$ "<<endl;
//             vector<int> a_;
//             for(int i=0;i<n;i++) {
//                 a_.push_back(nums[a[i]]);
//             }
//             while(i<n && j<m) {
//                 int val_i = nums[a[i]], val_j = nums[b[j]];
//                 if(val_i<val_j) {
//                     res.push_back(a[i]);
//                     i++;
//                 } else if(val_i==val_j) {
//                     auto it = upper_bound(a_.begin(),a_.end(),val_i);
//                     int cnt = a_.end() - it;
//                     res.push_back(b[j]);
//                     my[b[j]]+=cnt;
//                     j++;
//                 } else if(val_i>val_j) {
//                     res.push_back(b[j]);
//                     my[b[j]]+=(n-i);
//                     j++;
//                 }
//             }
//             if(i<n) {
//                 while(i<n) {
//                     res.push_back(a[i]);
//                     i++;
//                 }
//             } else if(j<m) {
//                 while(j<m) {
//                     res.push_back(b[j]);
//                     j++;
//                 }
//             }
//             cout<<"******* "<<endl;
//             for(auto ele:res) cout<<ele<<" ";
//             cout<<endl<<"******* "<<endl;
//             return res;
//         };
        
//         std::function<vector<int>(int,int)> merge_sort = [&](int left, int right) {
//             vector<int> v;
//             if(left==right){
//                 v.push_back(left);
//                 return v;
//             }
//             int mid = left + (right-left)/2;
//             vector<int> a = merge_sort(left,mid);
//             vector<int> b = merge_sort(mid+1,right);
//             v = merge(a,b);
//             return v;
//         };
        
         
        
//         merge_sort(0,(int)nums.size()-1);
//         vector<int> ans(nums.size());
//         for(int i=0;i<nums.size();i++) {
//             ans[i]=my[i];
//         }
//         return ans;
        
//     }
// };





class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        // int n = nums.size();
        unordered_map<int,int> my;
        
        // reverse(nums.begin(),nums.end());
        
        std::function<vector<int>(vector<int>&,vector<int>&)> merge = [&](vector<int> &a, vector<int> &b) {
            int n = a.size();
            int m = b.size();
            int i = 0, j = 0;
            vector<int> res;
            vector<int> b_;
            for(int i=0;i<m;i++) {
                b_.push_back(nums[b[i]]);
            }
            while(i<n && j<m) {
                int val_i = nums[a[i]], val_j = nums[b[j]];
                if(val_i>val_j) {
                    res.push_back(a[i]);
                    my[a[i]]+=(m-j);
                    i++;
                } else if(val_i==val_j) {
                    auto it = upper_bound(b_.rbegin(),b_.rend(),val_j-1);
                    int cnt = it - b_.rbegin();
                    res.push_back(a[i]);
                    my[a[i]]+=cnt;
                    i++;
                } else if(val_i<val_j) {
                    res.push_back(b[j]);
                    j++;
                }
            }
            if(i<n) {
                while(i<n) {
                    res.push_back(a[i]);
                    i++;
                }
            } else if(j<m) {
                while(j<m) {
                    res.push_back(b[j]);
                    j++;
                }
            }
            return res;
        };
        
        std::function<vector<int>(int,int)> merge_sort = [&](int left, int right) {
            vector<int> v;
            if(left==right){
                v.push_back(left);
                return v;
            }
            int mid = left + (right-left)/2;
            vector<int> a = merge_sort(left,mid);
            vector<int> b = merge_sort(mid+1,right);
            v = merge(a,b);
            return v;
        };
        
         
        
        merge_sort(0,(int)nums.size()-1);
        vector<int> ans(nums.size());
        for(int i=0;i<nums.size();i++) {
            ans[i]=my[i];
        }
        return ans;
        
    }
};