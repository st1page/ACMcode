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
#define N 20
int a[N],tot;
const int n = 15;
int main(){
	int T = gn();
	while(T--){
		tot = 0;
		int y=0;
		for(int i=1;i<=4;i++) for(int j=1;j<=4;j++){
			int x = gn();
			if(x) a[tot++] = x;
			else y+=(4-i);
		}
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++) if(a[j]<a[i]) y++;
		if(y&1) puts("No");
		else puts("Yes");
	}
}




