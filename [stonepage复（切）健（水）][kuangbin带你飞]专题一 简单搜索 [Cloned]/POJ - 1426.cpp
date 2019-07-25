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

#define N 201
int n;
ll ans[201];
void dfs(ll x,int d){
	if(d==20||ans[n]) return ;
	if(x%n==0){
 		ans[n] = x; return ;
	}
	dfs(x*10+1,d+1);
	dfs(x*10,d+1);
}
int main(){ 
	for(n=1;n<=200;n++) dfs(1,1);
//	for(n=1;n<=200;n++) if(!ans[n]) printf("%d\n",n);
	scanf("%d",&n);
	while(n){
		printf("%lld\n",ans[n]);
		scanf("%d",&n);
	}	
	return 0;
} 



