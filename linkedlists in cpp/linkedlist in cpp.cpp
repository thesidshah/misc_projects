/*
Problem Statement: Write C/C++ program to store two sets using linked list. compute and
display-

1. Set of students who like either vanilla or butterscotch or both
2. Set of students who like both vanilla and butterscotch
3. Set of students who like only vanilla not butterscotch
4. Set of students who like only butterscotch not vanilla
5. Number of students who like neither vanilla nor butterscotch.
*/





#include <iostream>
using namespace std;
class clIce
{
public:
		int iNoIceCount,iRoll,iNo,iV,iB;
		clIce *pntVHead,*pntVTmp,*pntVNext,*pntBHead,*pntBTmp,*pntBNext;

		clIce()															
		{
			pntVHead=NULL;
			pntBHead=NULL;												// init heads to null
			iNoIceCount=0;												// init no IceCream counter to zero
		}
		
		void fnGet();
		void fnVorB();
		void fnVandB();
		void fnV();
		void fnB();
		void fnNo();
};



void clIce::fnGet()														// creating LL according top I/P
{
	int i;
	cout<<"\n No of Student(s): ";
	cin>>iNo;
	for (i=0;i<iNo;i++)
	{
		cout<<"\n\n\nStudent"<<(i+1)<<" : ";



		cout<<"\nVanilla (1/0) : ";
		cin>>iV;


		if(iV==1)
		{	
			if (pntVHead==NULL)
			{
				pntVHead=new clIce;
				pntVTmp=pntVHead;
			}
			else
			{
				pntVTmp->pntVNext=new clIce;
				pntVTmp=pntVTmp->pntVNext;
			}
			pntVTmp->iRoll=i+1;
			pntVTmp->pntVNext=NULL;
		}


		cout<<"\nButterScotch (1/0) : ";
		cin>>iB;


		if(iB==1)
		{	
			if (pntBHead==NULL)
			{
				pntBHead=new clIce;
				pntBTmp=pntBHead;
			}
			else
			{
				pntBTmp->pntBNext=new clIce;
				pntBTmp=pntBTmp->pntBNext;
			}
			pntBTmp->iRoll=i+1;
			pntBTmp->pntBNext=NULL;

			if(iV==1)
			{
				pntBTmp->iRoll=0-(pntBTmp->iRoll);
				pntVTmp->iRoll=0-(pntVTmp->iRoll);
			}
		}

		if(iV==0&&iB==0)
		{
			iNoIceCount++;
		}
	}
}

void clIce::fnVorB()													// for Vanilla or ButterScotch
{
	pntVTmp=pntVHead;
	pntBTmp=pntBHead;

	cout<<"\n\n\n\n\nStudent who like eigther Vanilla or ButterScotch:	{ ";
	while(pntVTmp!=NULL)
	{
		if(pntVTmp->iRoll<0)
		{
			cout<<0-(pntVTmp->iRoll)<<", ";
			pntVTmp=pntVTmp->pntVNext;
		}
		else
		{
			cout<<pntVTmp->iRoll<<", ";
			pntVTmp=pntVTmp->pntVNext;
		}
	}

	while(pntBTmp!=NULL)
	{
		if(pntBTmp->iRoll>0)
		{
			cout<<pntBTmp->iRoll<<", ";
		}
		pntBTmp=pntBTmp->pntBNext;
	}

	cout<<"}.\n";
}

void clIce::fnVandB()													// for Vanilla and ButterScotch
{
	pntBTmp=pntBHead;
	cout<<"\n\nStudent who like Vanilla and ButterScotch:	{ ";
	while(pntBTmp!=NULL)
	{
		if(pntBTmp->iRoll<0)
		{
			cout<<0-(pntBTmp->iRoll)<<", ";
		}
		pntBTmp=pntBTmp->pntBNext;
	}
	cout<<"}.\n";
}

void clIce::fnV()														// for only Vanilla 
{
	pntVTmp=pntVHead;
	cout<<"\n\nStudent who like Vanilla only:	{ ";
	while(pntVTmp!=NULL)
	{
		if(pntVTmp->iRoll>0)
		{
			cout<<pntVTmp->iRoll<<", ";
		}
		pntVTmp=pntVTmp->pntVNext;
	}
	cout<<"}.\n";
}

void clIce::fnB()														// for only ButterScotch
{
	pntBTmp=pntBHead;
	cout<<"\n\nStudent who like ButterScotch only:	{ ";
	while(pntBTmp!=NULL)
	{
		if(pntBTmp->iRoll>0)
		{
			cout<<pntBTmp->iRoll<<", ";
		}
		pntBTmp=pntBTmp->pntBNext;
	}
	cout<<"}.\n";
}

void clIce::fnNo()														// for no IceCream
{
	cout<<"\n\nNo of students like no IceCream: "<<iNoIceCount<<"\n\n";
}

int main()
{
	clIce objIce;														//Init Object
	objIce.fnGet();
	objIce.fnVorB();
	objIce.fnVandB();
	objIce.fnV();
	objIce.fnB();
	objIce.fnNo();
	return 0;
}

/*
OUTPUT:



 No of Student(s): 10 



Student1 : 
Vanilla (1/0) : 1  

ButterScotch (1/0) : 0



Student2 : 
Vanilla (1/0) : 0

ButterScotch (1/0) : 1



Student3 : 
Vanilla (1/0) : 1

ButterScotch (1/0) : 1



Student4 : 
Vanilla (1/0) : 0

ButterScotch (1/0) : 0



Student5 : 
Vanilla (1/0) : 1

ButterScotch (1/0) : 0



Student6 : 
Vanilla (1/0) : 0

ButterScotch (1/0) : 1



Student7 : 
Vanilla (1/0) : 1

ButterScotch (1/0) : 1



Student8 : 
Vanilla (1/0) : 0

ButterScotch (1/0) : 0



Student9 : 
Vanilla (1/0) : 1

ButterScotch (1/0) : 0



Student10 : 
Vanilla (1/0) : 0

ButterScotch (1/0) : 1





Student who like eigther Vanilla or ButterScotch:	{ 1, 3, 5, 7, 9, 2, 6, 10, }.
Student who like Vanilla and ButterScotch:	{ 3, 7, }.
Student who like Vanilla only:	{ 1, 5, 9, }.
Student who like ButterScotch only:	{ 2, 6, 10, }.
No of students like no IceSream: 2



*/