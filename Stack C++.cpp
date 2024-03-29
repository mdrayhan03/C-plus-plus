/******************************************************************************
This is a 5 element Stack. Stack does last in first out like an array of book
standing one upon another.In Stack we can do isFull(All element occupied or 
not checker), isEmpty(Is any element left there checker), they are boolian 
function. Push(add new element in last), peek(take last element to use) , pop
(delete the last element), display(show the whole Stack in a line).
*******************************************************************************/
#include <iostream>

using namespace std;

class myStack{  //Class of Stack
    public:     //Making public Objective(variable)
        int n = 5 ;
        int arr[5] ;
        int index = 0 ;
        bool isFull()   //Stack full checking
        {
            if (index >= n){
                cout<<"Stack is full."<<endl ;
                return true ;
            }
            cout<<"Stack is not full."<<endl ;
            return false ;
        }
        bool isEmpty()  //Stack empty checking  
        {
            if (index < n){
                cout<<"Stack is empty."<<endl ;
                return true ;
            }
            cout<<"Stack is not empty."<<endl ;
            return false ;
        }
        void push(int k)    //Adding an element in Stack in last
        {   
            if (index == n){
                cout<<"Stack is full. Can't push."<<endl ;
                return ;
            }
            arr[index] = k ;
            index++ ;
            return ;
        }
        int peek()  //Peeking the last element from Stack
        {
            if (index <= 0){
                cout<<"Stack is empty. Nothing to peek."<<endl ;
                return 0 ;
            }
            cout<<arr[index - 1]<<endl ;
            return arr[index - 1] ;
        }
        void pop()  //Deletin the last element from Stack
        {
            if (index < 0){
                cout<<"Stack is empty. Nothing to pop."<<endl ;
                return ;
            }
            index-- ;
            return ;
        }
        void display()  //Showing the whole Stack in a line
        {
            if (index <= 0){
                cout<<"Stack is empty. Nothing to display."<<endl ;
            }
            for (int i=0 ; i<index ; i++){
                cout<<arr[i]<<" ";
            }
        }
    
};

int main()
{
    myStack s ;
    s.peek() ;
    s.push(5) ;
    s.peek() ;
    s.push(4) ;
    s.peek() ;
    s.push(3) ;
    s.peek() ;
    s.push(2) ;
    s.peek() ;
    s.push(1) ;
    s.peek() ;
    s.push(0) ;
    s.peek() ;
    s.display() ;
    s.isFull() ;
    s.pop() ;
    s.pop() ;
    s.pop() ;
    s.pop() ;
    s.pop() ;
    s.display() ;
    s.isEmpty() ;
    
    return 0;
}
