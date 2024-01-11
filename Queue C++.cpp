/******************************************************************************
This is a 5 element Queue. Queue does first in first out like an array of ticket
line one after another.In Queue we can do isEmpty(Is any element left there 
checker), this is boolian function. Push(add new element in last), peek(take
first element to use) , pop(delete the first element), display(show the whole
Queue in a line).
*******************************************************************************/
#include <iostream>

using namespace std;

class myQueue { //class of Queue
    public:     //public Objective(variable)
        int n = 5 ;
        int arr[5] ;
        int index = 0 ;
        int start = 0 ;
        bool isEmpty()  //Queue empty checking
        { 
            if ((index - start) < n){
                return true ;
            }
            return false ;
        }
        void enqueue(int k)    //Adding new element in Queue in last
        {   
            if (isEmpty() == false){
                cout<<"Queue is full. Can't push."<<endl ;
                return ;
            }
            arr[index] = k ;
            index++ ;
            return ;
        }
        int peek()  //Peeking the first element from Queue
        {
            if (isEmpty() == false){
                cout<<"Queue is full. Nothing to peek."<<endl ;
                return 0 ;
            }
            cout<<arr[0]<<endl ;
            return arr[0] ;
        }
        void dequeue()  //Deleting the first element from Queue
        {
            if ((index - start) <= 0){
                cout<<"Queue is empty. Nothing to pop."<<endl ;
                index = 0 ;
                start = 0 ;
                return ;
            }
            start++ ;
            return ;
        }
        void display()  //Showing the whole Queue in a line
        {
            if ((index - start) <= 0){
                cout<<"Queue is empty. Nothing to display."<<endl ;
                return ;
            }
            for (int i = start ; i < index ; i++){
                cout<<arr[i]<<" " ;
            }
            cout << endl ;
            return ;
        }
};

int main()
{
    myQueue q;
    q.display() ;
    for (int i = 0 ; i < 7 ; i++){
        q.enqueue(i) ;
    }
    q.display() ;
    q.dequeue() ;
    q.dequeue() ;
    q.dequeue() ;
    q.dequeue() ;
    q.dequeue() ;
    q.dequeue() ;
    q.display() ;
    q.enqueue(9) ;
    q.display() ;
    
    return 0;
} 
