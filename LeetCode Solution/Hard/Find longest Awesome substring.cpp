class Solution {
public:
    int longestAwesome(string s) {
        int n = s.length();
        int cur = 0;
        unordered_map<int,int> my;
        my[0]=-1;
        int ans = 0;
        for(int i=0;i<n;i++){
            int shif = s[i]-'0';
            cur^=(1<<shif);
            if(my.find(cur)==my.end())
                my[cur]=i;
            int len = i - my[cur];
            if((len&1)==0){
                // cout<<i<<" "<<len<<endl;
                ans=max(ans,len);
            }   
            for(int j=0;j<10;j++){
                int cur_ = cur^(1<<j);
                if(my.find(cur_)==my.end()){
                    continue;
                }
                else{
                    int len = i - my[cur_];
                    if(len&1){
                        // cout<<i<<" "<<len<<endl;
                        ans=max(ans,len);
                    }
                }
            }
        }
        return ans;
    }
};




