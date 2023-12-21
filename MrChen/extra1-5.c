#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#define rg register int
typedef long long ll;
typedef unsigned long long ull;
typedef long double lb;

int n;
ll ans, m;

inline ll qr() {  //快读
    char ch;
    while ((ch = getchar()) < '0' || ch > '9')
        ;
    ll res = ch ^ 48;
    while ((ch = getchar()) >= '0' && ch <= '9') res = res * 10 + (ch ^ 48);
    return res;
}

inline ll Abs(ll x) { return x < 0 ? -x : x; }  //取绝对值
inline ll gcd(ll x, ll y) {                     //非递归求gcd
    ll z;
    while (y) {
        z = x;
        x = y;
        y = z % y;
    }
    return x;
}

inline ll ksc(ull x, ull y, ll p) {  // O(1)快速乘（防爆long long）
    return (x * y - (ull)((lb)x / p * y) * p + p) % p;
}

inline ll ksm(ll x, ll y, ll p) {  //快速幂
    ll res = 1;
    while (y) {
        if (y & 1) res = ksc(res, x, p);
        x = ksc(x, x, p);
        y >>= 1;
    }
    return res;
}

inline bool mr(ll x, ll p) {              // mille rabin判质数
    if (ksm(x, p - 1, p) != 1) return 0;  //费马小定理
    ll y = p - 1, z;
    while (!(y & 1)) {  //二次探测
        y >>= 1;
        z = ksm(x, y, p);
        if (z != 1 && z != p - 1) return 0;
        if (z == p - 1) return 1;
    }
    return 1;
}

inline bool prime(ll x) {
    if (x < 2) return 0;  // mille rabin判质数
    if (x == 2 || x == 3 || x == 5 || x == 7 || x == 43) return 1;
    return mr(2, x) && mr(3, x) && mr(5, x) && mr(7, x) && mr(43, x);
}

inline ll rho(ll p) {  //求出p的非平凡因子
    ll x, y, z, c, g;
    rg i, j;                 //先摆出来（z用来存（y-x）的乘积）
    while (1) {              //保证一定求出一个因子来
        y = x = rand() % p;  //随机初始化
        z = 1;
        c = rand() % p;                  //初始化
        i = 0, j = 1;                    //倍增初始化
        while (++i) {                    //开始玄学生成
            x = (ksc(x, x, p) + c) % p;  //可能要用快速乘
            z = ksc(z, Abs(y - x), p);  //我们将每一次的（y-x）都累乘起来
            if (x == y || !z)
                break;  //如果跑完了环就再换一组试试（注意当z=0时，继续下去是没意义的）
            if (!(i % 127) ||
                i == j) {  //我们不仅在等127次之后gcd我们还会倍增的来gcd
                g = gcd(z, p);
                if (g > 1) return g;
                if (i == j)
                    y = x, j <<= 1;  //维护倍增正确性，并判环（一箭双雕）
            }
        }
    }
}

inline void prho(ll p) {   //不断的找他的质因子
    if (p <= ans) return;  //最优性剪纸
    if (prime(p)) {
        ans = p;
        return;
    }
    ll pi = rho(p);  //我们一次必定能求的出一个因子，所以不用while
    while (p % pi == 0) p /= pi;  //记得要除尽
    return prho(pi), prho(p);     //分开继续分解质因数
}

int main() {
    // freopen("in.txt","r",stdin);
    // ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    n = qr();
    srand(time(0));  //随机数生成必备！！！
    for (rg i = 1; i <= n; ++i) {
        ans = 1;
        prho((m = qr()));
        if (ans == m)
            puts("Prime");
        else
            printf("%lld\n", ans);
    }
    return 0;
}