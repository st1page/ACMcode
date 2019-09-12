#include<cstdio>

using namespace std;
typedef long long ll;

int gn(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||'9'<ch){if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return f*x;
}
#define N 212345
int n;
int f[N];
int main(){
	int T=gn();
	while(T--){
		n=gn();
		int ans=0;
		for(int x=2;x<=n;x++){
			int k=1;
			while(k&x) k<<=1;
			if(k>n) k=1;
			f[x]=k;
			ans+=k&x;
		}
		printf("%d\n",ans);
		for(int i=2;i<n;i++) printf("%d ",f[i]);
		printf("%d\n",f[n]);
	}
	return 0;
}




