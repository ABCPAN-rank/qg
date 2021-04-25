//
// Created by ABCPAN on 2021/4/24.
//
#include "binary_sort_tree.h"
#ifndef INC_LINKSTACK_H
#define INC_LINKSTACK_H

typedef enum LStatus {
    ERROR = 0,
    SUCCESS = 1
} LStatus;

typedef NodePtr LElemType;

typedef struct StackNode {
    NodePtr data;
    struct StackNode *next;
} StackNode, *LinkStackPtr;

typedef struct LinkStack {
    LinkStackPtr top;
    int count;
} LinkStack;

/*!
 * @description init a LinkStack
 * @param s     a pointer
 * @return      LStatus
 */
LStatus initLStack(LinkStack *s);

/*!
 * @description judge Is LinkStack empty ?
 * @param s     a pointer which point the Stack's top
 * @return      LStatus
 */
LStatus isEmptyLStack(LinkStack *s);

/*!
 * @description get Stack's top value and delaten't it
 * @param s     a pointer which point the Stack's top
 * @param e     receive the top value
 * @return      LStatus
 */
LStatus getTopLStack(LinkStack *s, LElemType *e);

/*!
 * @description clear Stack
 * @param s     a pointer which point the Stack's top
 * @return      LStatus
 */
LStatus clearLStack(LinkStack *s);

/*!
 * @description destory Stack
 * @param s     a pointer which point the Stack's pointer(help me free *S)
 * @return      LStatus
 */
LStatus destroyLStack(LinkStack **s);

/*!
 * @description get Stack length
 * @param s     a pointer which point the Stack's top
 * @param length receive the lenght about Stack
 * @return
 */
LStatus LStackLength(LinkStack *s, int *length);

/*!
 * @description push a value into a Stack
 * @param s     a pointer which point the Stack's top
 * @param data  the value which will be pushed into Stack
 * @return  LStatus
 */
LStatus pushLStack(LinkStack *s, LElemType data);

/*!
 * @description  pop a value from Stack
 * @param s     a pointer which point the Stack's top
 * @param data  receive the value which is popped from Stack
 * @return LStatus
 */
LStatus popLStack(LinkStack *s, LElemType *data);

/*!
 * @description print menu
 */


#endif //INC_LINKSTACK_H
