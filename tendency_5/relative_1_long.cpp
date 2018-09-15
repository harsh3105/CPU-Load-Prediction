#include<iostream>
#include<string.h>
#include<conio.h>
#include<math.h>
using namespace std;
float load[100];
int i,j,k,siz,x,y,u;
float a,s=0,s1=0,pg1=0,pg=0;
float m,m1;
float cons[100];
float adapt=0.5;
float turninc,norminc,normdec,turndec,turnincc,normincc,normdecc,turndecc,number,e;
float inc;
char t;
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
    for(j=0;j<5;j++)
     {
	 printf("\n load %d is %f",j+1,load[j]);
	 siz++;
    }
	for(x=1;x<siz;x++)
	{
		if(load[x]>load[x-1])
		 {
		 	 s=0;
			  for(y=0;y<x;y++)
		 	 {
		 	 	s=s+load[y];
			  }
			  s=s/x;
			norminc=cons[x-1]+((load[x]-load[x-1])-cons[x-1])*adapt;
			if(load[x]<s)
			   cons[x]=norminc;
			else
			  {
			    pg=0;
				for(y=0;y<x;y++)
			       {
				      if(load[y]>load[x])
				        {
				           pg++;
			            }
			       }   
			       pg=pg/x;
			 turninc=cons[x-1]*pg;
			 cons[x]=min(abs(norminc),abs(turninc));
		     }
		 }
		else
		 {
			s=0;
			for(y=0;y<x;y++)
			{
				 s=s+load[y];
			}
			s=s/x;
			normdec=cons[x-1]+((load[x-1]-load[x])-cons[x-1])*adapt;
		 if(load[x]<s)
		  {
		  	cons[x]=normdec; 
			}
		 else
		  {
		  	 pg=0;
			  for(y=0;y<x;y++)
		  	{
		  		if(load[y]<load[x])
		  		{
		  			pg++;
				  }
				  
			  }
			 pg=pg/x; 
			turndec=cons[x-1]*pg;
			cons[x]=min(abs(normdec),abs(turndec));
			}
				 	
		 }	    
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
		 {
		 	 s1=0;
			  for(y=0;y<siz-1;y+0)
		 	 {
		 	 	s1=s1+load[y];
			  }
			  s1=s1/siz;
			normincc=cons[siz-2]+((load[siz-1]-load[siz-2])-cons[siz-2])*adapt;
			if(load[siz-1]<s1)
			cons[siz-1]=normincc;
			else
			{
			pg1=0;
			for(y=0;y<siz-1;y++)
			{
				if(load[y]>load[siz-1])
				  {
				  pg1++;
			      }
			  }
			 pg1=pg1/siz-1;
			 turnincc=cons[siz-2]*pg1;
			 cons[siz-1]=min(abs(normincc),abs(turnincc));
		}
		}
		else
		 {
			s1=0;
			for(y=0;y<siz-1;y++)
			{
				 s1=s1+load[y];
			}
			s1=s1/siz;
			normdecc=cons[siz-2]+((load[siz-1]-load[siz-2])-cons[siz-2])*adapt;
		 if(load[siz-1]<s1)
		  {
		  	cons[siz-1]=normdecc; 
			}
		 else
		  {
		  	pg1=0;
			  for(y=0;y<siz-1;y++)
		  	{
		  		if(load[y]<load[siz-1])
		  		{
		  			pg1=pg1+1;
				  }
				  
			  }
			 pg1=pg1/siz-1; 
			turndecc=cons[siz-2]*pg1;
			cons[siz-1]=min(abs(normdecc),abs(turndecc));
			}
	     }
	 }


	     
void consp()
{
	 	for(i=0;i<siz;i++)
	 cout<<"\n cons["<<i<<"] is: "<<cons[i];
}

	     
void predict()
{
	 
	
	 if((load[siz-2]-load[siz-1])>0)
	 {
	 	 
		 cout<<"\n given current value is less than mean so predicted value will be: ";
	 	
		 cout<<a-cons[siz-1];
		 cout<<"\n The original value is : "<<e;
	 	 cout<<"\n Error in percentage is: ";
	 	 cout<<"\n"<<abs(((e-(a-cons[siz-1]))/e)*100)<<" %";
	 }
	 if((load[siz-1]-load[siz-2])>0)
	 {
	 	  
		  cout<<"\n given current value is greater than mean so predicted value will be: ";
	 	 cout<<a+cons[siz-1];
	 	 cout<<"\n The original value is : "<<e;
	 	 cout<<"\n Error in percentage is: ";
	 	 cout<<"\n"<<abs(((e-(a-cons[siz]-1))/e)*100)<<" %";
     }     
	 if(a==m)
	 {
	   cout<<"\n the current value and the mean value is same so predicted value is also same..";
	   cout<<"\n The original value is : "<<e;
	    cout<<"\n Error in percentage is 0 % ";
     } 
 	
    
 }
int main()
{
	cons[0]=1;
	input();
		mean();
		next();
		consp();
			FILE *myFile= fopen("A2.txt", "r");

    //read file into array
    	   
    	fscanf(myFile, "%f,", &e);
		  fclose(myFile);
		predict();
}	     
