#include<iostream>
#include<string.h>
#include<conio.h>
#include<math.h>
#include<cmath>
using namespace std;
float load[50];
int i,j,k,siz=0;
float a,e;
float m,number;

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
}
void next()
{
	
		  
	       FILE *myFile= fopen("current15.txt", "r");

    //read file into array
    	   
    	fscanf(myFile, "%f,", &a);
		  fclose(myFile);
		  siz++;
		  load[siz-1]=a;
		  cout<<"\n the current load value is : "<<load[siz-1];
	 	 
	 }
	 


void predict()
{

	 
	 if(a<m)
	 {
	 	cout<<"\n given current value is less than mean so predicted value will be: ";
	 	cout<<a+0.1;
	 	 cout<<"\n The original value is : "<<e;
	 	 cout<<"\n Error in percentage is: ";
	 	 cout<<"\n"<<abs(((e-(a+0.1))/e)*100)<<" %";
	 }
	 if(a>m)
	 {
	 	 cout<<"\n given current value is greater than mean so predicted value will be: ";
	 	 cout<<a-0.1;
	 	 cout<<"\n The original value is : "<<e;
	 	 cout<<"\n Error in percentage is: ";
	 	 cout<<"\n"<<abs(((e-(a-0.1))/e)*100)<<" %";
	 }
	 if(a==m)
	 {
	   cout<<"\n the current value and the mean value is same so predicted value is";
     }
 
}
int main()
{
	input();
	mean();
	next();
	FILE *myFile= fopen("original15.txt", "r");

    //read file into array
    	   
    	fscanf(myFile, "%f,", &e);
		  fclose(myFile);
	predict();
}
