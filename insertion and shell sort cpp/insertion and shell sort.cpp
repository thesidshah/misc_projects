/*
C++ program to store second year percentage of students in array.Write a function for sorting array of floating point numbers in ascending order using:
a.Insertion sort
b.Shellsort and display top 5 scores*/

#include<iostream>
using namespace std;

class sort
{
	public:
	int i,j,n;
	float a[10],temp;
 
	void insertion()
 	{
 	 	cout<<"\n\nHow many student's percentage do you want to enter? ::";
  		cin>>n;

  		cout<<"\nEnter the percentage::"<<endl;
  		for(i=0;i<n;i++)
   			cin>>a[i];
   			
   			
  		for(i=1;i<=n-1;i++)
  		{
  			 temp=a[i];
  			 j=i-1;
   			while(j>=0&&a[j]>temp)
   			{
   				 a[j+1]=a[j];
   				 j=j-1;
   			}
   			a[j+1]=temp;
  		}
  		//displaying the sorted list
  		cout<<"\Top five percentages sorted by Insertion sort are::"<<endl;
  		for(i=0;i<5;i++)
  			cout<<a[i]<<" ";
 	}

 	void shell()
 	{ 
  		int d,k;
  		float value;
  		cout<<"\n\nHow many student's percentage do you want to enter?";
  		cin>>n;

  		cout<<"\nEnter the percentage::"<<endl;
  		for(i=0;i<n;i++)
  			cin>>a[i];
  
  		//sorting by shell sort
  		d=(n+1)/2;
  		for(i=d;i>=1;i=i/2)//finding distance
  		{
  			 for(j=i;j<=n-1;j++) //One complete iteration
   			{
    				value=a[j];
    				k=j-i;
    				while(k>=0&&value<a[k])
    				{  
     					a[k+i]=a[k];
     					k=k-i;
    				}
    				a[k+i]=value;
   			}
  		}
  		//displaying the sorted list
  		cout<<"\nThe top five percentages sorted by shell sort are::"<<endl;
  		for(i=0;i<5;i++)
  			cout<<a[i]<<" "; 
 	}

};


int main()
{

	int choice; 
 	sort s;

 	do
 	{
 		cout<<"\n\n ...........MENU.........."<<endl;
 		cout<<"\n1.Insertion sort"<<endl;
 		cout<<"\n2.Shell sort"<<endl;
 		cout<<"\n3.exit"<<endl;
 		cout<<"\nEnter your choice::";
 		cin>>choice;
 
 		switch(choice)
 		{
  			case 1: s.insertion();
  				break;
   
  			case 2: s.shell();
  				break;
 
 		}
 	}while(choice!=3);
  
  	return 0;

}




