#include "calculator.h"
#include "Token.h"
#include "Error.h"
#include "Stack.h"
#include "string.h"
#include "CException.h"


int evaluate(char *expression , Stack *dataStack , Stack *operatorStack ){

	
	Tokenizer *tokenizer;
	Token *token;
	NumberToken *number;
	OperatorToken *operator;

	
	tokenizer = tokenizerNew(expression);
	while(1){
		number=(NumberToken*)nextToken(tokenizer);
	if(number == NULL){
	Throw(ERR_NOT_DATA);
	}
	else if(number->type!=NUMBER_TOKEN){				
	Throw(ERR_NOT_DATA);	
	}else
	push(dataStack,number);
	

	
}
}


