#include<iostream>
using namespace std;

class Node{
	private:
		int val;
		Node* next;
	public:
		void setval(int v)
		{
			val=v;
		}
		void setnextnode(Node* n)
		{
			next=n;
		}
		int getval()
		{
			return val;
		}
		Node* getnextnode()
		{
			return next;
		}
		
};
class edgeNode{
	private:
		int linkval;
		edgeNode* linknext;
	public:
		void setlinkval(int v)
		{
			linkval=v;
		}
		void setlinknextnode(edgeNode* ln)
		{
			linknext=ln;
		}
		int getlinkval()
		{
			return linkval;
		}
		edgeNode* getlinknextnode()
		{
			return linknext;
		}
		
};


class edgelist{
	private:
		edgeNode* ehead;
		edgeNode* ecurrent;
		int esize;
		public:
			edgelist()
			{
				ehead=NULL;
				ecurrent=NULL;
				esize=0;
			}
			
		void addedgenode(int e)
		{
			for(int i=0;i<e;i++)
			{
				int a;
				cout<<"Enter value of "<<i+1<<" edge: ";
				cin>>a;
				edgeNode* link=new edgeNode();
				link->setlinkval(a);
				if(esize==0)
				{
					link->setlinknextnode(NULL);
					ehead=link;
					ecurrent=ehead;
					esize++;
				}
				else
				{
					link->setlinknextnode(ecurrent->getlinknextnode());
					ecurrent->setlinknextnode(link);
					ecurrent=link;
					esize++;
				}		
			}
		}
		
		edgeNode* returnehead()
		{
			return ehead;
		}
		
		void printedge(edgeNode* ehead)
		{
			if ( ehead== NULL)
			{
				return ;
			}
			cout<< ehead->getlinkval()<<"  ";
			printedge(ehead->getlinknextnode());
			cout<<endl;
				
		}
};
class linkedgelist{
	private:
		Node* head;
		Node* current;
		int size;
		
	public:
		linkedgelist()
		{
			head=NULL;
			current=NULL;
			size=0;
		}
		edgelist p;
		void addnode(int s)
		{
			int v;
			int es;
			for(int i=0;i<s;i++) {
				cout<<"Enter Value of Node: ";
			cin>>v;
			Node* temp=new Node();
			temp->setval(v);
			if(size==0)
			{
				temp->setnextnode(NULL);
				head=temp;
				current=head;
				size++;			
			}
			else
			{
				temp->setnextnode(current->getnextnode());
				current->setnextnode(temp);
				current=temp;
				size++;
			}
			cout<<"How many edges of "<<i+1<<" node you want to enter :";
			cin>>es;
			p.addedgenode(es);
			}
		}
		
		
			
		Node* returnhead()
		{
			return head;
		}
		
			
		void PRINT(Node* head)
		{			
		    if ( head== NULL)
		    {
		    	return ;
			}	     
		    cout << head->getval() << " -> "; 
			p.printedge(p.returnehead());		
		    PRINT(head->getnextnode());
		}
		
		
};

int main ()
{
	linkedgelist ll;
	ll.addnode(2);
	ll.PRINT(ll.returnhead());
	
	
}


