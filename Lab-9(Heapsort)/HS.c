#include <stdio.h>
void Insrt(int A[],int n)
{
 int i=n,temp;
 temp=A[i];
 while(i>1 && temp>A[i/2])
 {
 A[i]=A[i/2];
 i=i/2;
 }
 A[i]=temp;
}
int Delte(int A[],int n)
{
 int i,j,x,temp,val;
 val=A[1];
 x=A[n];
 A[1]=A[n];
 A[n]=val;
 i=1;j=i*2;
 while(j<=n-1)
 {
 if(j<n-1 && A[j+1]>A[j])
 j=j+1;
 if(A[i]<A[j])
 {
 temp=A[i];
 A[i]=A[j];
 A[j]=temp;
 i=j;
 j=2*j;
 }
 else
 break;
 }
 return val;
}
int main() {
 int H[8];
H[0]=0;
 for(int j=1;j<=7;j++){
scanf("%d",&H[j]);
}
 int i;
 for(i=2;i<=7;i++)
 Insrt(H,i);

 for(i=7;i>1;i--)
 {
 Delte(H,i);
 }
 for(i=1;i<=7;i++)
 printf("%d ",H[i]);
 printf("\n");

 return 0;
}