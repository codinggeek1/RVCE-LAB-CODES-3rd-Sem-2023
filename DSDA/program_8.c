Rabin Karp
#include<stdio.h>
#include<string.h>

int d = 256, q = 101, m, n, p = 0, t = 0, h = 1,j,i;
char pat[100], txt[1000];

void search(){
	m = strlen(pat);
	n = strlen(txt);
	for(i = 0; i < m-1; i++){
		h = (h*d)%q;
	}
	for( i = 0; i<m; i++){
		p = (d*p + pat[i])%q;
		t = (d*t + txt[i])%q;
	}
	for( i = 0; i<=n-m; i++){
		if(p!=t)
			for(j =0; j<m; j++){
				if(txt[i+j] != pat[j])
					break;
				if(i <= n-m){
				t = (d*(t-txt[i]*h) +txt[i+m])%q;
				if(t<0)
					t+=q;
				}
			}
		if(j == m)
			printf("pattern found at position %d\n",i);
	}
}

int main(){
	printf("enter a word\n");
	scanf("%s",txt);
	printf("Enter the substring to be searched\n");
	scanf("%s",pat);
	search();
	return 0;
}