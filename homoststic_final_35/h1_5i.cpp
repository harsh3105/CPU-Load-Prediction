#include<iostream>
#include<string.h>
#include<conio.h>
#include<math.h>
using namespace std;
int i=0,j,k,n,x,u;
float load[50];
float number = 0;
float sum = 0;
float a,e;
float m;
float decre[100];
float adapt=0.5;
int siz=0;
void mean()
{
	 
	float sum=0;
	for(i=0;i<siz;i++)
	{
		sum=sum+load[i];
	}
//	cout<<"\n The total sum of the array is: "<<sum;
	m=sum/siz;
	cout<<"\n The mean of the CPU load is : "<<m; 
}
void input()
{
	
    FILE* f = fopen("A.txt", "r");
     /* the sum of numbers in the file */

    while( fscanf(f, "%f,", &number) > 0 ) // parse %d followed by ','
    {
    	 // instead of sum you could put your numbers in an array
    	load[i]=number;
    	i++;
    }

    fclose(f);
    for(j=0;j<35;j++)
     {
	 printf("\n load %d is %f",j+1,load[j]);
	 siz++;
    }
	for(x=1;x<35;x++)
	{
		if(load[x]>load[x-1])
		decre[x]=decre[x-1]+((load[x]-load[x-1])-decre[x-1])*adapt;
		else
		decre[x]=decre[x-1]+((load[x-1]-load[x])-decre[x-1])*adapt;
	}
	cout<<"\ndecre is";
	for(u=0;u<35;u++)
	 {
	
	   cout<<"\n"<<decre[u];
      }
}
void next()
{
		
		  
		   FILE *myFile= fopen("A1.txt", "r");

    //read file into array
    	   
    	fscanf(myFile, "%f,", &a);
		  fclose(myFile);
		  siz++;
		  load[siz-1]=a;
		  
		  cout<<"\n the current load value is : "<<load[siz-1];
		  if(load[siz-1]>load[siz-2])
		decre[siz-1]=decre[siz-2]+((load[siz-1]-load[siz-2])-decre[siz-2])*adapt;
		else
		decre[siz-1]=decre[siz-2]+((load[siz-2]-load[siz-1])-decre[siz-2])*adapt;
		  
		  
	      }

void predict()
{
	 
	 if(a<m)
	 {
	 	 cout<<"\n Current decrement value: "<<decre[siz-1];
		 cout<<"\n given current value is less than mean so predicted value will be: ";
	 	
		 cout<<a+decre[siz-1];
		 	 	 cout<<"\n The original value is : "<<e;
	 	 cout<<"\n Error in percentage is: ";
	 	 cout<<"\n"<<abs(((e-(a-decre[siz-1]))/e)*100)<<" %";
	 }
	 if(a>m)
	 {
	 	  cout<<"\n Current decrement value: "<<decre[siz-1];
		  cout<<"\n given current value is greater than mean so predicted value will be: ";
	 	 cout<<a-decre[siz-1];
	 	 cout<<"\n The original value is : "<<e;
	 	 cout<<"\n Error in percentage is: ";
	 	 cout<<"\n"<<abs(((e-(a-decre[siz-1]))/e)*100)<<" %";
	 }
	 if(a==m)
	 {
	   cout<<"\n the current value and the mean value is same so predicted value is same";
     }
 }

int main()
{
	decre[0]=0;
	input();
	
	mean();
	next();
	
		   FILE *myFile= fopen("A2.txt", "r");

    //read file into array
    	   
    	fscanf(myFile, "%f,", &e);
		  fclose(myFile);

	predict();
}
