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


vector<pii> in;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k, i, t, b;
    cin >> n >> k;
    rep(i, n) {
        cin >> t >> b;
        in.pb({b, t});
    }
    sort(in.begin(), in.end());
    ll sum(0), ans(0);
    multiset<int> xset;
    for (i = n - 1; i >= 0; i--) {
        b = in[i].first;

        sum += in[i].second;
        xset.insert({in[i].second});
        if (n - i > k) {
            sum -= *xset.begin();
            xset.erase(xset.begin());
        }
        ans = max(ans, sum * b);
    }
    cout << ans << endl;
}
