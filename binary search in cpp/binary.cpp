#include<iostream>
#include<cstdlib>
#include<queue>
using namespace std;
struct node
{
	int data;
	node *left, *right;
};
class tree
{
	public :
		node *root;
		tree()
		{
			root=NULL;
		}
		node *create();
		void inorder(node *);
		void BFS(node *);
		node *copy(node *);
		
};
node *tree :: create()
{
	node *p;
	int x;
	cout<<"\nEnter data (-1 for NULL) : ";
	cin>>x;
	if(x==-1)
	{
		return NULL;
	}
	p=new node;
	p->data=x;
	p->left=NULL;
	p->right=NULL;
	cout<<"\nEnter Left child of "<<x<<" :  ";
	p->left=create();
	cout<<"\nEnter right chid of "<<x<<" :  ";
	p->right=create();
	return p;
}
void tree :: inorder(node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<root->data<<"  ";
		inorder(root->right);		
	}
}
void tree :: BFS(node *root)
{
	if(root==NULL)
	{
		cout<<"Tree empty ";
	}
	else
	{
		queue<node *>q;
		q.push(root);
		while(!q.empty())
		{
			node*curr=q.front();
			cout<<curr->data<<" ";
			if(curr->left!=NULL)
			q.push(curr->left);
			if(curr->right!=NULL)
			q.push(curr->right);
			q.pop();
		}
	}
}
node *tree :: copy(node *root)
{
	node *p;
	p=NULL;
	if(root!=NULL)
	{
		p=new node;
		p->data=root->data;
		p->left=copy(root->left);
		p->right=copy(root->right);
	}
	return p;
	
}
int main()
{
	tree t;
	int ch;
	while(1)
	{
		cout<<"\n1.Create \n2.Inorder Display \n3.BFS display \n4.Copy \n5.Exit";
		cout<<"\nENter your choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1 :
				t.root = t.create();
				break;
			case 2 :
				t.inorder(t.root);
				break;
			case 3 :
				t.BFS(t.root);
				break; 
			case 4 : 
				t.croot=t.copy(t.root);
				break;
			case 5 :
				exit(0);
				break; 
				
		}
	}
	return 0;
}
