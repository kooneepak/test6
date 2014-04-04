#ifndef __EVALUATE_H__
#define __EVALUATE_H__
#include "Stack.h"
#include "Token.h"

void tryEvaluateOperatorsOnStackThenPush(Stack *dataStack ,Stack *operatorStack , OperatorToken *operator);
void evaluateAlloperatorOnStack(Stack *operatorStack , Stack *dataStack);
void evaluateOperator(Stack *dataStack , OperatorToken *operatorToken);


#endif //__EVALUATE_H__