#include<iostream>

using namespace std;

struct Node
{
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList
{
private:
    int count;
    Node* header;
    

public:
    Node* trailer;
    DoublyLinkedList()
    {
        count=0;
        header=new Node{0, NULL, NULL};
        trailer=new Node{0, NULL, NULL};
        header->next=trailer;
        trailer->prev=header;
    }

    ~DoublyLinkedList()
    {
        while(!empty())
        {
            pop_front();
        }
        delete header;
        delete trailer;
    }

    void insert(Node *p, int val)
    {
        Node* new_node=new Node{val, p->prev, p};
        new_node->prev->next=new_node;
        new_node->next->prev=new_node;
        count++;
    }

    void push_front(int val)
    {
        insert(header->next, val);
    }

    void push_back(int val)
    {
        insert(trailer, val);
    }

    void erase(Node *p)
    {
        p->prev->next=p->next;
        p->next->prev=p->prev;
        delete p;
        count --;
    }

    void pop_front()
    {
        if(!empty())
            erase(header->next);
    }

    void pop_back()
    {
        if(!empty())
            erase(trailer->prev);
    }

    bool empty() const
	{
		return count == 0;
	}

    void print_all()
    {
        Node* curr = header->next;

        while(curr!=trailer)
        {
            std::cout<<curr->data<<" ";
            curr=curr->next;
        }

        std::cout<<std::endl;
    }

    void print_reverse();

};

int main()
{
    int number;
    cin>>number;
    DoublyLinkedList ll;
    int count;

    for(int i=1;i<=number;i++)
    {   
        cin>>count;
        if(i==1)
        {
            ll.push_front(i);
        }
        else if(count==0)
        {
            ll.push_back(i);
        }
        else if(count==i-1)
        {
            ll.push_front(i);
        }
        else
        {
            Node* node=ll.trailer->prev;

            while(count!=1)
            {
                node=node->prev;
                count--;
            }

            ll.insert(node, i);
        }

    }

    ll.print_all();
    

    
}