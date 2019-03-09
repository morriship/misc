#include<iostream>
#include<sstream>
#include<vector>
#include<map>
#include<string>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<queue>
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

int gcd(int a, int b){ return a%b ? gcd(b,a%b) : b; } 

struct Obj {
    int h,m,t;
};

int cmp(const Obj &a, const Obj &b) {
    return a.h < b.h;
}

int eat(int now, vector<Obj> &obj, int h) {
    int use[obj.size()];
    int n = obj.size();
    memset(use,0,sizeof(use));
    int i,j,ans(0);
    rep(i,n) {
        int m = -1;
        int ind = -1;
        rep(j,n) {
            if (!use[j] && obj[j].t == now && obj[j].h <= h && obj[j].m > m) {
                m = obj[j].m;
                ind = j;
            }
        }
        if (m == -1) {
            return ans;
        }
        use[ind] = 1;
        ans++;
        h += m;
        now ^= 1;
    }
    return ans;
}

int main() {
    int n,hei,ans(0);
    cin >> n >> hei;
    int i,j,k;
    vector<Obj> obj(n);
    rep(i,n) {
        Obj temp;
        cin >> temp.t >> temp.h >> temp.m;
        obj[i] = temp;
    }
    ans = eat(0,obj,hei);
    ans = max(ans,eat(1,obj,hei));
    cout << ans << endl;
}
