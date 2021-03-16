#define ff first
#define ss second

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int prime_cnt = primes.size();
        vector<int> cnt(prime_cnt);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> minHeap;
        for(int i=0;i<prime_cnt;i++) minHeap.push({primes[i],i});
        vector<int> ans;
        ans.push_back(1);
        unordered_map<int,int> s;
        while((int)ans.size()<n){
            pair<int,int> cur = minHeap.top();
            minHeap.pop();
            if(s[cur.ff]==0){
                s[cur.ff]=1;
                ans.push_back(cur.ff);
            }
            cnt[cur.ss]++;
            minHeap.push({ans[cnt[cur.ss]]*primes[cur.ss],cur.ss});
        }
        return ans.back();
    }
};