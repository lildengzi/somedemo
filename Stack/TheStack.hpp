#include <iostream>

#ifndef _THESTACK_HPP
#define _THESTACK_HPP

template<class DataType>
class Stack
{
private:
    DataType* stack_array; // 栈数组
    int stacksize; //栈空间
    int top; //栈顶指针
public:
    Stack(int size): stacksize(size), top(0) {
        this->stack_array = new DataType[stacksize];
    }

    Stack(const Stack& st, int size) {
        st->stacksize = size;
        st->stack_array = new DataType[stacksize];
    }
    
    Stack operator=(const Stack &st)
    {
        Stack newStack;
        newStack->stacksize = st.stacksize;
        newStack->top = st.top;
        newStack->stack_array = new DataType[stacksize];
        return newStack;
    }

    ~Stack() {
        delete[] stack_array;
        stack_array = nullptr;
    }

    bool isEmpty() const { //栈是否为空
        return top == 0;
    }

    bool isFull() const { //栈是否为满
        return top == stacksize;
    }

    bool push(const DataType& item) { //元素入栈
        if (top < stacksize)
        {
            stack_array[top++] = item; 
            return true;
        }
        return false;
    }

    bool pop(DataType& item) { //元素出栈
        if (top > 0)
        {
            item = stack_array[--top]; 
            return true;
        }
        return false;
    }
};

#endif // _THESTACK_HPP
