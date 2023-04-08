
#include "TheStack.hpp"
#include <iostream>
using std::cout, std::cin, std::endl;

int main()
{
    Stack<int>st(5);
    if (st.isFull())
    {
        cout << "stack is full now" << endl;
    }
    if (st.isEmpty())
    {
        cout << "stack is empty now" << endl;
    }

    st.push(5), st.push(4), st.push(3), st.push(2), st.push(1);
    if (st.isFull())
    {
        cout << "stack is full now" << endl;
    }
    if (st.isEmpty())
    {
        cout << "stack is empty now" << endl;
    }
    system("pause");
    return 0;
}