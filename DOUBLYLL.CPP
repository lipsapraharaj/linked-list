#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
/*
 * Node Declaration
 */
template <class X>
struct node
{
    X info;
    struct node *next;
    struct node *prev;
}*start;
 
/*
 Class Declaration 
 */
template <class X>
class double_llist
{
    public:
        void add_begin(int value);
        void add_after(int value, int position);
        void add_last(int value)
        void delete_element(int value);
        void search_element(int value);
        void display_dlist();
        void count();
        void reverse();
        double_llist()
        ~double_llist()
        {
            start = NULL;  
        }
};
 
/*
 * Main: Conatins Menu
 */
int main()
{
    int choice, element, position;
    double_llist<int> dl;
    while (1)
    {
        cout<<endl<<"----------------------------"<<endl;
        cout<<endl<<"Operations on Doubly linked list"<<endl;
        cout<<endl<<"----------------------------"<<endl;         
        cout<<"1.Add at begining"<<endl;
        cout<<"2.Add at a position"<<endl;
        cout<<"3.Add at the end"<<endl;
        cout<<"4.Delete from front"<<endl;
        cout<<"5.Delete from a posititon"<<endl;
        cout<<"6.Delete from end"<<endl;
        cout<<"7.Display doubly linked list"<<endl;
        cout<<"8.Searching"<<endl;
        cout<<"9.Count the no. of elements"<<<endl;
        cout<<"10.Reverse the list"<<endl;
        cout<<"11.Exit";
        cout<<"Enter your choice : ";
        cin>>choice;
        switch ( choice )
        {
        
        case 1:
            cout<<"Enter the element: ";
            cin>>element;
            dl.add_begin(element);
            cout<<endl;
            break;
        case 2:
            cout<<"Enter the element: ";
            cin>>element;
            cout<<"Insert Element after postion: ";
            cin>>position;
            dl.add_after(element, position);
            cout<<endl;
            break;
         case 3:
            cout<<"Enter the element: ";
            cin>>element;
            cout<<"Insert Element at end ";
            cin>>position;
            dl.add_last(element, position);
            cout<<endl;
            break;
        case 4:
            if (start == NULL)
            {                      
                cout<<"List empty,nothing to delete"<<endl;   
                break;
            }
            cout<<"Enter the element for deletion: ";
            cin>>element;
            dl.delete_front(element);
            cout<<endl;
            break;
         case 5: 
            cout<<"Enter the element for deletion: ";
            cin>>element;
            dl.delete_pos(element);
            cout<<endl;
            break;
         case 6:
             cout<<"Enter the element for deletion: ";
            cin>>element;
            dl.delete_last(element);
            cout<<endl;
            break;
        case 7:
            dl.display_dlist();
            cout<<endl;
            break;
        case 8:
            dl.search();
            cout<<endl;
            break;
        case 9:
            dl.count();
            break;    
       
        case 10:
           dl.reverse();
           break;
         case 11:
            exit(1);
            break;
        default:
            cout<<"Wrong choice"<<endl;
      }
    }
    return 0;
}
 

/*
 * Destructor
 */

void double_llist<X>::~double_llist()
{

 struct node<X> *current = head;
	
	while (current != NULL)
	{
		struct node<X> *temp = current;
		current = current->next;
		(current->prev)->next = NULL;
		(temp->next)->prev = NULL;
		temp->next = NULL;
		current->prev = NULL;
		delete temp;
		head = current;
	}
	current = NULL;
	delete head;
	delete tail;
}

 
/*
 * Insertion at the beginning
 */
template <class X>
void double_llist<X>::add_begin(int value)
{
    if (start == NULL)
    {
        cout<<"First Create the list."<<endl;
        return;
    }
    struct node<X> *temp;
    temp = new(struct node);
    temp->prev = NULL;
    temp->info = value;
    temp->next = start;
    start->prev = temp;
    start = temp;
    cout<<"Element Inserted"<<endl;
}
 
/*
 * Insertion of element at a particular position
 */
template <class X>
void double_llist<X>::add_after(int value, int pos)
{
    if (start == NULL)
    {
        cout<<"First Create the list."<<endl;
        return;
    }
    struct node<X> *tmp, *q;
    int i;
    q = start;
    for (i = 0;i < pos - 1;i++)
    {
        q = q->next;
        if (q == NULL)
        {
            cout<<"There are less than ";
            cout<<pos<<" elements."<<endl;
            return;
        }
    }
    tmp = new(struct node);
    tmp->info = value;
    if (q->next == NULL)
    {
        q->next = tmp;
        tmp->next = NULL;
        tmp->prev = q;      
    }
    else
    {
        tmp->next = q->next;
        tmp->next->prev = tmp;
        q->next = tmp;
        tmp->prev = q;
    }
    cout<<"Element Inserted"<<endl;
}
 
/*
 * Deletion of element from the list
 */
template <class X>
void double_llist::delete_element(int value)
{
    struct node<X> *tmp, *q;

     /*first element deletion*/

void double_llist<X>::delete_front()
    if (start->info == value)
    {
        tmp = start;
        start = start->next;  
        start->prev = NULL;
        cout<<"Element Deleted"<<endl;
        free(tmp);
        return;
    }
    q = start;
    while (q->next->next != NULL)
    {   
        /*Element deleted in between*/

        void double_llist::delete_pos()
        if (q->next->info == value)  
        {
            tmp = q->next;
            q->next = tmp->next;
            tmp->next->prev = q;
            cout<<"Element Deleted"<<endl;
            free(tmp);
            return;
        }
        q = q->next;
    }
     /*last element deleted*/
     
     void double_llist::delete_last()
    if (q->next->info == value)    
    { 	
        tmp = q->next;
        free(tmp);
        q->next = NULL;
        cout<<"Element Deleted"<<endl;
        return;
    }
    cout<<"Element "<<value<<" not found"<<endl;
}
 

/*
 * Display elements of Doubly Link List
 */
template <class X>
void double_llist<X>::display_dlist()
{
    struct node<X> *q;
    if (start == NULL)
    {
        cout<<"List empty,nothing to display"<<endl;
        return;
    }
    q = start;
    cout<<"The Doubly Link List is :"<<endl;
    while (q != NULL)
    {
        cout<<q->info<<" <-> ";
        q = q->next;
    }
    cout<<"NULL"<<endl;
}

/*
 * Searching in Doubly Link List
 */
template <class X>
void double_llist<X>::search()
{
{
    X value, pos = 0;
    bool flag = false;
    if (start == NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    cout<<"Enter the value to be searched: ";
    cin>>value;
    struct node<X> *s;
    s = start;
    while (s != NULL)
    {
        pos++;
        if (s->info == value)
        {
            flag = true;
            cout<<"Element "<<value<<" is found at position "<<pos<<endl;
        }
        s = s->next;
    }
    if (!flag)
        cout<<"Element "<<value<<" not found in the list"<<endl;  
}
 
/*
 * Number of elements in Doubly Link List
 */
template <class X>
void double_llist<X>::count()
{ 	
    struct node<X> *q = start;
    int cnt = 0;
    while (q != NULL)
    {
        q = q->next;
        cnt++;
    }
    cout<<"Number of elements are: "<<cnt<<endl;
}

/*
 * Reverse Doubly Link List
 */
template <class X>
void double_llist<X>::reverse()
{
    struct node<X> *p1, *p2;
    p1 = start;
    p2 = p1->next;
    p1->next = NULL;
    p1->prev = p2;
    while (p2 != NULL)
    {
        p2->prev = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p2->prev; 
    }
    start = p1;
    cout<<"List Reversed"<<endl; 
}

