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
typedef long long ll;
using namespace std;

ll in[100100];
long long ans;


int main() {
	int t, tt, n, i, j, st;
	ll p, now;
	cin >> tt;
	xrep(t, 1, tt+1) {
		cin >> n >> p;
		now = st = 0;
		ans = 0;
		rep(i, n) {
			scanf("%lld", &in[i]);
			now += in[i];
			while (now > p) { now -= in[st++]; }
			ans += i - st + 1;
		}
		cout << "Case #" << t << ": " << ans << endl;
	}
}
