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


vector<pii> in;

int inc[5100];
int one[5100];

int main() {
    int n, q, i, j;
    cin >> n >> q;
    rep(i, q) {
        int x, y;
        cin >> x >> y;
        in.pb({x, y});
    }
    int ans(0);
    rep(i, q) {
        memset(inc, 0, sizeof(inc));
        memset(one, 0, sizeof(one));
        rep(j, q) if (j != i) {
            inc[in[j].first]++;
            inc[in[j].second + 1]--;
        }
        int cnt(0), total(0);
        xrep(j, 1, n + 1) {
            cnt += inc[j];
            if (cnt) {
                total++;
            }
            one[j] = one[j - 1] + (cnt == 1);
        }
        rep(j, q) if (j != i){
            ans = max(ans, total - one[in[j].second] + one[in[j].first - 1]); 
        }
    }
    cout << ans << endl;
}
