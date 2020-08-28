#include <iostream>
#include <string>
//Prof Griffin forgot to #include <string>

//Using standard namespace
using namespace std;


//initialize array of 100 elements
int A[100];


///////////////////////////////////////////////////////
//      Struct:     Node
//      Description:Holds an int and a pointer to the
//                  next node. To be used in a linked
//                  list.
//      Params:     int. default is -1.
//      Use:        To be added to a linked list
////////////////////////////////////////////////////////
struct Node
{
    int x;
    Node *next;
    Node()
    {
        x = -1;
        next = NULL;
    }
    Node(int n)
    {
        x = n;
        next = NULL;
    }
};

/*****************************************************
 * Class:   List
 * Descr:   Linked nodes. Similar to an array
 * Params:  None
 * Use:     Holds a lot of integers
 * 
 * Functions:
 *          Insert()
 *          Pop()
 *          Print()
 *          PrintTail()
 *          Push()
******************************************************/
class List
{

/********************************************************
 * Private Members:
 *       Node pointer Head - points to front of list
 *         Node pointer Tail - points to end of list
 *         int Size - keeps track of size of list
*********************************************************/ 
  private:
    Node *Head;
    Node *Tail;
    int Size;

  public:
  //Constructor for class List
    List()
    {
        Head = Tail = NULL;
        Size = 0;
    }

/********************************************************
 * Function:    Push(int val)
 * Params:      int val
 * Description: Adds a node to the back of the list
 *********************************************************/
    void Push(int val)
    {
        // allocate new memory and init node
        Node *Temp = new Node(val);

        if (!Head && !Tail)
        {
            Head = Tail = Temp;
        }
        else
        {
            Tail->next = Temp;
            Tail = Temp;
        }
        Size++;
    }
/**************************************************************
 * Function:    Insert(int val)
 * Params:      int val
 * Description: Adds a node to the front of the list
*****************************************************************/
    void Insert(int val)
    {
        // allocate new memory and init node
        Node *Temp = new Node(val);

        // figure out where it goes in the list

        Temp->next = Head;
        Head = Temp;
        if (!Tail)
        {
            Tail = Head;
        }
        Size++;
    }
/********************************************************************
 * Function:    PrintTail()
 * Params:      None
 * Description: Prints the data in the last node of the list
***********************************************************************/
    void PrintTail()
    {
        cout << Tail->x << endl;
    }

    string Print()
    {
        Node *Temp = Head;
        string list;

        while (Temp != NULL)
        {
            list += to_string(Temp->x) + "->";
            Temp = Temp->next;
        }

        return list;
    }

    // not implemented but would usually take the last
    // element from the list and return the int that it contained
    int Pop()
    {
        Size--;
        return 0; 
    }

/***********************************************************
 * Function:        Operator+(const List)
 * Params:          referenced list
 * Description:     adds this list and another referenced list
 *                  to create 1 big list
 * Returns:         List
 ***********************************************************/
    List operator+(const List &Rhs)
    {
        // Create a new list that will contain both when done
        List NewList;

        // Get a reference to beginning of local list
        Node *Temp = Head;

        // Loop through local list and Push values onto new list
        while (Temp != NULL)
        {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

        // Get a reference to head of Rhs
        Temp = Rhs.Head;

        // Same as above, loop and push
        while (Temp != NULL)
        {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

        // Return new concatenated version of lists
        return NewList;
    }

    // Implementation of [] operator.  This function returns an
    // int value as if the list were an array.
    int operator[](int index)
    {
        Node *Temp = Head;

        if (index >= Size)
        {
            cout << "Index out of bounds, exiting";
            exit(0);
        }
        else
        {

            for (int i = 0; i < index; i++)
            {
                Temp = Temp->next;
            }
            return Temp->x;
        }
    }

    friend ostream &operator<<(ostream &os, List L)
    {
        os << L.Print();
        return os;
    }
};

int main(int argc, char **argv)
{
    List L1;
    List L2;

    for (int i = 0; i < 25; i++)
    {
        L1.Push(i);
    }

    for (int i = 50; i < 100; i++)
    {
        L2.Push(i);
    }

    //cout << L1 << endl;
    L1.PrintTail();
    L2.PrintTail();

    List L3 = L1 + L2;
    cout << L3 << endl;

    cout << L3[5] << endl;
    return 0;
}