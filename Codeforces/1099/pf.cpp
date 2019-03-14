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
#define MX 100010
#define vi vector<int>
#define pii pair<int, int>
#define mii map<int, int>
#define pb push_back
typedef long long ll;
using namespace std;


template<class T, int SZ> class SegmenetTree {
private:
    T val[SZ*4];
    T cnt[SZ*4];
    pii range[SZ*4];
    void clear() { memset(val, 0, sizeof(val)), memset(cnt, 0, sizeof(cnt)); }
    void build(int idx, int l, int r) {
        range[idx] = {l, r};
        if (l != r) {
            int mi = (l + r) >> 1;
            build(idx + idx, l, mi);
            build(idx + idx + 1, mi + 1, r);
        }
    }
    int getIdx(int pos) {
        int l(1), r(SZ), idx(1);
        while (l < r) {
            int mi((l + r) >> 1);
            idx <<= 1;
            if (mi >= pos) { r = mi; }
            else { ++idx, l = mi + 1; }
        }
        return idx;
    }

public:
    SegmenetTree() { build(1, 1, SZ), clear(); }
    void add(int pos, T v) {
        int idx(getIdx(pos));
        for (; idx > 0; idx >>= 1) {
            val[idx] += pos * v;
            cnt[idx] += v;
        }
    }
    T query(T total) { return query(total, 1); }
    T query(T total, int idx) {
        if (total < val[idx]) {
            if (range[idx].first != range[idx].second) {
                int nidx(idx << 1);
                T result = query(total, nidx);
                total -= val[nidx];
                if (total > 0) {
                    result += query(total, nidx + 1);
                }
                return result;
            } else if (total > 0) {
                return total / range[idx].first;
            } else {
                return 0;
            }
        }
        return cnt[idx];
    }
};

SegmenetTree<ll, 1000100> st;
ll x[MX], t[MX];
vi edge[MX];
vi cost[MX];
ll dp[MX];

ll dfs(int now, ll rest) {
    if (rest <= 0) {
        dp[now] = 0;
        return dp[now];
    }
    st.add(t[now], x[now]);
    vector<ll> ch;
    for (int i = 0; i < edge[now].size(); i++) {
        int y = edge[now][i];
        int c = cost[now][i];
        ch.pb(dfs(y, rest - c));
    }
    dp[now] = st.query(rest);
    if (ch.size() > 1) {
        sort(ch.begin(), ch.end());
        dp[now] = max(dp[now], ch[ch.size() - 2]);
    }
    st.add(t[now], -x[now]);
    return dp[now];
}

int main() {
    ll n, T;
    int i, j;
    cin >> n >> T;
    xrep(i, 1, n + 1) { cin >> x[i]; }
    xrep(i, 1, n + 1) { cin >> t[i]; }
    xrep(i, 2, n + 1) {
        ll p, c;
        cin >> p >> c;
        edge[p].pb(i);
        cost[p].pb(c + c);
    }
    dfs(1, T);
    ll ans = dp[1];
    rep(i, edge[1].size()) {
        int y(edge[1][i]);
        ans = max(ans, dp[y]);
    }
    cout << ans << endl;
    // xrep(i, 1, n + 1) {
    //     cout << i << ": " << dp[i] << endl;
    // }
}
