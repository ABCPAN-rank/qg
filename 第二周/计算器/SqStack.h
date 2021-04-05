#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef enum Status {
    ERROR = 0, SUCCESS = 1
} Status;

typedef int ElemType;

typedef struct SqStack {
    ElemType *elem;
    int top;
    int size;
} SqStack;


/*！
 * @name    Status initStack(SqStack *s,int sizes)
 * @param   init Stack
 * @return  Status
 */
Status initStack(SqStack *s, int sizes);

/*!
 * @name   Status isEmptyStack(SqStack *s)
 * @param  s Sqstack *
 * @return Status
 */
Status isEmptyStack(SqStack *s);

/*!
 * @name   Status getTopStack(SqStack *s,ElemType *e)
 * @param  s SqStack *
 * @param  e int *
 * @return Status
 */
Status getTopStack(SqStack *s, ElemType *e);

/*!
 * @name   Status clearStack(SqStack *s)
 * @param  s SqStack *
 * @return Status
 */
Status clearStack(SqStack *s);

/*!
 * @name   Status destroyStack(SqStack *s)
 * @param  s SqStack *
 * @return Status
 */
Status destroyStack(SqStack *s);

/*!
 * @name   Status stackLength(SqStack *s,int *length)
 * @param  s SqStack *
 * @param  length  int *
 * @return Status
 */
Status stackLength(SqStack *s, int *length);

/*!
 * @name  Status pushStack(SqStack *s,ElemType data)
 * @param s SqStack*
 * @param data   a value which will be push into Stack
 * @return Status
 */
Status pushStack(SqStack *s, ElemType data);

/*!
 * @name   Status popStack(SqStack *s,ElemType *data)
 * @param  s SqStack *
 * @param  data get the value which is popped by function
 * @return Status
 */
Status popStack(SqStack *s, ElemType *data);

/*!
 * @description print menu
 */
void menu();

#endif
