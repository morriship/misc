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

int in[200010];
vector<ll> out;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, i, j;
    cin >> n;
    int cnt(0), maxn(0);
    rep(i, n - 1) {
        cin >> in[i];
        cnt += in[i];
        maxn = max(maxn, cnt);
    }
    int offset = n - maxn;
    out.pb(offset);
    rep(i, n - 1) {
        offset += in[i];
        out.pb(offset);
    }
    sort(out.begin(), out.end());
    rep(i, n) {
        if (out[i] != i + 1) {
            break;
        }
    }
    if (i < n || out.size() != n) {
        cout << -1 << endl;
    } else {
        offset = n - maxn;
        cout << offset;
        rep(i, n - 1) {
            offset += in[i];
            cout << ' ' << offset;
        }
        cout << endl;
    }
}
