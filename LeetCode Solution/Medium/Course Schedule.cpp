#define pb push_back

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<vector<int>> edges(numCourses+2);
        vector<int> inDegree(numCourses+2,0);
        for(auto &vec:prerequisites){
            edges[vec[1]].pb(vec[0]);
            inDegree[vec[0]]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++) if(inDegree[i]==0) q.push(i);
        int ans = 0;
        while(!q.empty()){
            ans++;
            int node = q.front();
            q.pop();
            for(auto child:edges[node]){
                inDegree[child]--;
                if(inDegree[child]==0) q.push(child);
            }
        }
        return ans==numCourses;
    }
};



