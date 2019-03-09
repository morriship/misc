#include<bits/stdc++.h>
#define two(a) (1<<(a))
#define LINF (1ll<<61)
#define EPS (1e-14)
#define Lshift(a,b) (a<<b)
#define Rshift(a,b) (a>>b)
#define rep(a,b) for(a=0 ; a<b ; a++)
#define xrep(a,b,c) for(a=b ; a<c ; a++)
#define INF (1<<29)
#define readi(a) scanf("%d", &a)
#define swap(a,b) ( (a^=b) , (b^=a) , (a^=b) )
#define min(a,b) ( a < b ? a : b )
#define max(a,b) ( a > b ? a : b )
#define GET(x) (mark[x>>5]>>(x&31)&1)
#define SET(x) (mark[x>>5]|=1<<(x&31))
#define maxL (10000000>>5)+1
#define mod 1000000007
typedef long long ll;
using namespace std;

vector<pair<ll, ll> > in;
ll st[200010], slen;
long long sum[200010], num[200010], sumx[200010];

int main() {
    int i, j, k, t, tt, n;
    ll x, h;
    cin >> tt;
    slen = 0;
    ll ans;
    xrep(t, 1, tt+1) {
        in.clear();
        ans = 0;
        scanf("%lld", &n);
        rep(i, n) {
            scanf("%lld%lld", &x, &h);
            in.push_back({x, h});
        }
        sort(in.begin(), in.end());
        memset(sumx, 0, sizeof(sumx));
        memset(st, 0, sizeof(st));
        memset(sum, 0, sizeof(sum));
        memset(num, 0, sizeof(num));
        slen = 0;
        rep(i, n) {
            long long val = in[i].second;
            ll posi = in[i].first;
            //cout << "val: " << val << endl;
            //cout << "posi: " << posi << endl;
            if (!slen) {
                st[slen] = val;
                sum[slen] = posi;
                sumx[slen] = (posi * posi) % mod;
                num[slen] = 1;
                slen++;
            }
            else {
                while (slen && st[slen-1] < val) { slen--; }
                if (!slen || st[slen-1] > val) {
                    st[slen] = val;
                    sum[slen] = posi;
                    sumx[slen] = (posi * posi) % mod;
                    num[slen] = 1;
                    slen++;
                }
                else if (st[slen-1] == val) {
                    ll posx = ((posi * posi) % mod) * num[slen-1];
                    ll xxx = (2 * posi * sum[slen-1]) % mod;
                    if (posx < xxx) posx += mod;
                    ans += posx - xxx + sumx[slen-1];
                    ans %= mod;
// cout << posi * posi * num[slen-1] << ' ' << 2 * posi * sum[slen-1] << ' ' << sumx[slen-1] << endl;
                    sum[slen-1] += posi;
                    sumx[slen-1] += (posi * posi) % mod;
                    num[slen-1]++;
                    sum[slen-1] %= mod;
                    sumx[slen-1] %= mod;
                    num[slen-1] %= mod;
//cout << sumx[slen-1] << endl;
                }
            }
        }
        cout << "Case #" << t << ": " << ans << endl;
    }
}
