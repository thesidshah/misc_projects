/*
Implement C++ program for expression conversion as infix to postfix and its evaluation
using stack based on given conditions
i. Operands and operator, both must be single character.
ii. Input Postfix expression must be in a desired format.
iii. Only '+', '-', '*' and '/ ' operators are expected.
*/
#include<iostream>
#define size 20
using namespace std;
class expression
{
	char nExp[40],stack[size];
	int top,j;
	float pEStack[size];
	public:
		expression()
		{
			top=-1;
			j=0;
		}
		void input();
		void getPostfix();
		void evaluation();
};
void expression :: input()
{
	cout<<"Enter the expression";
	cin>>nExp;
}
void expression :: getPostfix()
{
	int i;
	for(i=0;nExp[i]!='\0';i++)
	{	
		char a=nExp[i];
		if((a=='(')||(a=='+')||(a=='-')||(a=='*')||(a=='/'))
		{
			if(top!=size)
				stack[++top]=a;
		}
		else if(a==')')
		{
			if(top!=-1)
			{
				while(stack[top]!='(')
				{
					if((stack[top]=='+')||(stack[top]=='-')||(stack[top]=='*')||(stack[top]=='/'))
						if(top!=-1)
							nExp[j++]=stack[top--];
				}
				char ch=stack[top--];
			}
		}
		else
			nExp[j++]=a;
	}
	nExp[j]='\0';
	cout<<endl<<"Postfix Expression is:\t"<<nExp<<endl;
}
void expression :: evaluation()
{	
	int i=0,a;
	float left,right;
	top=-1;
	while(nExp[i]!='\0')
	{
		if( nExp[i]>=97 && nExp[i]<=122)
		{
			cout<<"\nEnter the Value for "<<nExp[i]<<"\t:";
			cin>>a;
			pEStack[++top]=a;
		}
		else if( nExp[i]=='+' ||  nExp[i]=='-' ||  nExp[i]=='*' ||  nExp[i]=='/' )
		{
			right=( float )pEStack[top--];
			left =( float )pEStack[top--];
			switch(nExp[i])
			{
				case '+':
					pEStack[++top]=left + right;
					break;
				case '-':
					pEStack[++top]=left - right;
					break;
				case '*':
					pEStack[++top]=left * right;
					break;
				case '/':
					pEStack[++top]=left / right;
					break;
			}
		}
		i++;
	}
	cout<<endl<<"Evaluation of Postfix is:" << pEStack[top--]<<endl;
}
int main()
{
	expression a;
	a.input();
	a.getPostfix();
	a.evaluation();
	return 0;
}
