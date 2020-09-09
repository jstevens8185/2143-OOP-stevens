#pragma once
#include <iostream>
#include <fstream>
#include "stack.h"

using namespace std;
//using namespace psl;

Stack::Stack() {
    initCapacity = capacity = 10;          // set array size
    S = new int[capacity];  // allocate new memory
    top = -1;               // initialize top of stack
    size = 0;               // set stack to empty
    Stack::ReachedHalfFull = false;
}

/**
 * Stack:
 *    Constructor.
 * Params:
 *    int : capacity
 * 
 * Returns:
 *     Void
 */
Stack::Stack(int cap) {
    initCapacity = capacity = cap;         // set array size      
    S = new int[capacity];  // allocate new memory
    top = -1;               // initialize top of stack
    size = 0;               // set stack to empty
}

/**
 * Push:
 *    Push item onto stack.
 * Params:
 *    int : data
 * 
 * Returns:
 *     Void
 */
void Stack::Push(int data) {
    if (Stack::Full())
    {
        Stack::Enlarge();
        cout << "made the stack bigger\n";
    }
    top++;              // move top of stack up
    size++;             // increment size
    S[top] = data;      // add item to array
    cout << "pushed " << data << endl;
    if (size == (.5*capacity))
    {
        Stack::setHalfFullTrue();
    }
}

/**
 * Pop:
 *    remove item from stack.
 * Params:
 *    void
 * 
 * Returns:
 *     int
 */
int Stack::Pop() {
    if (Stack::Empty())
    {
        cout << "\n\nError: Stack empty!" << endl;
        return -1;
    }
    if (size <= (.5*capacity))
    {
        Stack::Reduce();
    }
    
    int data = S[top];  // pull item from stack
    top--;              // shrink the stack
    size--;             // update our size
    return data;        // send item back
}

/**
 * Enlarge
 * Description:
 *    increase stack size
 * Params:
 *    void
 * Returns:
 *    bigger stack
 */

void Stack::Enlarge(){
    //cout<<"Enlarge was called" << endl;

    
    int newCapacity = capacity*2;;
    int* array2 = new int[newCapacity];
    for(int i = 0; i < newCapacity; i++){
      array2[i]=S[i];
    }
  
    int* temp = S;
    capacity = newCapacity;
    
    // if(Size > Largest){         //Keep track of how big array gets
    //   Largest = Size;
    // }

    S = array2;
    delete []temp;
    Enlarged = true;
   // cout << Enlarged <<endl;

  
}

/**
 * Reduce
 * Description:
 *    decrease stack size
 * Params:
 *    void
 * Returns:
 *    smaller stack
 */
void Stack::Reduce(){
   


    if(Enlarged && capacity>initCapacity)
    {
        //cout << "Top is: "<< Top << endl;
        //cout << "Size is: " << Size << endl;

        int newSize = (capacity * .5);

        //cout << "newSize is: " << newSize << endl;
        //cout << "before a new array is made" << endl;

        int* smallerArray = new int[newSize];
        capacity = newSize;
        //cout << endl <<"after a new array is made" << endl;


        for(int i = 0; i < capacity; i++){      //changed from i < top
        smallerArray[i]=S[i];             
        //cout << smallerArray[i]<<endl;
        }
    
        //cout<<"Reduce was called" << endl << endl;
        // cout << "Top is: " << A[Top] << endl;

        int* temp = S;                    //<-Here is the problem*
        S = smallerArray;                 //<-
        delete[] temp;                    //<- *go to line 184 for problem
        return;
    }
    else if(!Enlarged){
        cout << "Stack has not been enlarged" << endl;
        return;
    }
    else if(capacity<=initCapacity){
        cout<<"Stack cannot shrink anymore" << endl;
    }
    else
        Error();
    return;
}
/**
 * Error
 * Description:
 *    Dispays error message
 * Params:
 *    void
 * Returns:
 *    
 */
void Stack::Error(){
    cout << "There was an error\n\n";
    return;
}

/**
 * Empty:
 *    is the stack empty?
 * Params:
 *    void
 * 
 * Returns:
 *     bool : true == stack is empty
 */
bool Stack::Empty() {
    //return size == 0;
    return top == -1;
}

/**
 * Full:
 *    is the stack full?
 * Params:
 *    void
 * 
 * Returns:
 *     bool : true == stack is full
 */
bool Stack::Full() {
    return top == capacity - 1;
}

void Stack::setHalfFullTrue(){
    ReachedHalfFull = true;
    if (ReachedHalfFull)
    {
        cout << "halfFull is now true\n";
    }
    
    
    return;
}

void Stack::LoadFile(std::string input){
    ifstream in;
    in.open(input);
    ofstream out;
    out.open("out.txt");

    // Load the stack from infile
    while(!in.eof()){
 
        int data;
        string useless;
        in >> useless >> data;
        if(data > 0){
            Push(data);
            //cout << "data is: " << data << endl;
        }
        else{
            Pop();
        }
    }
    cout<<"data loaded" << endl;
  return;
}

/**
 * Print:
 *    Used so we can inspect our stack.
 * Params:
 *    void
 * 
 * Returns:
 *     void
 */    
void Stack::Print() {
    for (int i = top; i >= 0; i--) {
        cout << S[i] << endl;
    }
}

void Stack::Print(string outf){
    ofstream out;
    out.open(outf);
    //out << "in Print";
    for (int i = top; i >= 0; i--) {
        out << S[i] << endl;
    }
}

