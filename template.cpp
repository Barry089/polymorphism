


#include <iostream>
using namespace std;
template <class T>
class Stack {
    private:
        int size;
        int top;
        T * space;
    public:
        Stack(int = 10);
        ~Stack()
        {
            delete [] space;
        }
        bool IsEmpty()
        {
            return top == size;
        }
        bool IsFull()
        {
            return top == 0;
        }
        bool push(const T&);
        T pop();
};
template <class T>
Stack<T>::Stack(int size)
{
    cout << "construct..." << endl;
    this->size = size;
    top = size;
    space = new T[size];
}
template <class T>
bool Stack<T>::push(const T& element)
{
    if (!IsFull())
    {
        space[--top] = element;
        return true;
    }
    return false;
}
template <class T>
T Stack<T>::pop()
{
    return space[top++];
}
int main()
{
    Stack<char> S1(4);
    S1.push('a');
    S1.push('b');
    S1.push('c');
    S1.push('d');
    S1.push('e');

    while (!S1.IsEmpty())
    {
        cout << S1.pop() << endl;
    }
    
}