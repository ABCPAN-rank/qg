//
// Created by ABCPAN on 2021/4/5.
//

#ifndef C_TOOL_H
#define C_TOOL_H
#define MAXSIZE 50

/*!
 * @name   int  get_pri(int ope)
 * @param  ope  get operation sign
 * @return int  which can help us judge calculate method
 * @description get a precedence level about calculating
 */
int get_pri(int ope);

/*!
 * @name         void compute(SqStack *snum, int ope)
 * @param        snum a Stack which save number
 * @param        ope  save operation sign
 * @description  use ope and number to calculate
 */
void compute(SqStack *snum, int ope);

/*!
 * @name          void get_ope(SqStack *snum, SqStack *sope, int ope)
 * @param snum    a Stack which save number
 * @param sope    a Stack which save operation sign
 * @param ope     a value to save a operation sign which get from input
 * @description   a function which can help us get operation sign from input
 */
void get_ope(SqStack *snum, SqStack *sope, int ope);

/*!
 * @name          void meet_right(SqStack *snum, SqStack *sope)
 * @param snum    a Stack which save number
 * @param sope    a Stack which save operation sign
 * @description   a function which help us judge precedence level in a calculate
 */
void meet_right(SqStack *snum, SqStack *sope);


#endif //C_TOOL_H
