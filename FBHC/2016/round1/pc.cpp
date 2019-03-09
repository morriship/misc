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

ll c[100010], sum;
int n;

double get_all() {
    double result(0);
    int i;
    rep(i, n) { result += double(c[i]) * c[i] / 2; }
    return result;
}

double get_remain(ll re) {
    double result(0);
    int i;
    rep(i, n) {
        if (c[i] < re) {
            re -= c[i];
            result += double(c[i]) * c[i] / 2;
        }
        else {
            result += double(re) * re / 2;
            break;
        }
    }
    return result;
}

int main() {
    int t, tt, i, j, k;
    ll a, b;
    readi(tt);
    xrep(t, 1, tt+1) {
        cin >> n >> a >> b;
        sum = 0;
        rep(i, n) {
            scanf("%lld", &c[i]);
            sum += c[i];
        }
        ll count(b/sum - a/sum);
        double ans(0);
        if (count) { ans += get_all() * count; }
        ans += get_remain(b%sum) - get_remain(a%sum);
        double ansd = ans / (b - a);
        
        printf("Case #%d: %.9lf\n", t, ansd);
    }
}
