#include <stdio.h>
#include <string.h>
#include "Stack.h"
#include "Token.h"
#include "createNumberToken.h"
#include "Evaluate.h"


void evaluateOperator(Stack *dataStack ,  OperatorToken *opeToken){

	NumberToken *answer;
	
	NumberToken *first =(NumberToken*)pop(dataStack);
	NumberToken *second =(NumberToken*)pop(dataStack);
	
	switch(opeToken->name[0])
	{	
		case '*':
			answer=createNumberToken(first->value*second->value);
		break;
		
		case '/':
			answer=createNumberToken(first->value/second->value);
		break;
		case '+':
			answer=createNumberToken(first->value+second->value);
		break;	
		
		case '-':
			answer=createNumberToken(first->value-second->value);
		break;
		
		case '&':
			answer=createNumberToken(first->value&second->value);
		break;
		
		case '|':
			answer=createNumberToken(first->value|second->value);
		break;
		
		case '^':
			answer=createNumberToken(first->value^second->value);
		break;
		
		case '%':
			answer=createNumberToken(first->value%second->value);
		break;
		
	}
	
	push(dataStack, answer);
}

void evaluateAlloperatorOnStack(Stack *operatorStack , Stack *dataStack){

	OperatorToken *operator;
	while((operator = pop(operatorStack)) != NULL){
		
		evaluateOperator(dataStack, operator);
	
	}

}

void tryEvaluateOperatorsOnStackThenPush(Stack *dataStack, Stack *operatorStack , OperatorToken *operator){

	OperatorToken *tempOperatorToken = pop(operatorStack);
	if(operator->precedence > tempOperatorToken->precedence){
		push(operatorStack,tempOperatorToken);
		push(operatorStack,operator);
	}else
		evaluateOperator(dataStack,tempOperatorToken);
		
	
}
	


