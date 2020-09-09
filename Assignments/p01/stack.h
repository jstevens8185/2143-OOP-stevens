#pragma once
//#include "stack.cpp"




/**
 * Stack
 * 
 * Description:
 *      Integer array based stack implementation
 * 
 * Public Methods:
 *      - Stack()
 *      - Stack(int)
 *      - void Push()
 *      - int Pop()
 *      - bool empty()
 *      - bool full()
 *      - void Print()
 * 
 * Private Methods:
 *      - None
 * 
 * Usage: 
 * 
 *  Stack S;
 *  S.Push(80);
 *  S.Push(90);
 *  S.Print();
 *  int x = S.Pop();
 *      
 */
//namespace psl{
    class Stack {
        private:
            int *S;       //array pointer
            int capacity; //max stack size
            int initCapacity; // The initial capacity
            int top;      //current top (index)
            int size;     //current num items
            bool ReachedHalfFull;//Sets to true if stack reaches half of original capacity
            bool Enlarged;//Sets to true if stack is made bigger
            int Largest;
        public:
            /**
             * Stack:
             *    Constructor.
             * Params:
             *    void
             * 
             * Returns:
             *     Void
             */
            Stack();
            /**
             * Stack:
             *    Constructor.
             * Params:
             *    int : capacity
             * 
             * Returns:
             *     Void
             */
            Stack(int cap);

            /**
             * Push:
             *    Push item onto stack.
             * Params:
             *    int : data
             * 
             * Returns:
             *     Void
             */
            void Push(int data);

            /**
             * Pop:
             *    remove item from stack.
             * Params:
             *    void
             * 
             * Returns:
             *     int
             */
            int Pop();

            /**
             * Enlarge
             * Description:
             *    increase stack size
             * Params:
             *    void
             * Returns:
             *    bigger stack
             */

            void Enlarge();

            /**
             * Reduce
             * Description:
             *    decrease stack size
             * Params:
             *    void
             * Returns:
             *    smaller stack
             */
            void Reduce();

            /**
             * Error
             * Description:
             *    Dispays error message
             * Params:
             *    void
             * Returns:
             *    
             */
            void Error();

            /**
             * Empty:
             *    is the stack empty?
             * Params:
             *    void
             * 
             * Returns:
             *     bool : true == stack is empty
             */
            bool Empty();

            /**
             * Full:
             *    is the stack full?
             * Params:
             *    void
             * 
             * Returns:
             *     bool : true == stack is full
             */
            bool Full();
            
            /**
             * LoadFile:
             *    loads input file
             * Params:
             *    ifstream& in
             * 
             * Returns:
             *     void
             */
            void LoadFile(std::string input);        // Reads input

            void setHalfFullTrue();

            /**
             * Print:
             *    Used so we can inspect our stack.
             * Params:
             *    void
             * 
             * Returns:
             *     void
             */    
            void Print();

            /**
             * Print:
             *    Prints to output file.
             * Params:
             *    ofstream& outf
             * 
             * Returns:
             *     void
             */ 
            void Print(std::string outf);

            /**
             * Overloaded ostream <<
             *    Lets us print a stack using cout
             * Params:
             *    ostream &os   : instance of ostream passed in by reference
             *    const Stack   : instance of stack passed in using const so 
             *                    it cannot be changed
             * 
             * Returns:
             *     ostream 
             */
            friend std::ostream &operator<<(std::ostream &os, const Stack s) {
                os << "Overloaded!!" << std::endl;
                for (int i = s.top; i >= 0; i--) {
                os << s.S[i] << std::endl;
                }
                return os;
            }
    };
//}