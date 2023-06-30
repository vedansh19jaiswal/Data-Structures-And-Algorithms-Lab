#include<stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#define V 8
#define max 10

//Selected citites are Nagpur Akola Bhopal Sagar Raipur Sambhalpur Allahbad Jagdalpur


struct queue
{
int size;
int front ;
int rear;
int *arr;
};
int visited[V], i=0;;
int isFull(struct queue *ptr)
{
if(ptr->rear==ptr->size-1)
{
return 1;
}
else
{
return 0;
}
}
int isEmpty(struct queue *ptr)
{
if(ptr->front==ptr->rear)
{
return 1;
}
else
{
return 0;
}
}
void enqueue(struct queue *ptr,int ele)
{
if(isFull(ptr))
{
printf("The above queue is full\n");
}
else
{
ptr->rear++;
ptr->arr[ptr->rear]=ele;
}
}
int dequeue(struct queue *ptr)
{ int data=0;
if(isEmpty(ptr))
{
printf("The Queue is empty");
}
else
{
ptr->front++;
data=ptr->arr[ptr->front];
}
return data;
}
int minKey(int key[], bool mstSet[])
{
int min = INT_MAX, min_index;
for (int v = 0; v < V; v++)
if (mstSet[v] == false && key[v] < min)
min = key[v], min_index = v;
return min_index;
}
void dfs(int i,int a1[V][V])
{
printf("%d",i);
visited[i]=1;
for(int j=1;j<=8;j++)
{
if(a1[i][j]==1 && !visited[j] )
{
dfs(j,a1);
}
}
}
int printMST(int parent[], int graph[V][V])
{
int sum =0;
printf("Edge \tWeight\n");
for (int i = 1; i < V; i++)
printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
for (int i = 1; i < V; i++){
sum = sum+graph[i][parent[i]];
}
printf("Cost of Spanning tree is :%d", sum);
}
void primMST(int graph[V][V])
{
int parent[V];
int key[V];
bool mstSet[V];
for (int i = 0; i < V; i++)
key[i] = INT_MAX, mstSet[i] = false;
key[0] = 0;
parent[0] = -1;
for (int count = 0; count < V - 1; count++) {
int u = minKey(key, mstSet);
mstSet[u] = true;
for (int v = 0; v < V; v++)
if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
parent[v] = u, key[v] = graph[u][v];
}
printMST(parent, graph);
}
int main()
{
struct queue ptr;
ptr.size=20;
ptr.front=ptr.rear=0;
ptr.arr=(int *)malloc(ptr.size*sizeof(int));
int a1[8][8]={
{0,0,0,0,1,0,0,1},
{0,0,1,0,0,0,1,0},
{0,1,0,1,0,0,0,0},
{0,0,1,0,1,0,0,0},
{1,0,0,1,0,1,0,0},
{0,0,0,0,1,0,0,1},
{1,1,0,0,0,0,0,1},
{1,0,0,0,0,1,1,0}
};
int i=1;
int visited[8]={0,0,0,0,0,0,0};
int a[8][8]={
{0,0,0,0,283,0,250,634},
{0,0,169,0,0,0,376,0},
{0,169,0,599,0,0,0,0},
{0,0,599,0,270,0,0,0},
{283,0,0,270,0,301,0,0},
{0,0,0,0,301,0,0,896},
{250,376,0,0,0,0,0,883},
{634,0,0,0,0,896,883,0}
};
printf("The cities selected are: \n1)Nagpur \n2)Akola \n3)Bhopal\n4)Sagar \n5)Raipur \n6)Sambhalpur \n7)Allahbad \n8)Jagdalpur");
printf("\nDistance is in Kilometers\n");
printf("---------------------------------------");
printf("\nGraph as Adjacency Matrix for diatance :\n");
for(int i=0;i<8;i++){
for(int j=0;j<8;j++){
printf("%d\t",a[i][j]);
}
printf("\n");
}
printf("----------------------------------------");
printf("\nThe BSF Search is as follows\n");
printf("%d",i);
visited[i]=1;
enqueue(&ptr,i);
while(!isEmpty(&ptr))
{
int node=dequeue(&ptr);
for(int j=1;j<=8;j++)
{
if(a1[node][j]==1 && visited[j]==0)
{
printf("%d",j);
visited[j]=1;
enqueue(&ptr,j);
}
}
}
printf("\nThe DSF Search is as follows\n");
dfs(1,a1);
printf("\n");
primMST(a);
return 0;
}


