#include<stdio.h>

int max[100][100];
int alloc[100][100];
int need[100][100];
int avail[100];
int n,r;

void input();
void show();
void cal();

int main(){
printf("Enter no of processes:");
scanf("%d",&n);
printf("Enter no of resources:");
scanf("%d",&r);
input();
show();
cal();
return 0;
}

void input(){
int i,j;

printf("Enter the max matrix:");
for(i=0;i<n;i++){
for(j=0;j<r;j++){
scanf("%d",&max[i][j]);
}
}

printf("Enter the alloc matrix:");
for(i=0;i<n;i++){
for(j=0;j<r;j++){
scanf("%d",&alloc[i][j]);
}
}

printf("Enter the avail matrix:");
for(j=0;j<r;j++){
scanf("%d",&avail[j]);
}
}

void show(){
int i,j;
printf("Process\tMaximum\tAllocation\tRemaining");

for(i=0;i<n;i++){
printf("P%d",i+1);
for(j=0;j<r;j++){
printf("%d",max[i][j]);
}
printf("\t");
for(j=0;j<r;j++){
printf("%d",alloc[i][j]);
}
printf("\t");
if(i==0){
for(j=0;j<r;j++){
printf("%d",avail[j]);
}
}
}
}

void cal(){
int finish[100],i,j,k,c=0,cl,flag=1;



for(i=0;i<n;i++){
finish[i]=0;
}

for(i=0;i<n;i++){
for(j=0;j<r;j++){
need[i][j] = max[i][j] - alloc[i][j];
}
}

while(flag){
flag=0;
for(i=0;i<n;i++){
c=0;
for(j=0;j<r;j++){
if((finish[i]==0) && (need[i][j]<=avail[j])){
c++;
}
if(c==r){
finish[i]=1;
flag=1;
for(k=0;k<r;k++){
avail[k] += alloc[i][k];
}
}
}
}
}

for(i=0;i<n;i++){
if(finish[i]==1){
cl++;
}
else{
printf("P%d->",i);
}
}

if(cl==n){
printf("System is in safe state");
}
else{
printf("System is in unsafe state");
}
}