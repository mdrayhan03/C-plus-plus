/*************************************************************************************
This is a Link List called DoublyLinkList. There we can create and add Node one 
after another. We can go after and previous also. THere is a class Node which 
create Node. In class DoublyLinkList we make a list with Nodes. This list is not 
limited. Here appendleft(add new element in most left), appendright(add new element
in most right), popleft(delete most left element), popright(delete most right element),
search(check k element is in list), insert(add new element k after element pos),
display(show the whole list in a line), reverse_display(show the whole list reversly
in a line)
*************************************************************************************/
#include <iostream>

using namespace std;
class Node {    //class Node
public:         //Public Objective(variable)
    int data; 
    Node* next;
    Node* prev;
  
    // Default constructor 
    Node() 
    { 
        data = 0; 
        next = NULL; 
        prev = NULL;
    } 
  
    // Parameterised Constructor 
    Node(int data) 
    { 
        this->data = data; 
        this->next = NULL; 
        this->prev = NULL;
    } 
};

class DoublyLinkList {  //Class DoublyLinkList
public:                 //Public Objective(variable)
    Node* n;
    Node* head = NULL ;
    Node* tail = NULL ;
    Node* temp ;
    void appendleft(int k)  //Adding new element in left
    { 
        n = new Node(k);
        if (head != NULL){
            head->prev = n ;
            n->next = head ;
        }
        head = n ;
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
        head->prev = NULL ;
    }
    
    void appendright(int k) //Adding new element in right
    {
        n = new Node(k);
        tail->next = n ;
        n->prev = tail ;
        tail = n ;
        if (head == NULL){
            appendleft(k) ;
        }
        return ;
    }
    
    void popright() //Deleting element from right
    {
        if (tail == NULL){
            cout << "Nothing to pop." ;
            return ;
        }
        temp = tail->prev ;
        tail = temp ;
        tail->next = NULL ;
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
                n->prev = curr ;
                n->next = temp ;
                temp->prev = n ;
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
    
    void reverse_display()  //Showing whole List reversly in a line
    {
        Node* curr = tail ;
        while (curr != NULL ){
            cout<<curr->data<<" " ;
            curr = curr->prev ;
        }
        cout << endl ;
    }
    
};

int main()
{
    DoublyLinkList l;
    for (int i = 1 ; i < 5 ; i++){
        l.appendleft(i) ;
        l.appendright(i) ;
    }
    l.popleft() ;
    l.popright() ;
    l.insert(2 , 5) ;
    l.display() ;
    l.reverse_display() ;
    l.search(3) ;

    return 0;
}
