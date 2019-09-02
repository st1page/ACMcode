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
#define N 112345
int t[N];
int n,k;
ll ans;

int main(){
	int T; scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		ans=0;
		for(int i=0;i<n;i++) scanf("%d",&t[i]);
		for(int i=0;i<n;i++) ans+=t[i];
		sort(t,t+n);
		ans+=k;
		int cnt=0;
		for(int i=n-1;i>=0;i--) if(t[i]>=k) {
			cnt+=t[i]/k; t[i]%=k;
		} 
		if(cnt>=n-1) printf("%lld\n",ans);
		else {
			cnt=n-1-cnt;
			sort(t,t+n);
			for(int i=n-1;cnt&&i>=0;i--) {
				cnt--;
				ans+=k-t[i];	
			}
			printf("%lld\n",ans);
		}
	}
}




