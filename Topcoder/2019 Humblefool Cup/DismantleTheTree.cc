#include<bits/stdc++.h>
#define two(a) (1<<(a))
#define LINF (1ll<<61)
#define EPS (1e-14)
#define Lshift(a,b) (a<<b)
#define Rshift(a,b) (a>>b)
#define rep(a,b) for(a=0 ; a<b ; a++)
#define xrep(a,b,c) for(a=b ; a<c ; a++)
#define INF (1<<29)
#define swap(a,b) ( (a^=b) , (b^=a) , (a^=b) )
#define GET(x) (mark[x>>5]>>(x&31)&1)
#define SET(x) (mark[x>>5]|=1<<(x&31))
#define maxL (10000000>>5)+1
#define mod 1000000007
typedef long long ll;
using namespace std;

set<int> edge[1010];
int used[1010];
queue<int> que;
int degree[1011];
int nn;


void dfs(int x) {
    degree[x]--;
    if (edge[x].size()) {
        auto iter = edge[x].begin();
        int y = *iter;
        edge[y].erase(x);
        edge[x].erase(y);
        dfs(y);
    }
    if (edge[x].size() == 1) {
        que.push(x);
    }
}

int solve() {
    int i;
    xrep(i, 1, nn + 1) {
        // cout << edge[i].size() << endl;
        if (edge[i].size() == 1) {
            que.push(i);
        }
    }
    int res = 0;
    // cout << n << ' ' << que.empty() << endl;
    while (!que.empty()) {
        int x = que.front();
        que.pop();
        if (edge[x].size() == 0) { continue; }
        // cout << n << ' ' << x << endl;
        dfs(x);
        degree[x]--;
        res++;
    }
    return res;
}

class DismantleTheTree {
public:
    int dismantle(int n, vector <int> x, vector <int> y, vector <int> w) {
        vector<pair<int, pair<int, int> > > v;
        int i;
        nn = n;
        rep(i, n - 1) {
            v.push_back({w[i], {x[i], y[i]} });
        }
        sort(v.begin(), v.end());
        xrep(i, 1, n + 1) { edge[i].clear(); }
        int prev = -1;
        int now = 0;
        int ans(0);
        while (now < n - 1) {
            auto w = v[now];
            if (w.first != prev) {
                if (prev != -1) {
                    ans += solve() * prev;
                }
                prev = w.first;
                xrep(i, 1, n + 1) { edge[i].clear(); }
            }
            edge[w.second.first].insert(w.second.second);
            edge[w.second.second].insert(w.second.first);
            now++;
        }
        ans += solve() * prev;
        return ans;
    };
};
