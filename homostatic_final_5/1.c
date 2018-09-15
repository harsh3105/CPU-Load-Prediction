#include<stdio.h>
int i,j,n;float totwt,totserv;
struct pr
{
char name[5];
float tservice;
int priority;
float twait;
float trnd;
};
struct pr temp;
struct pr pr1[20];
void init()
{
printf("\nEnter the number of processes:");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("\nprocess %d:\n1.Name: ",i+1);
scanf("%s",pr1[i].name);
printf("Service time: ");
scanf("%f",&pr1[i].tservice);
printf("Priority: ");
scanf("%d",&pr1[i].priority);
}
}
void sjnsort()
{
for(i=0;i<n;i++)
for(j=0;j<n-i-1;j++)
{
if(pr1[j].tservice>pr1[j+1].tservice)
{
temp=pr1[j];
pr1[j]=pr1[j+1];
pr1[j+1]=temp;
}
}
}
void calculation()
{
pr1[0].twait=0;totwt=0;totserv=pr1[0].trnd=pr1[0].tservice;
for(i=1;i<n;i++)
{
//printf("\nwait= %f",totwt);
pr1[i].twait=pr1[i-1].twait+pr1[i-1].tservice;
totwt+=pr1[i].twait;
pr1[i].trnd=pr1[i].twait+pr1[i].tservice;
totserv+=pr1[i].trnd;
}
}
void printing()
{
printf("Name \tPriority \tServiceTime \t WaitTime \t TurnAroundTime\n");
for(i=0;i<n;i++)
{
printf("%s \t %d \t\t %f \t %f \t %f\n",pr1[i].name,pr1[i].priority,pr1[i].tservice,pr1[i].twait,pr1[i].trnd);
}
printf("\nAverage wait:%f \tAverage turnaround:%f \n",totwt/n,totserv/n);
}
int main()
{
int ch,exit=0;
init();
sjnsort();
if(exit==0)
{
calculation();
printing();
}
}
