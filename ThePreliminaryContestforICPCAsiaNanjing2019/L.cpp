#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;

int gn(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||'9'<ch){if(ch=='-')f=-1;ch=getchar();}
    while('0'<=ch&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return f*x;
}
#define N 1123456

const int dis[6][6] = {
    {0},
    {3,6},
    {4,5,4},
    {5,6,5,6},
    {4,5,6,7,8},
    {7,8,7,8,9,10}
};

int dd=0;
int d(int i,int j){
    i = abs(i), j = abs(j);
    if (i < j) swap(i, j);
    int ti = i, tj = j;
    int res = 0;
    if (i >= 2) ti = (i - 2) % 4 + 2, res += i - ti;
    if (j >= 2) tj = (j - 2) % 4 + 2, res += j - tj;
    return dis[ti][tj] + res;
}
ll ans;
int n;
int vis[20];
struct point{
    int x,y;
}a[20];
bool cmp1(point x,point y){ return x.x<y.x; }
bool cmp2(point x,point y){ return x.x>y.x; }
bool cmp3(point x,point y){ return x.y<y.y; }
bool cmp4(point x,point y){ return x.y>y.y; }
bool cmp5(point a,point b){ 
	if(atan2(a.y,a.x)!=atan2(b.y,b.x)) return atan2(a.y,a.x)<atan2(b.y,b.x);
	else return a.x<b.x;
}
bool cmp6(point x,point y){ return x.x<y.x; }
int tim=0;
void dfs(int now, long long nowans, point last) {
	if(tim>1e7) return ; tim++;
    if (now == n) {
        ans = min(nowans, ans);
    } else if (nowans >= ans) {
        return;
    } else {
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                vis[i] = true;
                if(abs(last.x-a[i].x)+abs(last.y-a[i].y)>dd) continue;
                dfs(now + 1, nowans + d(last.x - a[i].x, last.y - a[i].y), a[i]);
                vis[i] = false;
            }
        }
    }
}
int aa[12345];
int tot=0;
int main(){
    int T=gn();
    while(T--){
        n=gn();
        for(int i=0;i<n;i++) {
            a[i].x=gn(); a[i].y=gn();
        }
        for(int i=0;i<n;i++) {
        	for(int j=0;j<n;j++){
        		aa[tot++]=abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y);
			}
		}
		sort(aa,aa+tot);
		dd=aa[tot]*(n-0.5)/n;
        ans=0x3f3f3f3f3f3f3f3fll;
        tim=0;
		long long sum;
		sort(a,a+n,cmp5);
		for(int st=0;st<n;st++){
			sum=d(abs(a[st].x), abs(a[st].y));
			for(int i=1;i<n;i++) sum+=d(abs(a[(st+i)%n].x-a[(st+i-1)%n].x),abs(a[(st+i)%n].y-a[(st+i-1)%n].y));
			ans=min(ans,sum);
		}
		
		memset(vis, 0, sizeof(vis));
        dfs(0, 0, {0, 0});
		printf("%lld\n",ans);
	}
	return 0;
}



