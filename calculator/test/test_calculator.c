#include "unity.h"
#include "calculator.h"
#include "mock_Token.h"
#include "mock_Stack.h"
#include "mock_createNumberToken.h"
#include "CException.h"
#include "Error.h"
#include "Evaluate.h"

void setUp(void){}

void tearDown(void){}




void test_evaluate_operand_plus(){
	Stack dataStack;
	
	OperatorToken operatorToken = {.type = OPERATOR_TOKEN , .name = "+", .precedence=70};
	NumberToken numberToken = {.type = NUMBER_TOKEN, .value = 1};
	NumberToken numberToken1 = {.type = NUMBER_TOKEN, .value = 2};
	NumberToken numberToken2 = {.type = NUMBER_TOKEN, .value = 3};
	
	pop_ExpectAndReturn(&dataStack, &numberToken);
	pop_ExpectAndReturn(&dataStack, &numberToken1);
	
	createNumberToken_ExpectAndReturn(3, &numberToken2);
	push_Expect(&dataStack,&numberToken2);
	evaluateOperator(&dataStack ,  &operatorToken);

}

void test_evaluate_operand_minus(){
	Stack dataStack;
	
	OperatorToken operatorToken = {.type = OPERATOR_TOKEN , .name = "-", .precedence=70};
	NumberToken numberToken = {.type = NUMBER_TOKEN, .value = 2};
	NumberToken numberToken1 = {.type = NUMBER_TOKEN, .value = 1};
	NumberToken numberToken2 = {.type = NUMBER_TOKEN, .value = 1};
	
	pop_ExpectAndReturn(&dataStack, &numberToken);
	pop_ExpectAndReturn(&dataStack, &numberToken1);
	
	createNumberToken_ExpectAndReturn(1, &numberToken2);
	push_Expect(&dataStack,&numberToken2);
	evaluateOperator(&dataStack ,  &operatorToken);

}

void test_evaluate_operand_multiply(){
	Stack dataStack;
	
	OperatorToken operatorToken = {.type = OPERATOR_TOKEN , .name = "*", .precedence=100};
	NumberToken numberToken = {.type = NUMBER_TOKEN, .value = 2};
	NumberToken numberToken1 = {.type = NUMBER_TOKEN, .value = 2};
	NumberToken numberToken2 = {.type = NUMBER_TOKEN, .value = 4};
	
	pop_ExpectAndReturn(&dataStack, &numberToken);
	pop_ExpectAndReturn(&dataStack, &numberToken1);
	
	createNumberToken_ExpectAndReturn(4, &numberToken2);
	push_Expect(&dataStack,&numberToken2);
	evaluateOperator(&dataStack ,  &operatorToken);

}

void test_evaluate_operand_divide(){
	Stack dataStack;
	
	OperatorToken operatorToken = {.type = OPERATOR_TOKEN , .name = "/", .precedence=100};
	NumberToken numberToken = {.type = NUMBER_TOKEN, .value = 4};
	NumberToken numberToken1 = {.type = NUMBER_TOKEN, .value = 2};
	NumberToken numberToken2 = {.type = NUMBER_TOKEN, .value = 2};
	
	pop_ExpectAndReturn(&dataStack, &numberToken);
	pop_ExpectAndReturn(&dataStack, &numberToken1);
	
	createNumberToken_ExpectAndReturn(2, &numberToken2);
	push_Expect(&dataStack,&numberToken2);
	evaluateOperator(&dataStack ,  &operatorToken);

}

void test_evaluate_operand_modulo(){
	Stack dataStack;
	
	OperatorToken operatorToken = {.type = OPERATOR_TOKEN , .name = "%", .precedence=100};
	NumberToken numberToken = {.type = NUMBER_TOKEN, .value = 5};
	NumberToken numberToken1 = {.type = NUMBER_TOKEN, .value = 2};
	NumberToken numberToken2 = {.type = NUMBER_TOKEN, .value = 1};
	
	pop_ExpectAndReturn(&dataStack, &numberToken);
	pop_ExpectAndReturn(&dataStack, &numberToken1);
	
	createNumberToken_ExpectAndReturn(1, &numberToken2);
	push_Expect(&dataStack,&numberToken2);
	evaluateOperator(&dataStack ,  &operatorToken);

}

void test_evaluate_operand_xor(){
	Stack dataStack;
	
	OperatorToken operatorToken = {.type = OPERATOR_TOKEN , .name = "^", .precedence=50};
	NumberToken numberToken = {.type = NUMBER_TOKEN, .value = 0b10};
	NumberToken numberToken1 = {.type = NUMBER_TOKEN, .value = 0b11};
	NumberToken numberToken2 = {.type = NUMBER_TOKEN, .value = 0b01};
	
	pop_ExpectAndReturn(&dataStack, &numberToken);
	pop_ExpectAndReturn(&dataStack, &numberToken1);
	
	createNumberToken_ExpectAndReturn(0b01, &numberToken2);
	push_Expect(&dataStack,&numberToken2);
	evaluateOperator(&dataStack ,  &operatorToken);

}

void test_evaluate_operand_and(){
	Stack dataStack;
	
	OperatorToken operatorToken = {.type = OPERATOR_TOKEN , .name = "&", .precedence=20};
	NumberToken numberToken = {.type = NUMBER_TOKEN, .value = 0b10};
	NumberToken numberToken1 = {.type = NUMBER_TOKEN, .value = 0b11};
	NumberToken numberToken2 = {.type = NUMBER_TOKEN, .value = 0b10};
	
	pop_ExpectAndReturn(&dataStack, &numberToken);
	pop_ExpectAndReturn(&dataStack, &numberToken1);
	
	createNumberToken_ExpectAndReturn(0b10, &numberToken2);
	push_Expect(&dataStack,&numberToken2);
	evaluateOperator(&dataStack ,  &operatorToken);
}

void test_evaluate_operand_or(){
	Stack dataStack;
	
	OperatorToken operatorToken = {.type = OPERATOR_TOKEN , .name = "|", .precedence=10};
	NumberToken numberToken = {.type = NUMBER_TOKEN, .value = 0b10};
	NumberToken numberToken1 = {.type = NUMBER_TOKEN, .value = 0b11};
	NumberToken numberToken2 = {.type = NUMBER_TOKEN, .value = 0b11};
	
	pop_ExpectAndReturn(&dataStack, &numberToken);
	pop_ExpectAndReturn(&dataStack, &numberToken1);
	
	createNumberToken_ExpectAndReturn(0b11, &numberToken2);
	push_Expect(&dataStack,&numberToken2);
	evaluateOperator(&dataStack ,  &operatorToken);
}


void test_evaluateAllOperatorOnStack(){

	Stack dataStack;
	Stack stackOperator;
	
	
	OperatorToken minus = {.type= OPERATOR_TOKEN , .name = "-" , .precedence = 70};
	OperatorToken plus = {.type= OPERATOR_TOKEN , .name = "+" , .precedence = 70};
	
	NumberToken numberToken = {.type = NUMBER_TOKEN, .value = 5};
	NumberToken numberToken1 = {.type = NUMBER_TOKEN, .value = 2};
	NumberToken numberToken2 = {.type = NUMBER_TOKEN, .value = 3};
	NumberToken numberToken3 = {.type = NUMBER_TOKEN, .value = 2};
	NumberToken numberToken4 = {.type = NUMBER_TOKEN, .value = 5};
	
	pop_ExpectAndReturn(&stackOperator, &minus);
	pop_ExpectAndReturn(&dataStack, &numberToken);
	pop_ExpectAndReturn(&dataStack, &numberToken1);
	createNumberToken_ExpectAndReturn(3, &numberToken2);
	push_Expect(&dataStack,&numberToken2);

	
	pop_ExpectAndReturn(&stackOperator, &plus);
	pop_ExpectAndReturn(&dataStack, &numberToken2);
	pop_ExpectAndReturn(&dataStack, &numberToken3);
	createNumberToken_ExpectAndReturn(5, &numberToken4);
	push_Expect(&dataStack,&numberToken4);
	
	
	pop_ExpectAndReturn(&stackOperator , NULL);
	evaluateAlloperatorOnStack(&stackOperator , &dataStack);

}


void test_evaluateAllOperatorOnStack_with_more_number(){

	Stack dataStack;
	Stack stackOperator;
	
	
	OperatorToken minus = {.type= OPERATOR_TOKEN , .name = "-" , .precedence = 70};
	OperatorToken plus = {.type= OPERATOR_TOKEN , .name = "+" , .precedence = 70};
	OperatorToken multiply = {.type= OPERATOR_TOKEN , .name = "*" , .precedence = 100};
	
	NumberToken numberToken = {.type = NUMBER_TOKEN, .value = 5};
	NumberToken numberToken1 = {.type = NUMBER_TOKEN, .value = 2};
	NumberToken numberToken2 = {.type = NUMBER_TOKEN, .value = 3};
	NumberToken numberToken3 = {.type = NUMBER_TOKEN, .value = 2};
	NumberToken numberToken4 = {.type = NUMBER_TOKEN, .value = 5};
	NumberToken numberToken5 = {.type = NUMBER_TOKEN, .value = 5};
	NumberToken numberToken6 = {.type = NUMBER_TOKEN, .value = 25};
	
	pop_ExpectAndReturn(&stackOperator, &minus);
	pop_ExpectAndReturn(&dataStack, &numberToken);
	pop_ExpectAndReturn(&dataStack, &numberToken1);
	createNumberToken_ExpectAndReturn(3, &numberToken2);
	push_Expect(&dataStack,&numberToken2);

	
	pop_ExpectAndReturn(&stackOperator, &plus);
	pop_ExpectAndReturn(&dataStack, &numberToken2);
	pop_ExpectAndReturn(&dataStack, &numberToken3);
	createNumberToken_ExpectAndReturn(5, &numberToken4);
	push_Expect(&dataStack,&numberToken4);
	
	pop_ExpectAndReturn(&stackOperator, &multiply);
	pop_ExpectAndReturn(&dataStack, &numberToken4);
	pop_ExpectAndReturn(&dataStack, &numberToken5);
	createNumberToken_ExpectAndReturn(25, &numberToken6);
	push_Expect(&dataStack,&numberToken6);
	
	
	pop_ExpectAndReturn(&stackOperator , NULL);
	evaluateAlloperatorOnStack(&stackOperator , &dataStack);

}


void test_evaluateAllOperatorOnStack_with_five_number(){

	Stack dataStack;
	Stack stackOperator;
	
	
	OperatorToken minus = {.type= OPERATOR_TOKEN , .name = "-" , .precedence = 70};
	OperatorToken plus = {.type= OPERATOR_TOKEN , .name = "+" , .precedence = 70};
	OperatorToken multiply = {.type= OPERATOR_TOKEN , .name = "*" , .precedence = 100};
	OperatorToken divide = {.type= OPERATOR_TOKEN , .name = "/" , .precedence = 100};
	
	NumberToken numberToken = {.type = NUMBER_TOKEN, .value = 5};
	NumberToken numberToken1 = {.type = NUMBER_TOKEN, .value = 2};
	NumberToken numberToken2 = {.type = NUMBER_TOKEN, .value = 3};
	NumberToken numberToken3 = {.type = NUMBER_TOKEN, .value = 2};
	NumberToken numberToken4 = {.type = NUMBER_TOKEN, .value = 5};
	NumberToken numberToken5 = {.type = NUMBER_TOKEN, .value = 5};
	NumberToken numberToken6 = {.type = NUMBER_TOKEN, .value = 25};
	NumberToken numberToken7 = {.type = NUMBER_TOKEN, .value = 5};
	NumberToken numberToken8 = {.type = NUMBER_TOKEN, .value = 5};
	
	pop_ExpectAndReturn(&stackOperator, &minus);
	pop_ExpectAndReturn(&dataStack, &numberToken);
	pop_ExpectAndReturn(&dataStack, &numberToken1);
	createNumberToken_ExpectAndReturn(3, &numberToken2);
	push_Expect(&dataStack,&numberToken2);

	
	pop_ExpectAndReturn(&stackOperator, &plus);
	pop_ExpectAndReturn(&dataStack, &numberToken2);
	pop_ExpectAndReturn(&dataStack, &numberToken3);
	createNumberToken_ExpectAndReturn(5, &numberToken4);
	push_Expect(&dataStack,&numberToken4);
	
	pop_ExpectAndReturn(&stackOperator, &multiply);
	pop_ExpectAndReturn(&dataStack, &numberToken4);
	pop_ExpectAndReturn(&dataStack, &numberToken5);
	createNumberToken_ExpectAndReturn(25, &numberToken6);
	push_Expect(&dataStack,&numberToken6);
	
	pop_ExpectAndReturn(&stackOperator, &divide);
	pop_ExpectAndReturn(&dataStack, &numberToken6);
	pop_ExpectAndReturn(&dataStack, &numberToken7);
	createNumberToken_ExpectAndReturn(5, &numberToken8);
	push_Expect(&dataStack,&numberToken8);
	
	
	pop_ExpectAndReturn(&stackOperator , NULL);
	evaluateAlloperatorOnStack(&stackOperator , &dataStack);

}


void test_tryEvaluateOperatorsOnStackThenPush(){

	Stack dataStack;
	Stack stackOperator;
	
	
	OperatorToken minus = {.type= OPERATOR_TOKEN , .name = "-" , .precedence = 70};
	OperatorToken multiply = {.type= OPERATOR_TOKEN , .name = "*" , .precedence = 100};
	
	NumberToken numberToken = {.type = NUMBER_TOKEN, .value = 5};
	NumberToken numberToken1 = {.type = NUMBER_TOKEN, .value = 2};
	NumberToken numberToken2 = {.type = NUMBER_TOKEN, .value = 3};

	
	pop_ExpectAndReturn(&stackOperator, &minus);
	push_Expect(&stackOperator,&minus);
	push_Expect(&stackOperator,&multiply);
	

	
		tryEvaluateOperatorsOnStackThenPush(&dataStack ,&stackOperator, &multiply);


}

void test_tryEvaluateOperatorsOnStackThenPush2(){

	Stack dataStack;
	Stack stackOperator;
	
	
	OperatorToken multiply = {.type= OPERATOR_TOKEN , .name = "*" , .precedence = 100};
	OperatorToken or = {.type= OPERATOR_TOKEN , .name = "|" , .precedence = 10};
	
	NumberToken numberToken = {.type = NUMBER_TOKEN, .value = 5};
	NumberToken numberToken1 = {.type = NUMBER_TOKEN, .value = 2};
	NumberToken numberToken2 = {.type = NUMBER_TOKEN, .value = 10};

	
	pop_ExpectAndReturn(&stackOperator, &multiply);
	pop_ExpectAndReturn(&dataStack, &numberToken);
	pop_ExpectAndReturn(&dataStack, &numberToken1);
	createNumberToken_ExpectAndReturn(10, &numberToken2);
	push_Expect(&dataStack,&numberToken2);
	
	
	tryEvaluateOperatorsOnStackThenPush(&dataStack ,&stackOperator, &multiply);


}

void test_evaluate_plus(){
	CEXCEPTION_T ERROR;	
	Stack dataStack;
	Tokenizer tokenizer;
	Stack operatorStack;
	
	OperatorToken operatorToken = {.type = OPERATOR_TOKEN , .name = "+", .precedence=70};	
	tokenizerNew_ExpectAndReturn("+",&tokenizer);
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&operatorToken);
	Try{
		 evaluate("+",&dataStack,&operatorStack);
	
	}Catch(ERROR){
	
	TEST_ASSERT_EQUAL(ERR_NOT_DATA,ERROR);
	}
	
}













