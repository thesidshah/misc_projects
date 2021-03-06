/*
  problem statement:Write C++ program for sparse matrix realization and operations on it- Transpose, Fast 
Transpose and addition of two matrices 
*/
#include<iostream>
using namespace std;
class funSprM
{
	private:
		int ia[4][4],is[10][3],t[10][3],f[10][3],h[10][3],add[10][3],p[4][4],a,b,i,j,k,r,c,ze;
		
	public:
		void Accept();
		void sparse();
		void simpleTranspose();
		void fastTranspose();
		void addSpaMatrix();
};
void funSprM:: addSpaMatrix()
{
	t[0][1]=4;
	t[0][0]=4;
	k=1;
	ze=0;
	cout<<"\n\n---------------Enter the entries in second matrix-------------"<<endl;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			cout<<"p["<<i<<"]["<<j<<"]=";
			cin>>p[i][j];
			if(p[i][j]!=0)
			{
				t[k][0]=i;
				t[k][1]=j;
				t[k][2]=p[i][j];
				k++;
				ze++;
			}
		}
	}
	cout<<"\n\n-------------SECOND MATRIX IS-----------";
	for(i=0;i<4;i++)
	{
		cout<<"\n[	";
		for(j=0;j<4;j++)
		{
			cout<<p[i][j]<<"	";
		}
		cout<<"]";
	}	
	t[0][2]=ze;	
	add[0][0]=add[0][1]=4;
	int z=0;//To store count of non zero element present in sum matrix
	i=j=k=1;
	while((i<=is[0][2])&&(j<=t[0][2]))
	{
		//ROW NUMBER NOT EQUAL
		if(is[i][0]<t[j][0])
		{
			add[k][0]=is[i][0];
			add[k][1]=is[i][1];
			add[k][2]=is[i][2];
			i++;
			k++;
			continue;
		}
		if(is[i][0]>t[j][0])
		{
			add[k][0]=t[j][0];
			add[k][1]=t[j][1];
			add[k][2]=t[j][2];
			j++;
			k++;
			continue;
		}
		//IF ROW NUMBER IS SAME COMPARE COLUMN
		if(is[i][1]<t[j][1])
		{
			add[k][0]=is[i][0];
			add[k][1]=is[i][1];
			add[k][2]=is[i][2];
			i++;
			k++;
			continue;
		}
		if(is[i][1]>t[j][1])
		{
			add[k][0]=t[j][0];
			add[k][1]=t[j][1];
			add[k][2]=t[j][2];
			j++;
			k++;
			continue;
		}
		// ELSE THIS MEANS ROW AND COLUMN NUMBER OF BOTH SPARSE MATRIX ARE SAME
		add[k][0]=is[i][0];
		add[k][1]=is[i][1];
		add[k][2]=is[i][2]+t[j][2];
		i++;
		j++;
		k++;
	}
	while(i<=is[0][2])
	{
		add[k][0]=is[i][0];
		add[k][1]=is[i][1];
		add[k][2]=is[i][2];
		i++;
		k++;
	}
	while(i<=t[0][2])
	{
		add[k][0]=t[i][0];
		add[k][1]=t[i][1];
		add[k][2]=t[i][2];
		j++;
		k++;
	}
	add[0][2]=k-1;
	cout<<"\n-------------SECOND SPARSE MATRIX GENERATED IS-----------";
	for(i=0;i<=t[0][2];i++)
	{
		cout<<"\n[	";
		for(j=0;j<3;j++)
		{
			cout<<t[i][j]<<"	";
		}
		cout<<"]";
	}	
	cout<<"\n-------------SUMMATION OF SPARSE MATRIXES GENERATED IS-----------";
	for(i=0;i<k;i++)
	{
		cout<<"\n[	";
		for(j=0;j<3;j++)
		{
			cout<<add[i][j]<<"	";
		}
		cout<<"]";
	}	
}
void funSprM::Accept()
{
	ze=0;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			cout<<"a["<<i<<"]["<<j<<"]=";
			cin>>ia[i][j];
			if(ia[i][j]>0)
			{
				ze++;
			}
		}	
	}
	
	cout<<"---------------First Matrix is---------------------\n";
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			cout<<ia[i][j]<<"\t";
		}
		cout<<"\n";
	}
	cout<<"no of non zero elements are="<<ze;
	cout<<"\n";	
}
void funSprM::sparse()
{
	is[0][0]=4;
	is[0][1]=4;
	is[0][2]=ze;
	k=1;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(ia[i][j]!=0)
			{
				is[k][0]=i;
				is[k][1]=j;
				is[k][2]=ia[i][j];
				k++;
			}
		}
	}
	cout<<"\n-------------SPARSE MATRIX GENERATED IS-----------";
	for(i=0;i<k;i++)
	{
		cout<<"\n[	";
		for(j=0;j<3;j++)
		{
			cout<<is[i][j]<<"	";
		}
		cout<<"]";
	}	
}      
void funSprM:: simpleTranspose()
{	
	f[0][1]=is[0][0];
	f[0][0]=is[0][1];
	f[0][2]=is[0][2];
	k=1;
	for(r=0;r<is[0][1];r++)
	{
		for(c=1;c<=is[0][2];c++)
		{
			if(r==is[c][1])
			{
				f[k][0]=r;
				f[k][1]=is[c][0];	
				f[k][2]=is[c][2];
				k++;
			}
		}
	}
	cout<<"\n---------------TRANSPOSED MATRIX IS--------------";
	for(i=0;i<k;i++)
	{
		cout<<"\n[	";
		for(j=0;j<3;j++)
		{
			cout<<f[i][j]<<"	";
		}
		cout<<"]";
	}
	cout<<endl;	
}
void funSprM:: fastTranspose()
{
	int cindex[4],index[4],m,n;
	for(i=0;i<4;i++)
	{	
		cindex[i]=0;
	}
	for(i=1;i<=ze;i++)//to count element in sparse matrix of same column
	{
		int col=is[i][1];
		cindex[col]++;
	}
	index[0]=1;
	for(i=1;i<4;i++)
	{
		index[i]=index[i-1]+cindex[i-1];
	}
	h[0][0]=is[0][1];
	h[0][1]=is[0][0];
	h[0][2]=is[0][2];
	int k=0; 
	for(j=1;j<h[0][2]+1;j++)
	{
		m=is[j][1];
		n=index[m];
		index[m]++;
		h[n][1]=is[j][0];
		h[n][0]=is[j][1];
		h[n][2]=is[j][2];
	}
	cout<<"\n---------------FAST TRANSPOSED MATRIX IS--------------";
	for(i=0;i<=ze;i++)
	{
		cout<<"\n[	";
		for(j=0;j<3;j++)
		{
			cout<<h[i][j]<<"	";
		}
		cout<<"]";
	}	
	
}
int main()
{
	funSprM M1,M2;
	M1.Accept();
	M1.sparse();
	M1.simpleTranspose();
	M1.fastTranspose();
	M1.addSpaMatrix();
	return 0;
}
