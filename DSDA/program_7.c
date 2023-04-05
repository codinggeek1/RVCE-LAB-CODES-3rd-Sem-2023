Dijkstra Algorithm

#include<stdio.h>
#include<math.h>

int main(){
	int n;
	printf("Enter the number of vertices : ");
	scanf("%d",&n);
	int g[n][n];
	printf("Enter the adjacency matrix");
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			scanf("%d",&g[i][j]);
		}
	}
	int s;
	printf("Enter the starting node");
	scanf("%d",&s);
	double c[n][n];
	for (int i=0; i<n; i++){
		for( int j=0; j<n; j++){
			if(g[i][j] != 0){
				c[i][j] = g[i][j];
			}
			else{
				c[i][j] = INFINITY;
			}
		}
	}
	
	double distance[n];
	int pred[n], visited[n];
	for(int i=0; i<n; i++){
		distance[i] = c[s][i];
		pred[i] = s;
		visited[i] = 0;
	}
	int nextnode;
	distance[s] = 0;
	visited[s] = 1;
	int count = 1;
	
	while(count < n-1){
		double min = INFINITY;
		for(int i =0; i<n; i++){
			if(distance[i] < min && !visited[i]){
				min = distance[i];
				nextnode = i;
			}
		}
		visited[nextnode] = 1;
		for(int i=0; i<n; i++){
			if(!visited[i]){
				if((min + c[nextnode][i] )< distance[i]){
					distance[i] = min + c[nextnode][i];
					pred[i] = nextnode;
				}
			}
		}
		count++;
	}
	for(int i=0; i<n; i++)
	{
		if(i != s){
			printf("Distance of %d to %d = %lf\n",i,s, distance[i]);
			printf("Path %d %d \n%d ",s,i,i);
			int j=i;
			do{
				j = pred[j];
				printf("%d ",j);
			}while(j != s);
		}
	}
	return 0;
}