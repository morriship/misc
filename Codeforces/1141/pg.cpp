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
#define vi vector<int>
#define pii pair<int, int>
#define mii map<int, int>
#define si set<int>
#define MID 2001
#define pb push_back
typedef long long ll;
using namespace std;

vector<pii> edge[200100];
vi deg;
int used[200010];
int ans[200010];


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, x, y, k, i;
    cin >> n >> k;
    rep(i, n - 1) {
        cin >> x >> y;
        edge[x].pb({y, i});
        edge[y].pb({x, i});
    }
    xrep(i, 1, n + 1) {
        deg.pb(edge[i].size());
    }
    sort(deg.begin(), deg.end());
    int r(deg[deg.size() - k - 1]);
    cout << r << endl;
    queue<pii> que;
    que.push({1, 0});
    while (!que.empty()) {
        pii x = que.front();
        que.pop();
        int node(x.first), color(x.second);
        used[node]++;
        for (auto y: edge[node]) {
            if (!used[y.first]) {
                color = (color + 1) % r;
                ans[y.second] = color + 1;
                que.push({y.first, color});
            }
        }
    }
    rep(i, n - 1) {
        cout << ans[i] << ' ';
    }
    cout << endl;
}
