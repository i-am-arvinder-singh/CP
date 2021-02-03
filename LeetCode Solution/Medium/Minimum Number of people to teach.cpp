#define pii pair<int,int>
#define all(v) v.begin(),v.end()
#define ff first
#define ss second
#define pb push_back

class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();
        vector<set<int>> langs(m);
        for(int i=0;i<m;i++){
            vector<int> &vec = languages[i];
            for(auto ele:vec) langs[i].insert(ele);
        }
        vector<set<int>> blue(m); //to connect
        set<int> bad_people;
        for(auto vec:friendships){
            bool check = false;
            int first = vec[0] - 1;
            int second = vec[1] - 1;
            for(auto ele:langs[first]){
                if(langs[second].count(ele)){
                    check = true;
                    break;
                }
            }
            if(!check){
                bad_people.insert(first);
                bad_people.insert(second);
            }
        }
        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            int needed=0;
            for(auto people:bad_people){
                if(!langs[people].count(i)) needed++;
            }
            ans=min(ans,needed);
        }
        return ans;
    }
};