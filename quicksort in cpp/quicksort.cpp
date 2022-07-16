

#include<iostream>
using namespace std;

class quicksort
{
	int i,j;

	public:
		void quick(int *,int,int);
};

int main()
{
	int a[10],l,u,i;
	quicksort q;
	cout <<"\n Enter 10 elements: \n";
	
	for(i=0;i<10;i++)
		cin >> a[i];
	l=0;
	u=9;
	q.quick(a,l,u);
	cout <<"\n Sorted elements: \n";
	
	for(i=0;i<10;i++)
		cout << a[i] << " ";
}
 
void quicksort::quick(int a[],int l,int u)
{
	int p,temp;
	if(l<u)
	{
		p=a[l];
		i=l;
		j=u;
		while(i<j)
		{
			while(a[i] <= p && i<j )
				i++;
			while(a[j]>p && i<=j )
				j--;
			if(i<=j)
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
			temp=a[j];
			a[j]=a[l];
			a[l]=temp;
			quick(a,l,j-1);
			quick(a,j+1,u); 
		}
	}
