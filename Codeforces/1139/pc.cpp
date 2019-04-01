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

int parent[100010];
ll cnt[100010];

vi edge[100010];


void bfs(int x) {
    queue<int> que;
    que.push(x);
    parent[x] = x;
    while (!que.empty()) {
        int y = que.front();
        cnt[x]++;
        que.pop();
        for (auto v: edge[y]) {
            if (parent[v] == -1) {
                parent[v] = x;
                que.push(v);
            }
        }
    }
}

ll xpow(ll x, ll y) {
    int i;
    ll res(1);
    rep(i, y) {
        res = (res * x) % mod;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    int i, j, x, y, v;
    rep(i, n - 1) {
        cin >> x >> y >> v;
        if (v == 0) {
            edge[x].pb(y);
            edge[y].pb(x);
        }
    }
    memset(parent, -1, sizeof(parent));
    memset(cnt, 0, sizeof(cnt));
    xrep(i, 1, n + 1) {
        if (parent[i] == -1) {
            bfs(i);
        }
    }
    ll ans(0);
    ans += xpow(n, k);
    rep(i, n + 1) {
        if (cnt[i]) {
            ans -= xpow(cnt[i], k);
            if (ans < 0) { ans += mod; }
        }
    }
    cout << ans << endl;
}
