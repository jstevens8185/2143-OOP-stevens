///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Jered Stevens/Terry Griffin
// Email:            J.Stevens8185@gmailcom
// Label:            P01
// Title:            Array Based Stack Example
// Course:           2143
// Semester:         Fall 2020
//
// Description:
//          Example implementation of an array based stack that holds integers.
// Added methods: 
//          void Enlarge();
//          void Reduce();
//          void Error();
//          bool Empty();
//          bool Full();
//          void LoadFile(std::string input);
//          void setHalfFullTrue();
//          void Print(std::string outf);
//
// Usage:
//          Nothing special right now.
//
// Files:            
//       None
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <fstream>
#include "stack.h"
#include "stack.cpp"

//using namespace psl;
using namespace std;


/**
 * Person
 * 
 * Description:
 *      Example struct that represents a person.
 * 
 * Usage: 
 * 
 *  Person P1;
 * 
 *  P1.fname = "firstName";
 *  P1.lname = "lastName";
 *  P1.age = 99
 *  cout<<P1<<endl;
 * 
 *  Person P2("billy","bob",11);
 *  cout<<P2<<endl;
 */
struct Person {
    string fname;
    string lname;
    int age;

    Person();
    Person(string, string, int);

    friend ostream &operator<<(ostream &os, const Person p) {
        os << p.fname << "," << p.lname << " : " << p.age << endl;
        return os;
    }
};

/**
 * Constructor:
 *    Constructs the person structure
 * Params:
 *    void
 * 
 * Returns:
 *     void
 */   
Person::Person() {
    fname = "";
    lname = "";
    age = 0;
}

/**
 * Constructor:
 *    Constructs the person structure
 * Params:
 *    string    : first name
 *    string    : last name
 *    int       : persons age
 * 
 * Returns:
 *     void
 */ 
Person::Person(string f, string l, int a) {
    fname = f;
    lname = l;
    age = a;
}

int main() {

    ifstream in;
    in.open("input.txt");
    ofstream out;
    out.open("out.txt");

    Stack S1;           // calls default constructor
    //Stack S2(25);       // calls overloaded constructor

    // out << "Name:       Jered Stevens\n"
    //     << "Program:    P01\n"
    //     << "Date:       09/15/2020\n\n";

    S1.LoadFile("input.txt");
    S1.Print("out.txt");

    // cout << "Popped a: " << S1.Pop() << endl;
    // cout << "Popped a: " << S1.Pop() << endl;
    // cout << "Popped a: " << S1.Pop() << endl;
    // cout << "Popped a: " << S1.Pop() << endl;
    // cout << "Popped a: " << S1.Pop() << endl;
    
    //S1.Push(9);

    //S1.Print();           // old way to print!
    //cout << S1 << endl;     // cool way to print

    //Person P1;              // calls default constructor (no params)

    //P1.fname = "suzy";      // adds values to person P1
    //P1.lname = "queue";
    //P1.age = 14;

    //cout << P1 << endl;     // calls overloaded ostream method

    //Person P2("dudley", "doowright", 30);   // uses overloaded constructor

    //cout << P2 << endl;     // calls overloaded ostream method
}