#include <iostream>

using namespace std;

struct Node
{
	char data;
	Node* prev;
	Node* next;
};

class DoublyLinkedList
{
	private:
	int count;
	Node* header;
	Node* trailer;
	Node* curser;
	
	public:
	DoublyLinkedList()
	{
		count=0;
		header=new Node{'0', NULL, NULL};
		trailer=new Node{'0', NULL, NULL};
		curser=new Node{'0', NULL, NULL};
		header->next=trailer;
		trailer->prev=header;
		curser->next=trailer;
		curser->prev=header;
	}
	
	~DoublyLinkedList()
	{
		while(!empty()){
			pop_front();
		}
		
		delete header;
		delete trailer;
	}
	
	void push_left(char val)
	{
		Node* new_node = new Node{val, curser->prev, curser->next};
		new_node->prev->next=new_node;
		new_node->next->prev=new_node;
		count++;
		curser->prev=curser->prev->next;
	}
	
	void moveleft()
	{
		if(curser->prev!=header)
		{
			curser->next=curser->prev;
			curser->prev=curser->prev->prev;
		}
	}
	
	void moveright()
	{
		if(curser->next!=trailer){
			curser->prev=curser->next;
			curser->next=curser->next->next;
		}
	}
	
	void erase(Node* p)
	{
		p->prev->next=p->next;
		p->next->prev=p->prev;
		curser->prev=p->prev;
		delete p;
		count--;
	}
	
	void pop_front()
	{
		if(!empty())
			erase(header->next);
	}
	
	void pop_left()
	{
		if(!empty() && curser->prev!=header)
		{
			erase(curser->prev);
		}
	}
	
	void print_all()
	{
		Node* curr=header->next;
		
		while(curr!=trailer){
			cout<<curr->data;
			curr=curr->next;
		}
		
		cout<<endl;
	}
	
	bool empty() const
	{
		return count==0;
	}
};

int main()
{
	int round;
	cin>>round;
	
	for(int i=0;i<round;i++)
	{
		string sentence = "";
    	cin >> sentence;

    	DoublyLinkedList ll;
	
		for(int j=0;j<sentence.length();j++)
		{
			char order=sentence[j];
		
			switch(order)
			{
				case '<':
					ll.moveleft();
					break;
				case '-':
					ll.pop_left();
					break;
				case '>':
					ll.moveright();
					break;
				default:
					ll.push_left(sentence[j]);
					break;
			}
		
		}
		ll.print_all();
	
		
	}
	
	
}