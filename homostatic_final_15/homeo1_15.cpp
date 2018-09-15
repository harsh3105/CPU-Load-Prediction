#include<iostream>
#include<string.h>
#include<conio.h>
#include<cmath>
using namespace std;
int i=0,j,k,n,x,u;
float load[10];
float number = 0,number2=0;
float sum = 0;
float a,error;
float m;
float decre[100];
float adapt=0.15;
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
	cout<<"\nThe mean of the CPU load is : "<<m<<endl; 
}
void input()
{
	
    FILE* f = fopen("history15.txt", "r");
     /* the sum of numbers in the file */

    while( fscanf(f, "%f,", &number) > 0 ) // parse %d followed by ','
    {
    	 // instead of sum you could put your numbers in an array
    	load[i]=number;
    	i++;
    }

    fclose(f);
    
  
   
	 
   for(j=0;j<15;j++)
     {
	 printf("\n load %d is %f",j+1,load[j]);
	 siz++;
    }
	for(x=1;x<15;x++)
	{
		if(load[x]>load[x-1])
		decre[x]=decre[x-1]+((load[x]-load[x-1])-decre[x-1])*adapt;
		else
		decre[x]=decre[x-1]+((load[x-1]-load[x])-decre[x-1])*adapt;
	}
	cout<<"\ndecre is";
	for(u=0;u<15;u++)
	 {
	
	   cout<<"\n"<<decre[u];
      }
}
void next()
{
		
		  
		  FILE* f = fopen("current15.txt", "r");
     

    fscanf(f, "%f,", &a) > 0 ; // parse %d followed by ','
   cout<<"The load value from the file : "<<a<<endl;

    fclose(f); 
		  
		  siz++;
		  load[siz-1]=a;
		  if(load[siz-1]>load[siz-2])
		decre[siz-1]=decre[siz-2]+((load[siz-1]-load[siz-2])-decre[siz-2])*adapt;
		else
		decre[siz-1]=decre[siz-2]+((load[siz-2]-load[siz-1])-decre[siz-2])*adapt;
		  
		  
	      }

void predict()
{
	 
	 if(a<m)
	 {
	 	 cout<<"\nCurrent decrement value: "<<decre[siz-1];
	 	 cout<<"\n";
	 	 
		 cout<<"\n Given current value is less than mean so predicted value will be: ";
	 	
		 cout<<a+decre[siz-1];
		 
		 error=(abs(number2-(a+decre[siz-1]))/number2)*100;
		 cout<<"\nThe error will be: "<<error;
		 
	 }
	 if(a>m)
	 {
	 	  cout<<"\nCurrent decrement value: "<<decre[siz-1];
	 	   cout<<"\n";
		  cout<<"\nGiven current value is greater than mean so predicted value will be: ";
		  
	 	 cout<<a-decre[siz-1];
	 	  cout<<"\n";
	 	 error=(abs(number2-(a-decre[siz-1]))/number2)*100;
		 cout<<"\nThe error percent will be: "<<error;
	 	 
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
	
FILE* f = fopen("original15.txt", "r");
     

    fscanf(f, "%f,", &number2) > 0 ;// parse %d followed by ','
   	cout<<"The original value is:"<<number2;
   
   fclose(f);
	predict();

   
}

