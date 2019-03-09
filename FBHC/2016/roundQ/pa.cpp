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

map<int, int> xmap[2010];
pair<int, int> in[2010];
int dist[2010][2010];
int c[2010][2010];

inline int cal_dist(int a, int b) {
	return (in[a].first - in[b].first) * (in[a].first - in[b].first) + (in[a].second - in[b].second) * (in[a].second - in[b].second);
}

long long ans;

int main() {
	int t, tt, n;
	int i, j, k;
	cin >> tt;
	xrep(t, 1, tt+1) {
		rep(i, n) xmap[i].clear();
		ans = 0;
		cin >> n;
		rep(i, n) {
			scanf("%d%d", &in[i].first, &in[i].second);
		}
		rep(i, n) dist[i][i] = 0;
		rep(i, n) xrep(j, i+1, n) {
			dist[i][j] = dist[j][i] = cal_dist(i, j);
		}
		rep(i, n) {
			rep(j, n) {
				xmap[i][dist[i][j]] += 1;
			}
		}
		rep(i, n) {
			for (map<int, int>::iterator it = xmap[i].begin(); it != xmap[i].end(); it++) {
				if (it->second > 1) {
					int a = it->second;
					ans += a * (a-1) / 2;
				}
			}
		}
		cout << "Case #" << t << ": " << ans << endl;
	}
}
