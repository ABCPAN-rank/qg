//
// Created by ABCPAN on 2021/4/3.
//
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef enum Status {
    ERROR = 0,
    SUCCESS = 1
} Status;

typedef int ElemType;

typedef struct StackNode {
    ElemType data;
    struct StackNode *next;
} StackNode, *LinkStackPtr;

typedef struct LinkStack {
    LinkStackPtr top;
    int count;
} LinkStack;

/*!
 * @description init a LinkStack
 * @param s     a pointer
 * @return      Status
 */
Status initLStack(LinkStack *s);

/*!
 * @description judge Is LinkStack empty ?
 * @param s     a pointer which point the Stack's top
 * @return      Status
 */
Status isEmptyLStack(LinkStack *s);

/*!
 * @description get Stack's top value and delaten't it
 * @param s     a pointer which point the Stack's top
 * @param e     receive the top value
 * @return      Status
 */
Status getTopLStack(LinkStack *s, ElemType *e);

/*!
 * @description clear Stack
 * @param s     a pointer which point the Stack's top
 * @return      Status
 */
Status clearLStack(LinkStack *s);

/*!
 * @description destory Stack
 * @param s     a pointer which point the Stack's pointer(help me free *S)
 * @return      Status
 */
Status destroyLStack(LinkStack **s);

/*!
 * @description get Stack length
 * @param s     a pointer which point the Stack's top
 * @param length receive the lenght about Stack
 * @return
 */
Status LStackLength(LinkStack *s, int *length);

/*!
 * @description push a value into a Stack
 * @param s     a pointer which point the Stack's top
 * @param data  the value which will be pushed into Stack
 * @return  Status
 */
Status pushLStack(LinkStack *s, ElemType data);

/*!
 * @description  pop a value from Stack
 * @param s     a pointer which point the Stack's top
 * @param data  receive the value which is popped from Stack
 * @return Status
 */
Status popLStack(LinkStack *s, ElemType *data);

/*!
 * @description print menu
 */
void menu();

#endif //LINKSTACK_LINKSTACK_H
