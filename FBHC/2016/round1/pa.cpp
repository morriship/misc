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
#define readInt(a) scanf("%d", &a)
#define min(a,b) ( a < b ? a : b )
#define max(a,b) ( a > b ? a : b )
#define GET(x) (mark[x>>5]>>(x&31)&1)
#define SET(x) (mark[x>>5]|=1<<(x&31))
#define maxL (10000000>>5)+1
#define mod 1000000007
typedef long long ll;
using namespace std;

int in[100011];

int main() {
    int tt, t, n, d, ans, count, i, now;
    readInt(tt);
    xrep(t, 1, tt+1) {
        count = ans = 0;
        readInt(n);
        rep(i, n) { readInt(in[i]); }
        now = in[0];
        count = 1;
        xrep(i, 1, n) {
            if (!count) {
                now = in[i];
                count++;
                continue;
            }
            if (in[i] <= now) {
                ans += 4 - count;
                count = 0;
                --i;
                continue;
            }
            while (count < 4 && now < in[i] - 10) {
                ++ans;
                ++count;
                now += 10;
            }
            if (count < 4 && now + 10 >= in[i]) {
                ++count;
                now = in[i];
                if (count == 4) { count = 0; }
            }
            else if (count == 4) {
                count = 0;
                i--;
                continue;
            }
        }
        if (count) { ans += 4 - count; }
        cout << "Case #" << t << ": " << ans << endl;
    }
}
