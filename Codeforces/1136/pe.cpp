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
#define pb push_back
typedef long long ll;
using namespace std;


ll a[100100], k[100010];

template<class T, int SZ> class BIT {
public:
    int SIZE;
    T bit[1<<SZ+1];
    T inc[1<<SZ+1];
    BIT() {
        memset(bit, 0, sizeof(bit));
        memset(inc, 0, sizeof(inc));
        SIZE = 1 << SZ + 1;
    }
    void add(int pos, T v) {
        while (1) {
            bit[pos] += v;

            if (pos == SIZE) { break; }
            pos += pos & -pos;
        }
    }

    void _update(int pos, T sum, T _inc) {
        while (1) {
            bit[pos] += sum;
            inc[pos] += _inc;
            if (pos == SIZE) { break; }
            pos += pos & -pos;
        }
    }
    void update(int l, int r, T val) {
        _update(l, -val * (l - 1), val);
        _update(r + 1, val * r, -val);
    }

    T query(int pos) {
        T ans;
        int p(pos);
        T _inc(0), _sum(0);
        while (p) {
            _sum += bit[p];
            _inc += inc[p];
            p -= p & -p;
        }
        return _sum + _inc * pos;
    }

    T query(int l, int r) {
        return query(r) - query(l - 1);
    }
};


BIT<ll, 20> bit;

int main() {
    int n, i, j;
    cin >> n;
    map<ll, ll> point;
    rep(i, n) { cin >> a[i+1]; }
    rep(i, n - 1) { cin >> k[i+1]; }
    ll cnt = a[1];
    bit.add(1, a[1]);
    point[1] = a[1];
    xrep(i, 2, n + 1) {
        bit.add(i, a[i]);
        if (a[i] - k[i-1] > a[i-1]) {
            cnt += a[i] - k[i-1] - a[i-1];
            point[i] = cnt;
        }
    }
    point[n + 1] = 1ll << 62;
    int q;
    cin >> q;
    rep(i, q) {
        char queryType;
        cin >> queryType;
        if (queryType == '+') {
            ll pos, val;
            cin >> pos >> val;
            auto iter = point.upper_bound(pos);
            --iter;
            ll cnt = iter -> second + val;
            vector<ll> rmlist;
            while (iter -> second <= cnt) {
                ll pcnt = iter -> second;
                ++iter;
                ll ncnt = min(cnt, iter -> second);
                ll diff(ncnt - pcnt);
                bit.update(pos, iter -> first - 1, diff);
                if (iter -> second <= cnt) {
                    rmlist.pb(iter -> first);
                }
            }
            for (auto x: rmlist) {
                point.erase(x);
            }
            point[pos] = cnt;
        } else { // 's'
            int l, r;
            cin >> l >> r;
            cout << bit.query(l, r) << endl;
        }
    }
}
