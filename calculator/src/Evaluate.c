#include <stdio.h>
#include <string.h>
#include "Stack.h"
#include "Token.h"
#include "createNumberToken.h"
#include "Evaluate.h"


void evaluateOperator(Stack *dataStack ,  OperatorToken *opeToken){

	NumberToken *answer;
	
	NumberToken *second =(NumberToken*)pop(dataStack);
	NumberToken *first =(NumberToken*)pop(dataStack);
	
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

	OperatorToken *tempOperatorToken;
	while(1){
	tempOperatorToken = pop(operatorStack);
	if(tempOperatorToken == NULL){
		push(operatorStack,operator);
		break;
	}
	else if(operator->precedence > tempOperatorToken->precedence){
		push(operatorStack,tempOperatorToken);
		push(operatorStack,operator);
		break;
	}else
		evaluateOperator(dataStack,tempOperatorToken);
	}	
	
}
	


