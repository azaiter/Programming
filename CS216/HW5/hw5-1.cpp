// hw5-1.cpp
//******************************************************************
// AUTHOR: Abdulrahman Zaiter
// COURSE TITLE: Programming II // COURSE NUMBER: CS216 // PROF NAME: Khandaker Abir Rahman
// ASSIGNMENT: HW5-1 // DUE DATE: 4-11-2016 // POSSIBLE POINTS: 25 Points
// PURPOSE:
//  a C++ program for a doubly linked list in C++. The data section of each node holds one integer value.
//  Operations (handled by a menu) are:
//  1) Insert: at the beginning, at the end, in the middle (position is specified by number. e.g., 1 for insert at second position, 2 for insert at third position and so on), and into an empty list.
//  2) Delete: the head, the tail, any node in the middle (position is specified by number. e.g., 1 for delete the second node, 2 for delete the third node and so on), and from an one-node list.
//  3) Show: To view the data in nodes
//*******************************************************************

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;

class Node
{
	private:
	int id;
	Node* next;
	Node* prev;
	
	public:
	void setNext(Node* in_Next);
	//*********************************************
	// Purpose: sets the next portion of the Node to point into the passed parameter Node.
	// Input: Node* in_Next
	// Pre: a declared Node and existence of another Node to point into in the parameter, it can be also a NULL pointer, also existence of next member in class.
	// Output: none.
	// Post: the next portion of the Node is set to point into the passed parameter Node.
	// Note: none.
	//*********************************************
	
	void setPrev(Node* in_Prev);
	//*********************************************
	// Purpose: sets the prev portion of the Node to point into the passed parameter Node.
	// Input: Node* in_Prev
	// Pre: a declared Node and existence of another Node to point into in the parameter, it can be also a NULL pointer, also existence of prev member in class.
	// Output: none.
	// Post: the prev portion of the Node is set to point into the passed parameter Node.
	// Note: none.
	//*********************************************

	void setData(int in_id=999, Node* in_next=NULL,Node* in_prev=NULL);
	//*********************************************
	// Purpose: sets the variables of the class ( id, next pointer, prev pointer) into the the passed parameters.
	// Input: int in_id, Node* in_next,Node* in_prev
	// Pre: a declared Node and existence of another Nodes to point into in the parameters, they can be also a NULL pointer, also proper data decleration.
	// Output: none.
	// Post: the variables of the class ( id, next pointer, prev pointer) are set into the the passed parameters.
	// Note: default values are indicated as follows: in_id=999, in_next=NULL, in_prev=NULL.
	//*********************************************
	
	
	int getId();
	//*********************************************
	// Purpose: returns  id.
	// Input: none
	// Pre: a properly declared Node and has data.
	// Output: none.
	// Post: id is returned.
	// Note: none.
	//*********************************************
	
	Node* getNext();
	//*********************************************
	// Purpose: returns pointer to next portion of the Node.
	// Input: none
	// Pre: a properly declared Node and has data.
	// Output: none.
	// Post: pointer to next portion of the Node is returned.
	// Note: none.
	//*********************************************
	
	Node* getPrev();
	//*********************************************
	// Purpose: returns pointer to prev portion of the Node.
	// Input: none
	// Pre: a properly declared Node and has data.
	// Output: none.
	// Post: pointer to prev portion of the Node is returned.
	// Note: none.
	//*********************************************
	
	Node(int in_id=999, Node* in_next=NULL,Node* in_prev=NULL);
	//*********************************************
	// Purpose: intializes and sets the variables of the class ( id, , next pointer, prev pointer) into the the passed parameters.
	// Input: int in_id, Node* in_next,Node* in_prev
	// Pre: a declared Node and existence of another Nodes to point into in the parameters, they can be also a NULL pointer, also proper data decleration.
	// Output: none.
	// Post: the variables of the class ( id, , next pointer, prev pointer) are initilized and set into the the passed parameters.
	// Note: default values are indicated as follows: in_id=999, in_fName="na", in_lName="na", in_next=NULL, in_prev=NULL.
	//*********************************************
};
	
void Node::setNext(Node* in_Next)
	//*********************************************
	// Purpose: sets the next portion of the Node to point into the passed parameter Node.
	// Input: Node* in_Next
	// Pre: a declared Node and existence of another Node to point into in the parameter, it can be also a NULL pointer, also existence of next member in class.
	// Output: none.
	// Post: the next portion of the Node is set to point into the passed parameter Node.
	// Note: none.
	//*********************************************
	{next = in_Next;}
	
void Node::setPrev(Node* in_Prev)
	//*********************************************
	// Purpose: sets the prev portion of the Node to point into the passed parameter Node.
	// Input: Node* in_Prev
	// Pre: a declared Node and existence of another Node to point into in the parameter, it can be also a NULL pointer, also existence of prev member in class.
	// Output: none.
	// Post: the prev portion of the Node is set to point into the passed parameter Node.
	// Note: none.
	//*********************************************
	{prev = in_Prev;}
	
void Node::setData(int in_id, Node* in_next,Node* in_prev)
	//*********************************************
	// Purpose: sets the variables of the class ( id, , next pointer, prev pointer) into the the passed parameters.
	// Input: int in_id, Node* in_next,Node* in_prev
	// Pre: a declared Node and existence of another Nodes to point into in the parameters, they can be also a NULL pointer, also proper data decleration.
	// Output: none.
	// Post: the variables of the class ( id, next pointer, prev pointer) are set into the the passed parameters.
	// Note: default values are indicated as follows: in_id=999, in_next=NULL, in_prev=NULL.
	//*********************************************
	
	{id = in_id; next = in_next; prev = in_prev;}
	
int Node::getId()
	//*********************************************
	// Purpose: returns  id.
	// Input: none
	// Pre: a properly declared Node and has data.
	// Output: none.
	// Post: id is returned.
	// Note: none.
	//*********************************************

	{return id;}
	
Node* Node::getNext()
	//*********************************************
	// Purpose: returns pointer to next portion of the Node.
	// Input: none
	// Pre: a properly declared Node and has data.
	// Output: none.
	// Post: pointer to next portion of the Node is returned.
	// Note: none.
	//*********************************************

	{return next;}
	
Node* Node::getPrev()
	//*********************************************
	// Purpose: returns pointer to prev portion of the Node.
	// Input: none
	// Pre: a properly declared Node and has data.
	// Output: none.
	// Post: pointer to prev portion of the Node is returned.
	// Note: none.
	//*********************************************

	{return prev;}
	
Node::Node(int in_id, Node* in_next,Node* in_prev)
	//*********************************************
	// Purpose: intializes and sets the variables of the class ( id, next pointer, prev pointer) into the the passed parameters.
	// Input: int in_id, Node* in_next,Node* in_prev
	// Pre: a declared Node and existence of another Nodes to point into in the parameters, they can be also a NULL pointer, also proper data decleration.
	// Output: none.
	// Post: the variables of the class ( id, next pointer, prev pointer) are initilized and set into the the passed parameters.
	// Note: default values are indicated as follows: in_id=999, in_next=NULL, in_prev=NULL.
	//*********************************************
	
	{id = in_id; next = in_next; prev = in_prev;}
	
	

class List
{
	private:
	Node * h;
	Node * c;
	Node * bc;
	Node * t;
	int cntItems;
	
	public:
	Node * getHead();
	//*********************************************
	// Purpose: returns the address of head variable.
	// Input: none
	// Pre: a declared Node class, existence of h variable in this class.
	// Output: none.
	// Post: the address of head variable is returned.
	// Note: none
	//*********************************************

	Node * getTail();
	//*********************************************
	// Purpose: returns the address of tail variable.
	// Input: none
	// Pre: a declared Node class, existence of t variable in this class.
	// Output: none.
	// Post: the address of tail variable is returned.
	// Note: none
	//*********************************************
	
	bool isEmpty();
	//*********************************************
	// Purpose: returns wether the List is empty or not.
	// Input: none
	// Pre: existence of cntItems variable in this class.
	// Output: none.
	// Post: a boolean data is returned to show wether the List is empty or not..
	// Note: none
	//*********************************************
	
	int size();
	//*********************************************
	// Purpose: returns the number of items of the List.
	// Input: none
	// Pre: a declared Node class, existence of cntItems variable in this class.
	// Output: none.
	// Post: the number of items of the List is returned.
	// Note: none
	//*********************************************
	
	List();
	//*********************************************
	// Purpose: intialize an empty List.
	// Input: none
	// Pre: a declared Node class.
	// Output: none.
	// Post: an empty List is initialized.
	// Note: none
	//*********************************************
	
	~List();
	//*********************************************
	// Purpose: destructing the List.
	// Input: none
	// Pre: a declared Node class.
	// Output: none.
	// Post: all Nodes in the List deleted.
	// Note: none
	//*********************************************
	
	void destruct();
	//*********************************************
	// Purpose: destructing the List.
	// Input: none
	// Pre: a declared Node class.
	// Output: none.
	// Post: all Nodes in the List deleted.
	// Note: none
	//*********************************************
	
	
	void pushHead(int in_id=999);
	//*********************************************
	// Purpose: inserts a new head for the List with the given passed parameters.
	// Input: in_id
	// Pre: a declared Node class.
	// Output: none.
	// Post:  a new head for the List is insrted with the given passed parameters.
	// Note: default data for the parameters as follows: in_id=999
	//*********************************************
	
	void pushTail(int in_id=999);
	//*********************************************
	// Purpose: inserts a new tail for the List with the given passed parameters.
	// Input: in_id
	// Pre: a declared Node class.
	// Output: none.
	// Post:  a new tail for the List is insrted with the given passed parameters.
	// Note: default data for the parameters as follows: in_id=999
	//*********************************************
	
	void show();
	//*********************************************
	// Purpose: shows the List in head to tail order.
	// Input: none
	// Pre: a declared Node class.
	// Output: none.
	// Post:  the List in head to tail order is showed on screen.
	// Note: none
	//*********************************************
	
	void showReverse();
	//*********************************************
	// Purpose: shows the List in tail to head order.
	// Input: none
	// Pre: a declared Node class.
	// Output: none.
	// Post:  the List in tail to head order is showed on screen.
	// Note: none
	//*********************************************
	
	void showByNode(Node* ptr);
	//*********************************************
	// Purpose: shows a List that has the given passed Node pointer.
	// Input: none
	// Pre: a declared Node class.
	// Output: none.
	// Post:  a List that has the given passed Node pointer is showed on screen.
	// Note: none
	//*********************************************
	
	Node* search(int in_id);
	//*********************************************
	// Purpose: returns a Node pointer to the searched id, otherwise returns NULL.
	// Input: int in_id
	// Pre: a declared Node class.
	// Output: none.
	// Post:  a Node pointer to the searched id is returned, otherwise it returns NULL.
	// Note: none
	//*********************************************
	
	Node* itemAt(int position);
	//*********************************************
	// Purpose: returns a Node pointer to the given position, otherwise returns NULL.
	// Input: int position
	// Pre: a declared Node class.
	// Output: none.
	// Post:  a Node pointer to the given position is returned, otherwise it returns NULL.
	// Note: none
	//*********************************************
	
	void removeHead();
	//*********************************************
	// Purpose: deletes the head of the List.
	// Input: none
	// Pre: a declared Node class.
	// Output: none.
	// Post:  the head of the List is removed.
	// Note: none
	//*********************************************
	
	void removeTail();
	//*********************************************
	// Purpose: deletes the tail of the List.
	// Input: none
	// Pre: a declared Node class.
	// Output: none.
	// Post:  the tail of the List is removed.
	// Note: none
	//*********************************************
	
	void remove(int id);
	//*********************************************
	// Purpose: deletes the Node object from the List of the passed id to the function.
	// Input: none
	// Pre: a declared Node class.
	// Output: none.
	// Post:  the object from the List of the passed id to the function is removed is deleted.
	// Note: none
	//*********************************************
	
	void push(Node *p=NULL, int in_id=999);
	//*********************************************
	// Purpose: inserts a new Node object into the List in a specific position with the given parameters.
	// Input: Node *p, in_id
	// Pre: a declared Node class.
	// Output: none.
	// Post: a new Node object into the List in a specific position with the given parameters is inserted.
	// Note: default data for the parameters as follows: Node *p=NULL, in_id=999
	//*********************************************
	
	void insertSort(int in_id=999);
	
};


Node * List::getHead()
	//*********************************************
	// Purpose: returns the address of head variable.
	// Input: none
	// Pre: a declared Node class, existence of h variable in this class.
	// Output: none.
	// Post: the address of head variable is returned.
	// Note: none
	//*********************************************

	{return h;}
	
Node * List::getTail()
	//*********************************************
	// Purpose: returns the address of tail variable.
	// Input: none
	// Pre: a declared Node class, existence of t variable in this class.
	// Output: none.
	// Post: the address of tail variable is returned.
	// Note: none
	//*********************************************

	{return t;}
	
bool List::isEmpty()
	//*********************************************
	// Purpose: returns wether the List is empty or not.
	// Input: none
	// Pre: existence of cntItems variable in this class.
	// Output: none.
	// Post: a boolean data is returned to show wether the List is empty or not..
	// Note: none
	//*********************************************

	{return (cntItems==0);}
	
int List::size()
	//*********************************************
	// Purpose: returns the number of items of the List.
	// Input: none
	// Pre: a declared Node class, existence of cntItems variable in this class.
	// Output: none.
	// Post: the number of items of the List is returned.
	// Note: none
	//*********************************************

	{return cntItems;}
	
List::List()
	//*********************************************
	// Purpose: intialize an empty List.
	// Input: none
	// Pre: a declared Node class.
	// Output: none.
	// Post: an empty List is initialized.
	// Note: none
	//*********************************************

	{
		t = NULL;
		h = t;
		c = t;
		cntItems = 0;
	}
		
void List::pushHead(int in_id)
	//*********************************************
	// Purpose: inserts a new head for the List with the given passed parameters.
	// Input: in_id
	// Pre: a declared Node class.
	// Output: none.
	// Post:  a new head for the List is insrted with the given passed parameters.
	// Note: default data for the parameters as follows: in_id=999
	//*********************************************

	{
		if (h==NULL)
		{
			h = new Node(in_id);
			t = h;
			cntItems += 1;
		}
		else
		{
		c = h;
		h = new Node(in_id);
		h-> setNext(c);
		c->setPrev(h);
		h->setPrev(NULL);
		cntItems += 1;
		}
	}
		
void List::pushTail(int in_id)
	//*********************************************
	// Purpose: inserts a new tail for the List with the given passed parameters.
	// Input: in_id
	// Pre: a declared Node class.
	// Output: none.
	// Post:  a new tail for the List is insrted with the given passed parameters.
	// Note: default data for the parameters as follows: in_id=999
	//*********************************************

	{
		if(isEmpty())
			pushHead(in_id);
		else
		{
			c = t;
			t = new Node(in_id);
			t-> setPrev(c);
			c->setNext(t);
			t->setNext(NULL);
			cntItems += 1;
		}
	}
	
void List::show()
	//*********************************************
	// Purpose: shows the List in head to tail order.
	// Input: none
	// Pre: a declared Node class.
	// Output: none.
	// Post:  the List in head to tail order is showed on screen.
	// Note: none
	//*********************************************

	{
		c = h;
		cout << left << setw(10) << "ID" << endl;
		while(c != NULL)
		{
			cout << left << setw(10) <<  c -> getId() << endl;
			c= c ->getNext();
		}
		
		system("pause");
	}
	
void List::showReverse()
	//*********************************************
	// Purpose: shows the List in tail to head order.
	// Input: none
	// Pre: a declared Node class.
	// Output: none.
	// Post:  the List in tail to head order is showed on screen.
	// Note: none
	//*********************************************

	{
		c = t;
		cout << left << setw(10) << "ID" << endl;
		while(c != NULL)
		{
			cout << left << setw(10) << c -> getId() << endl;
			c= c ->getPrev();
		}
		
		system("pause");
	}

void List::showByNode(Node* ptr)
	//*********************************************
	// Purpose: shows a List that has the given passed Node pointer.
	// Input: none
	// Pre: a declared Node class.
	// Output: none.
	// Post:  a List that has the given passed Node pointer is showed on screen.
	// Note: none
	//*********************************************

	{
		c = ptr;
		if(c != NULL)
		{
		cout << left << setw(10) << "ID" << endl;
		cout << left << setw(10) <<  c -> getId() << endl;
		system("pause");
		}
		else
		{
			cout << "Error!! Not Found ..." << endl;
			system("pause");
		}
	}
	
Node* List::search(int in_id)
	//*********************************************
	// Purpose: returns a Node pointer to the searched id, otherwise returns NULL.
	// Input: int in_id
	// Pre: a declared Node class.
	// Output: none.
	// Post:  a Node pointer to the searched id is returned, otherwise it returns NULL.
	// Note: none
	//*********************************************

	{
		c=h;
		while(c != NULL)
		{
			if (c->getId() == in_id)
				return c;
			else
				c = c->getNext();
		}
		return NULL;
	}

Node* List::itemAt(int position)
	//*********************************************
	// Purpose: returns a Node pointer to the given position, otherwise returns NULL.
	// Input: int position
	// Pre: a declared Node class.
	// Output: none.
	// Post:  a Node pointer to the given position is returned, otherwise it returns NULL.
	// Note: none
	//*********************************************

	{
		if(position < 0 || position >= size())
			return NULL;
		c = h;
		for (int i=0; i != position; i++)
			c = c->getNext();
		return c;
	}
	
void List::removeHead()
	//*********************************************
	// Purpose: deletes the head of the List.
	// Input: none
	// Pre: a declared Node class.
	// Output: none.
	// Post:  the head of the List is removed.
	// Note: none
	//*********************************************

	{
		if(isEmpty())
			return;
		c = h;
		h = h -> getNext();
		h -> setPrev(NULL);
		delete c;
		cntItems--;
	}
	
void List::removeTail()
	//*********************************************
	// Purpose: deletes the tail of the List.
	// Input: none
	// Pre: a declared Node class.
	// Output: none.
	// Post:  the tail of the List is removed.
	// Note: none
	//*********************************************

	{
		if(isEmpty())
			return;
		if (h == t)
		{
			h=NULL;
			t=NULL; 
			cntItems=0;
			return; 
		}
		c = itemAt(cntItems-2);
		c -> setNext(NULL);
		delete t;
		t = c;
		cntItems--;
	}
	
void List::remove(int id)
	//*********************************************
	// Purpose: deletes the Node object from the List of the passed id to the function.
	// Input: none
	// Pre: a declared Node class.
	// Output: none.
	// Post:  the object from the List of the passed id to the function is removed is deleted.
	// Note: none
	//*********************************************

	{
		if (isEmpty())  
		{
			cout << "Error, List is Empty!";
			return;
		}
		
		if (h==t && h->getId()==id)
		{
			h=NULL;
			t= NULL;
			cntItems=0;
			cout << "ID: " << id << " has been deleted succefully !" << endl;
			return;
		}
		if ( h->getId()==id )
		{
			removeHead();
			cout << "ID: " << id << " has been deleted succefully !" << endl;
			return;
		}
		if ( t->getId()==id )
		{
			removeTail();
			cout << "ID: " << id << " has been deleted succefully !" << endl;
			return;
		}
		
		Node * beforePtr=h;  // beforePtr trails currentPtr
		Node * currentPtr=h->getNext();
		Node * afterPtr=currentPtr->getNext();
		Node * tail = getTail();
		while (currentPtr != tail)
		{
			if (currentPtr->getId( ) == id)
			{ 
				beforePtr->setNext(afterPtr);
				afterPtr->setPrev(beforePtr);
		        delete currentPtr;
				cntItems--;
				cout << "ID: " << id << " has been deleted succefully !" << endl;
				return;
			}
		    else 
			{  
				beforePtr = currentPtr; 
				currentPtr = currentPtr->getNext();
				afterPtr = 	currentPtr->getNext();		
			}
		}
		cout << "Error !! ID not found ....";
		return;
	}
	
void List::push(Node* p, int in_id)
	//*********************************************
	// Purpose: inserts a new Node object into the List in a specific position with the given parameters.
	// Input: Node *p, in_id
	// Pre: a declared Node class.
	// Output: none.
	// Post: a new Node object into the List in a specific position with the given parameters is inserted.
	// Note: default data for the parameters as follows: Node *p=NULL, in_id=999
	//*********************************************

	{
		c = h;
		while(c !=NULL && c != p)
			 c = c->getNext();
		if (c != NULL) 
		{ // p is found
			if(c->getNext() != NULL) // if its not tail
			{
				Node* newNd = new Node(in_id);
				p->getNext()->setPrev(newNd);
				newNd -> setNext(p->getNext());
				p->setNext(newNd);
				newNd -> setPrev(p);
				cntItems++;
			}
			else //its in tail
				pushTail(in_id);
			cout << "ID " << in_id << " has been added succesfully." << endl;
		}
		else
		{
			cout << "Error!! Not Found, nothing added ..." << endl;
		}
	}
	
	
void List::destruct()
	//*********************************************
	// Purpose: destructing the List.
	// Input: none
	// Pre: a declared Node class.
	// Output: none.
	// Post: all Nodes in the List deleted.
	// Note: none
	//*********************************************
{
		while(!isEmpty())
		{
			removeTail();
		}
}
	
List::~List()
	//*********************************************
	// Purpose: destructing the List.
	// Input: none
	// Pre: a declared Node class.
	// Output: none.
	// Post: all Nodes in the List deleted.
	// Note: none
	//*********************************************
	{
		destruct();
	}

void List::insertSort(int in_id)
{
		c = h;
		if(isEmpty())
		{
			pushHead(in_id);
			return;
		}
		
		if(in_id <= h -> getId())
		{
			pushHead(in_id);
			return;
		}
		
		if(in_id >= t -> getId())
		{
			pushTail(in_id);
			return;
		}
		
		if(h->getNext() == t)
		{
			
		}
		
		while(c != t)
		{
			if((in_id >= c -> getId()) && (in_id <= c -> getNext() -> getId()))
			{
				push(search(c -> getId()), in_id);
				return;
			}
			c = c -> getNext();
		}		
	}
	
int main()
{
	//declaring the List
	List mainList;
	//declaring needed variables for the choices
	int choice = 0;
	int id = 0;
	int id_misc = 0;
	int position =0;
	
	//doing main menu loop. any other input other than 13 will be ignored.
	do
	{
		//clearing the screen and showing the menu
		system("cls");
		cout 
		<< "1) Show ID's List" << endl
		<< "2) Search by ID" << endl
		<< "3) Search by position" << endl
		<< "4) Insert after last item (tail)" << endl
		<< "5) Insert before first item (head)" << endl
		<< "6) Insert at id" << endl
		<< "7) Insert at position" << endl
		<< "8) Delete head" << endl
		<< "9) Delete tail" << endl
		<< "10) Delete at id" << endl
		<< "11) Delete at position" << endl
		<< "12) Destruct the List" << endl
		<< "13) Insert Sort By ID" << endl
		<< "14) Exit" << endl
		;
		
		// input data validation in order to make the program perfect
		for (;;) 
		{
			cout << "Please Select An Option ..."<< endl;
			if (cin >> choice) {
				break;
			} else {
				cout << "Please enter a valid integer" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}
		
		// main choices branching statments.
		// in this case if statments are used better than switch case statments.
	if (choice == 1) //1) Show ID List
	{
		//calling the function that does this job
		mainList.show();
	}
	else if (choice == 2) //2) Search by ID
		{
			//asking for needed data
			cout << "Enter ID: ";
			cin >> id;
			cout << endl;
			//calling the function that does this job
			mainList.showByNode(mainList.search(id));
		}
	else if (choice == 3)//3) Search by position
		{
			//asking for needed data
			cout << "Enter position number: ";
			cin >> position;
			cout << endl;
			//calling the function that does this job
			mainList.showByNode(mainList.itemAt(position));
		}
	else if (choice == 4)//4) Insert after last item (tail)
		{
			//asking for needed data
			cout << "Enter ID: ";
			cin >> id;
			//calling the function that does this job
			mainList.pushTail(id);
			cout << endl << "ID: " << id << " has been added after last item (tail)" << endl;
			system("pause");
		}
	else if (choice == 5)//5) Insert before first item (head)
		{
			//asking for needed data
			cout << "Enter ID: ";
			cin >> id;
			//calling the function that does this job
			mainList.pushHead(id);
			cout << endl << "ID " << id << " has been added before first item (head)" << endl;
			system("pause");

		}
	else if (choice == 6)//6) Insert at id
		{
			//asking for needed data
			cout << "Enter the ID that you want to add data after: ";
			cin >> id_misc;
			cout << endl << "Enter ID: ";
			cin >> id;
			//calling the function that does this job
			mainList.push(mainList.search(id_misc),id);
			system("pause");
		}
	else if (choice == 7) //7) Insert at position
		{
			//asking for needed data
			cout << "Enter the position of the ID that you want to add data after: ";
			cin >> position;
			cout << "Enter ID: ";
			cin >> id;
			cout << endl;
			//calling the function that does this job
			mainList.push(mainList.itemAt(position),id);
			system("pause");

		}
	else if (choice == 8) //8) Delete head
		{
			//calling the function that does this job
			mainList.removeHead();
			cout << "Head has been removed succefully." << endl;
			system("pause");
		}
	else if (choice == 9) //9) Delete tail
		{
			//calling the function that does this job
			mainList.removeTail();
			cout << "Tail has been removed succefully." << endl;
			system("pause");
		}
	else if (choice == 10) //10) Delete at id
		{
			//asking for needed data
			cout << "Enter ID to be deleted: ";
			cin >> id;
			cout << endl;
			//calling the function that does this job
			mainList.remove(id);
			system("pause");
		}
	else if (choice == 11) //11) Delete at position
		{
			//asking for needed data
			cout << "Enter position to be deleted: ";
			cin >> position;
			cout << endl;
			//validating inputting data
			if (mainList.itemAt(position) != NULL)
			{
				//if data seems to be okay
				//calling the function that does this job
				mainList.remove(mainList.itemAt(position)->getId());
			}
			else
			{
				//displaying error message otherwise
				cout << "Error !! Can't delete, position is incorrect !" << endl;
			}
			system("pause");
		}
	
	else if (choice == 12) //12) Delete at first name
		{
			mainList.destruct();
			cout << "List has been destructed succesfully !" << endl;
			system("pause");
		}
	else if (choice == 13)//5) Insert before first item (head)
		{
			//asking for needed data
			cout << "Enter ID: ";
			cin >> id;
			cout << endl;
			//calling the function that does this job
			mainList.insertSort(id);
			cout << "ID: " << id << " has been added using sorted addition." << endl;
			system("pause");
		}		
	}
	while(choice != 14); //15) Exit
	
	return 0;
}