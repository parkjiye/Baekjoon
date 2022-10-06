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
	}
	
	~DoublyLinkedList()
	{
		while(!empty()){
			pop_front();
		}
		
		delete header;
		delete trailer;
	}
	
	void insert(Node* p, char val)
	{
		Node* new_node = new Node{val, p->prev, p};
		new_node->prev->next=new_node;
		new_node->next->prev=new_node;
		count++;
	}
	
	void push_back(char val)
	{
		insert(trailer, val);
		curser->prev=trailer->prev;
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
	string sentence = "";
    cin >> sentence;

    //cout << sentence.length() << endl;
    DoublyLinkedList ll;
	
	for(int i=0; i<sentence.length();i++){
		ll.push_back(sentence[i]);
	}
	
	//ll.print_all();
	
	int round;
	cin>>round;
	
	for(int i=0;i<round;i++)
	{
		char order;
		string letter;
		cin>>order;
		
		switch(order)
		{
			case 'P':
				cin>>letter;
				//cout<<letter<<endl;
				ll.push_left(letter[0]);
				break;
			case 'L':
				ll.moveleft();
				break;
			case 'B':
				ll.pop_left();
				break;
			case 'D':
				ll.moveright();
				break;
			default:
				break;
		}
		
	}
	
	ll.print_all();

}