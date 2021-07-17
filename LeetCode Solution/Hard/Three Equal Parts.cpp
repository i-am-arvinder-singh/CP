class Solution {
public:
    
    
    
    vector<int> threeEqualParts(vector<int>& arr_) {
        
        
        int i = 0;
        int w = arr_.size();
        int cnt_zeros_start = 0;
        while(i<w && arr_[i]==0){
            cnt_zeros_start++;
            i++;
        }
        if(i==w){
            vector<int> temp = {0,w-1};
            return temp;
        }
        vector<int> arr;
        for(int j=i;j<w;j++)
            arr.push_back(arr_[j]);
        
        int n = arr.size();
        
        std::function<vector<int>(vector<int>&)> z_function = [&](vector<int> &v){
            int n = v.size();
            vector<int> z(n);
            for (int i = 1, l = 0, r = 0; i < n; ++i) {
                if (i <= r)
                    z[i] = min (r - i + 1, z[i - l]);
                while (i + z[i] < n && v[z[i]] == v[i + z[i]])
                    ++z[i];
                if (i + z[i] - 1 > r)
                    l = i, r = i + z[i] - 1;
            }
            return z;
        };
        
        map<int,set<int>> my;
        vector<int> z = z_function(arr);
        
        for(int i=0;i<n;i++){
            if(z[i]==0)
                continue;
            my[z[i]].insert(i);
        }
        
        
        vector<int> cnt_ones(n);
        for(int i=0;i<n;i++){
            if(i-1>=0)
                cnt_ones[i]=cnt_ones[i-1]+arr[i];
            else
                cnt_ones[i]=arr[i];
        }
        
        std::function<bool(int,int)> isOne = [&](int left, int right){
            if(right<left)
                return false;
            int cnt = cnt_ones[right] - (left-1>=0?cnt_ones[left-1]:0);
            return cnt>0?true:false;
        };
        
        i = 0;
        int j = n-1;
        while(i<j){
            if(my[z[j]].size()==0){
                i++;
                j--;
                continue;
            }
            my[z[j]].erase(my[z[j]].find(j));
            if(my[z[j]].size()==0){
                my.erase(z[j]);
            }
            if(z[i]>0){
                my[z[i]].erase(my[z[i]].find(i));
                if(my[z[i]].size()==0){
                    my.erase(z[i]);
                }
            }
            int len = n - j;
            if(z[j]==len){
                if(my.size()==0){
                    i++;
                    j--;
                    continue;
                }
                auto it = prev(my.end());
                if(it==my.end()){
                    i++;
                    j--;
                    continue;
                }
                int len_ = it->first;
                if(!my[len_].size() ){
                    i++;
                    j--;
                    continue;
                }
                int s_l = 0, s_r = len - 1;
                int e_l = j, e_r = n-1;
                if(!(s_r<e_l)){
                    i++;
                    j--;
                    continue;
                }
                int mid_l = *my[len_].begin();
                int mid_r = mid_l + len - 1;
                if(!(mid_r<e_l)){
                    i++;
                    j--;
                    continue;
                }
                int cnt_ones_rhs = isOne(mid_r+1,e_l-1);
                int cnt_ones_lhs = isOne(s_r+1,mid_l-1);
                if(cnt_ones_rhs || cnt_ones_lhs){
                    i++;
                    j--;
                    continue;
                }
                int a = i;
                int b = mid_r+1;
                vector<int> ans = {cnt_zeros_start+a,cnt_zeros_start+b};
                return ans;
            }
            i++;
            j--;
        }
        vector<int> ans = {-1,-1};
        return ans;
    }
};



