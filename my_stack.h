#ifndef MY_STACK_H
#define MY_STACK_H

#define STACK_TYPE int
#define STACK_SIZE 100


class my_stack
{
public:
    my_stack();
    void push(STACK_TYPE value);
    void pop();
    int is_empty();
    int is_full();
    STACK_TYPE top();
private:
    STACK_TYPE stack[STACK_SIZE];
};

#endif // MY_STACK_H
