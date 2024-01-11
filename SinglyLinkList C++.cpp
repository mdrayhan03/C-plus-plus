/******************************************************************************
This is a Link List called SinglyLinkList. There we can create and add Node one 
after another. We can go after not previous. THere is a class Node which create
Node. In class SinglyLinkList we make a list with Nodes. This list is not limited.
Here appendleft(add new element in most left), appendright(add new element in most
right), popleft(delete most left element), search(check k element is in list), 
insert(add new element k after element pos), display(show the whole list in a line).
*******************************************************************************/
#include <iostream>

using namespace std;
class Node {    //Class Node 
public:         //Public Objective(variable) 
    int data; 
    Node* next; 
  
    // Default constructor 
    Node() 
    { 
        data = 0; 
        next = NULL; 
    } 
  
    // Parameterised Constructor 
    Node(int data) 
    { 
        this->data = data; 
        this->next = NULL; 
    } 
};

class SinglyLinkList {  //Class Single Linked List
  public:               //Public Objective(variable)
    Node* n;
    Node* head = NULL ;
    Node* tail = NULL ;
    Node* temp ;
    void appendleft(int k)  //Adding new element in left
    {
        n = new Node(k);
        temp = head ;
        head = n ;
        n->next = temp ;
        if (head->next == NULL){
            tail = head ;
        }
        return ;
    }
    
    void popleft()  //Deleting element from left
    {
        if (head == NULL){
            cout << "Nothing to pop." ;
            return ;
        }
        temp = head->next ;
        head = temp ;
    }
    
    void appendright(int k) //Adding element in right
    {
        n = new Node(k);
        tail->next = n ;
        tail = n ;
        if (head == NULL){
            appendleft(k) ;
        }
        return ;
    }
    
    bool search(int k)  //Searching k is in this list or not
    {
        Node* curr = head ;
        while (curr != NULL){
            if (curr->data == k){
                cout << k << " is in List." << endl ;
                return true ;
            }
            curr = curr->next ;
        }
        cout << k << " is not in List." << endl ;
        return false ;
    }
    
    void insert(int pos , int k)    //Adding an element after pos.
    {
        n = new Node(k);
        Node* curr = head ;
        while (curr != NULL){
            if (curr->data == pos){
                temp = curr->next ;
                curr->next = n ;
                n->next = temp ;
                return ;
            }
            curr = curr->next ;
        }
        cout << pos << " not in list." ;
    }
    
    void display()  //Showing whole List in a line
    {
        Node* curr = head ;
        while (curr != NULL ){
            cout<<curr->data<<" " ;
            curr = curr->next ;
        }
        cout << endl ;
    }
};

int main()
{
    SinglyLinkList l;
    for (int i = 1 ; i < 5 ; i++){
        l.appendleft(i) ;
        l.appendright(i) ;
    }
    l.popleft() ;
    l.insert(2 , 5) ;
    l.display() ;
    l.search(3) ;

    return 0;
}
