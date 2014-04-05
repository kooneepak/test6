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
	
	pop_ExpectAndReturn(&dataStack, &numberToken1);
	pop_ExpectAndReturn(&dataStack, &numberToken);
	
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
	
	pop_ExpectAndReturn(&dataStack, &numberToken1);
	pop_ExpectAndReturn(&dataStack, &numberToken);
	
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
	
	pop_ExpectAndReturn(&dataStack, &numberToken1);
	pop_ExpectAndReturn(&dataStack, &numberToken);
	
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
	
	pop_ExpectAndReturn(&dataStack, &numberToken1);
	pop_ExpectAndReturn(&dataStack, &numberToken);
	
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
	
	pop_ExpectAndReturn(&dataStack, &numberToken1);
	pop_ExpectAndReturn(&dataStack, &numberToken);
	
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
	
	pop_ExpectAndReturn(&dataStack, &numberToken1);
	pop_ExpectAndReturn(&dataStack, &numberToken);
	
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
	
	pop_ExpectAndReturn(&dataStack, &numberToken1);
	pop_ExpectAndReturn(&dataStack, &numberToken);
	
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
	pop_ExpectAndReturn(&dataStack, &numberToken1);
	pop_ExpectAndReturn(&dataStack, &numberToken);
	createNumberToken_ExpectAndReturn(3, &numberToken2);
	push_Expect(&dataStack,&numberToken2);

	
	pop_ExpectAndReturn(&stackOperator, &plus);
	pop_ExpectAndReturn(&dataStack, &numberToken3);
	pop_ExpectAndReturn(&dataStack, &numberToken2);
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
	pop_ExpectAndReturn(&dataStack, &numberToken1);
	pop_ExpectAndReturn(&dataStack, &numberToken);
	createNumberToken_ExpectAndReturn(3, &numberToken2);
	push_Expect(&dataStack,&numberToken2);

	
	pop_ExpectAndReturn(&stackOperator, &plus);
	pop_ExpectAndReturn(&dataStack, &numberToken3);
	pop_ExpectAndReturn(&dataStack, &numberToken2);
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
	pop_ExpectAndReturn(&dataStack, &numberToken1);
	pop_ExpectAndReturn(&dataStack, &numberToken);
	createNumberToken_ExpectAndReturn(3, &numberToken2);
	push_Expect(&dataStack,&numberToken2);

	
	pop_ExpectAndReturn(&stackOperator, &plus);
	pop_ExpectAndReturn(&dataStack, &numberToken3);
	pop_ExpectAndReturn(&dataStack, &numberToken2);
	createNumberToken_ExpectAndReturn(5, &numberToken4);
	push_Expect(&dataStack,&numberToken4);
	
	pop_ExpectAndReturn(&stackOperator, &multiply);
	pop_ExpectAndReturn(&dataStack, &numberToken5);
	pop_ExpectAndReturn(&dataStack, &numberToken4);
	createNumberToken_ExpectAndReturn(25, &numberToken6);
	push_Expect(&dataStack,&numberToken6);
	
	pop_ExpectAndReturn(&stackOperator, &divide);
	pop_ExpectAndReturn(&dataStack, &numberToken7);
	pop_ExpectAndReturn(&dataStack, &numberToken6);
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

	
	pop_ExpectAndReturn(&stackOperator, &or);
	push_Expect(&stackOperator,&or);
	push_Expect(&stackOperator,&multiply);

	
	
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

void test_evaluate2(){
	CEXCEPTION_T ERROR;	
	Stack dataStack;
	Tokenizer tokenizer;
	Stack operatorStack;
	
	OperatorToken plus = {.type= OPERATOR_TOKEN , .name = "+" , .precedence = 70};

	
	NumberToken numberToken = {.type = NUMBER_TOKEN, .value = 38};
	NumberToken numberToken1 = {.type = NUMBER_TOKEN, .value = 39};
	NumberToken numberToken2 = {.type = NUMBER_TOKEN, .value = 77};
	
	tokenizerNew_ExpectAndReturn("38 39", &tokenizer);
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&numberToken);
	push_Expect(&dataStack,&numberToken);
	nextToken_ExpectAndThrow(&tokenizer,ERR_NOT_OPERATOR);
	
	

	Try{
		 evaluate("38 39",&dataStack,&operatorStack);
	
	}Catch(ERROR){
	TEST_ASSERT_EQUAL(ERR_NOT_OPERATOR,ERROR);
	}
	
}

void test_evaluate3(){
	CEXCEPTION_T ERROR;	
	Stack dataStack;
	Tokenizer tokenizer;
	Stack operatorStack;
	
	OperatorToken plus = {.type= OPERATOR_TOKEN , .name = "+" , .precedence = 70};
	OperatorToken multiply = {.type= OPERATOR_TOKEN , .name = "*" , .precedence = 100};

	
	NumberToken numberToken = {.type = NUMBER_TOKEN, .value = 40};
	NumberToken numberToken1 = {.type = NUMBER_TOKEN, .value = 41};
	NumberToken numberToken2 = {.type = NUMBER_TOKEN, .value = 81};
	
	tokenizerNew_ExpectAndReturn("40+*", &tokenizer);
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&numberToken);
	push_Expect(&dataStack,&numberToken);
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&plus);
	pop_ExpectAndReturn(&operatorStack,NULL);
	push_Expect(&operatorStack,&plus);
	
	
	nextToken_ExpectAndThrow(&tokenizer,ERR_NOT_DATA);
	
	

	Try{
		 evaluate("40+*",&dataStack,&operatorStack);
	
	}Catch(ERROR){
	TEST_ASSERT_EQUAL(ERR_NOT_DATA,ERROR);
	}
	
}

void test_evaluate4(){
	CEXCEPTION_T ERROR;	
	Stack dataStack;
	Tokenizer tokenizer;
	Stack operatorStack;
	
	OperatorToken xor = {.type= OPERATOR_TOKEN , .name = "^" , .precedence = 50};
	OperatorToken minus = {.type= OPERATOR_TOKEN , .name = "-" , .precedence = 70};

	
	NumberToken numberToken = {.type = NUMBER_TOKEN, .value = 42};
	NumberToken numberToken1 = {.type = NUMBER_TOKEN, .value = 2};
	NumberToken numberToken2 = {.type = NUMBER_TOKEN, .value = 44};
	
	tokenizerNew_ExpectAndReturn("42^2-", &tokenizer);
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&numberToken);
	push_Expect(&dataStack,&numberToken);
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&xor);
	pop_ExpectAndReturn(&operatorStack,NULL);
	push_Expect(&operatorStack,&xor);
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&numberToken1);
	push_Expect(&dataStack,&numberToken1);
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&minus);
	pop_ExpectAndReturn(&operatorStack,&xor);
	push_Expect(&operatorStack,&xor);
	push_Expect(&operatorStack,&minus);
	
	nextToken_ExpectAndThrow(&tokenizer,ERR_NOT_DATA);
	
	

	Try{
		 evaluate("42^2-",&dataStack,&operatorStack);
	
	}Catch(ERROR){
	TEST_ASSERT_EQUAL(ERR_NOT_DATA,ERROR);
	}
	
}


void test_evaluate5(){
	CEXCEPTION_T ERROR;	
	Stack dataStack;
	Tokenizer tokenizer;
	Stack operatorStack;
	
	OperatorToken unknown = {.type= UNKNOWN_TOKEN , .name = "#" , .precedence = 0};
	

	
	NumberToken numberToken = {.type = NUMBER_TOKEN, .value = 43};
	NumberToken numberToken1 = {.type = NUMBER_TOKEN, .value = 44};
	NumberToken numberToken2 = {.type = NUMBER_TOKEN, .value = 77};
	
	tokenizerNew_ExpectAndReturn("43#44", &tokenizer);
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&numberToken);
	push_Expect(&dataStack,&numberToken);

	nextToken_ExpectAndThrow(&tokenizer,ERR_NOT_OPERATOR);
	
	

	Try{
		 evaluate("43#44",&dataStack,&operatorStack);
	
	}Catch(ERROR){
	TEST_ASSERT_EQUAL(ERR_NOT_OPERATOR,ERROR);
	}
	
}

void test_evaluate6(){
	Stack dataStack;
	Tokenizer tokenizer;
	Stack operatorStack;
	
	OperatorToken plus = {.type = OPERATOR_TOKEN , .name = "+", .precedence=70};
	NumberToken numberToken = {.type = NUMBER_TOKEN, .value = 1};
	NumberToken numberToken1 = {.type = NUMBER_TOKEN, .value = 2};
	NumberToken numberToken2 = {.type = NUMBER_TOKEN, .value = 3};
	
	tokenizerNew_ExpectAndReturn("1+2", &tokenizer);
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&numberToken);
	push_Expect(&dataStack,&numberToken);
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&plus);
	pop_ExpectAndReturn(&operatorStack,NULL);
	push_Expect(&operatorStack,&plus);
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&numberToken1);
	push_Expect(&dataStack,&numberToken1);
	nextToken_ExpectAndReturn(&tokenizer,NULL);
	
	
	pop_ExpectAndReturn(&operatorStack, &plus);
	pop_ExpectAndReturn(&dataStack, &numberToken1);
	pop_ExpectAndReturn(&dataStack, &numberToken);
	createNumberToken_ExpectAndReturn(3, &numberToken2);
	push_Expect(&dataStack,&numberToken2);
	pop_ExpectAndReturn(&operatorStack,NULL);
	
	 evaluate("1+2",&dataStack,&operatorStack);

}

void test_evaluate7(){
	Stack dataStack;
	Tokenizer tokenizer;
	Stack operatorStack;
	
	OperatorToken multiply = {.type = OPERATOR_TOKEN , .name = "*", .precedence=70};
	NumberToken numberToken = {.type = NUMBER_TOKEN, .value = 4};
	NumberToken numberToken1 = {.type = NUMBER_TOKEN, .value = 3};
	NumberToken numberToken2 = {.type = NUMBER_TOKEN, .value = 12};
	
	tokenizerNew_ExpectAndReturn("4*3", &tokenizer);
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&numberToken);
	push_Expect(&dataStack,&numberToken);
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&multiply);
	pop_ExpectAndReturn(&operatorStack,NULL);
	push_Expect(&operatorStack,&multiply);
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&numberToken1);
	push_Expect(&dataStack,&numberToken1);
	nextToken_ExpectAndReturn(&tokenizer,NULL);
	
	
	pop_ExpectAndReturn(&operatorStack, &multiply);
	pop_ExpectAndReturn(&dataStack, &numberToken1);
	pop_ExpectAndReturn(&dataStack, &numberToken);
	createNumberToken_ExpectAndReturn(12, &numberToken2);
	push_Expect(&dataStack,&numberToken2);
	pop_ExpectAndReturn(&operatorStack,NULL);
	
	 evaluate("4*3",&dataStack,&operatorStack);

}

void test_evaluate8(){
	Stack dataStack;
	Tokenizer tokenizer;
	Stack operatorStack;
	
	OperatorToken plus1 = {.type = OPERATOR_TOKEN , .name = "+", .precedence=70};
	OperatorToken plus2 = {.type = OPERATOR_TOKEN , .name = "+", .precedence=70};
	OperatorToken minus = {.type = OPERATOR_TOKEN , .name = "-", .precedence=70};
	NumberToken numberToken = {.type = NUMBER_TOKEN, .value = 3};
	NumberToken numberToken1 = {.type = NUMBER_TOKEN, .value = 4};
	NumberToken answer1 = {.type = NUMBER_TOKEN, .value = 7};
	NumberToken numberToken2 = {.type = NUMBER_TOKEN, .value = 5};
	NumberToken answer2 = {.type = NUMBER_TOKEN, .value = 12};
	NumberToken numberToken3 = {.type = NUMBER_TOKEN, .value = 6};
	NumberToken answer3 = {.type = NUMBER_TOKEN, .value = 6};	
	
	tokenizerNew_ExpectAndReturn("3+4+5-6", &tokenizer);
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&numberToken);
	push_Expect(&dataStack,&numberToken);
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&plus1);
	pop_ExpectAndReturn(&operatorStack,NULL);
	push_Expect(&operatorStack,&plus1);
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&numberToken1);
	push_Expect(&dataStack,&numberToken1);
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&plus2);
	pop_ExpectAndReturn(&operatorStack, &plus1);
	
	pop_ExpectAndReturn(&dataStack, &numberToken1);
	pop_ExpectAndReturn(&dataStack, &numberToken);
	createNumberToken_ExpectAndReturn(7, &answer1);
	push_Expect(&dataStack,&answer1);
	
	pop_ExpectAndReturn(&operatorStack,NULL);
	push_Expect(&operatorStack,&plus2);
	
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&numberToken2);
	push_Expect(&dataStack,&numberToken2);
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&minus);
	
	pop_ExpectAndReturn(&operatorStack, &plus2);
	pop_ExpectAndReturn(&dataStack, &numberToken2);
	pop_ExpectAndReturn(&dataStack, &answer1);
	createNumberToken_ExpectAndReturn(12, &answer2);
	push_Expect(&dataStack,&answer2);
	
	pop_ExpectAndReturn(&operatorStack,NULL);
	push_Expect(&operatorStack,&minus);
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&numberToken3);
	push_Expect(&dataStack,&numberToken3);
	nextToken_ExpectAndReturn(&tokenizer,NULL);
	
	pop_ExpectAndReturn(&operatorStack, &minus);
	pop_ExpectAndReturn(&dataStack, &numberToken3);
	pop_ExpectAndReturn(&dataStack, &answer2);
	createNumberToken_ExpectAndReturn(6, &answer3);
	push_Expect(&dataStack,&answer3);
	pop_ExpectAndReturn(&operatorStack,NULL);
	
	
	
	
	 evaluate("3+4+5-6",&dataStack,&operatorStack);

}

void test_evaluate9(){
	Stack dataStack;
	Tokenizer tokenizer;
	Stack operatorStack;
	
	OperatorToken divide = {.type = OPERATOR_TOKEN , .name = "/", .precedence=100};
	OperatorToken plus = {.type = OPERATOR_TOKEN , .name = "+", .precedence=70};
	OperatorToken and = {.type = OPERATOR_TOKEN , .name = "&", .precedence=20};
	NumberToken numberToken = {.type = NUMBER_TOKEN, .value = 111};
	NumberToken numberToken1 = {.type = NUMBER_TOKEN, .value = 12};
	NumberToken answer1 = {.type = NUMBER_TOKEN, .value = 9};
	NumberToken numberToken2 = {.type = NUMBER_TOKEN, .value = 13};
	NumberToken answer2 = {.type = NUMBER_TOKEN, .value = 22};
	NumberToken numberToken3 = {.type = NUMBER_TOKEN, .value = 14};
	NumberToken answer3 = {.type = NUMBER_TOKEN, .value = 6};	
	
	tokenizerNew_ExpectAndReturn("111/12+13&14", &tokenizer);
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&numberToken);
	push_Expect(&dataStack,&numberToken);
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&divide);
	pop_ExpectAndReturn(&operatorStack,NULL);
	push_Expect(&operatorStack,&divide);
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&numberToken1);
	push_Expect(&dataStack,&numberToken1);
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&plus);
	pop_ExpectAndReturn(&operatorStack, &divide);
	
	pop_ExpectAndReturn(&dataStack, &numberToken1);
	pop_ExpectAndReturn(&dataStack, &numberToken);
	createNumberToken_ExpectAndReturn(9, &answer1);
	push_Expect(&dataStack,&answer1);
	
	pop_ExpectAndReturn(&operatorStack,NULL);
	push_Expect(&operatorStack,&plus);
	
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&numberToken2);
	push_Expect(&dataStack,&numberToken2);
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&and);
	
	pop_ExpectAndReturn(&operatorStack, &plus);
	pop_ExpectAndReturn(&dataStack, &numberToken2);
	pop_ExpectAndReturn(&dataStack, &answer1);
	createNumberToken_ExpectAndReturn(22, &answer2);
	push_Expect(&dataStack,&answer2);
	
	pop_ExpectAndReturn(&operatorStack,NULL);
	push_Expect(&operatorStack,&and);
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&numberToken3);
	push_Expect(&dataStack,&numberToken3);
	nextToken_ExpectAndReturn(&tokenizer,NULL);
	
	pop_ExpectAndReturn(&operatorStack, &and);
	pop_ExpectAndReturn(&dataStack, &numberToken3);
	pop_ExpectAndReturn(&dataStack, &answer2);
	createNumberToken_ExpectAndReturn(6, &answer3);
	push_Expect(&dataStack,&answer3);
	pop_ExpectAndReturn(&operatorStack,NULL);
	
	
	
	
	 evaluate("111/12+13&14",&dataStack,&operatorStack);

}

void test_evaluate10(){
	Stack dataStack;
	Tokenizer tokenizer;
	Stack operatorStack;
	
	OperatorToken and = {.type = OPERATOR_TOKEN , .name = "&", .precedence=20};
	OperatorToken xor = {.type = OPERATOR_TOKEN , .name = "^", .precedence=50};
	OperatorToken plus = {.type = OPERATOR_TOKEN , .name = "+", .precedence=70};
	NumberToken numberToken = {.type = NUMBER_TOKEN, .value = 211};
	NumberToken numberToken1 = {.type = NUMBER_TOKEN, .value = 22};
	NumberToken answer1 = {.type = NUMBER_TOKEN, .value = 47};
	NumberToken numberToken2 = {.type = NUMBER_TOKEN, .value = 23};
	NumberToken answer2 = {.type = NUMBER_TOKEN, .value = 57};
	NumberToken numberToken3 = {.type = NUMBER_TOKEN, .value = 24};
	NumberToken answer3 = {.type = NUMBER_TOKEN, .value = 17};	
	
	tokenizerNew_ExpectAndReturn("211&22^23+24", &tokenizer);
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&numberToken);
	push_Expect(&dataStack,&numberToken);
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&and);
	pop_ExpectAndReturn(&operatorStack,NULL);
	push_Expect(&operatorStack,&and);
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&numberToken1);
	push_Expect(&dataStack,&numberToken1);
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&xor);
	pop_ExpectAndReturn(&operatorStack, &and);
	push_Expect(&operatorStack,&and);
	push_Expect(&operatorStack,&xor);
	
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&numberToken2);
	push_Expect(&dataStack,&numberToken2);
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&plus);
	pop_ExpectAndReturn(&operatorStack,&xor);
	push_Expect(&operatorStack,&xor);
	push_Expect(&operatorStack,&plus);
	
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&numberToken3);
	push_Expect(&dataStack,&numberToken3);
	nextToken_ExpectAndReturn(&tokenizer,NULL);
	
	
	pop_ExpectAndReturn(&operatorStack,&plus);
	pop_ExpectAndReturn(&dataStack, &numberToken3);
	pop_ExpectAndReturn(&dataStack, &numberToken2);
	createNumberToken_ExpectAndReturn(47, &answer1);
	push_Expect(&dataStack,&answer1);
	
	pop_ExpectAndReturn(&operatorStack,&xor);
	pop_ExpectAndReturn(&dataStack, &answer1);
	pop_ExpectAndReturn(&dataStack, &numberToken1);
	createNumberToken_ExpectAndReturn(57, &answer2);
	push_Expect(&dataStack,&answer2);
	
	pop_ExpectAndReturn(&operatorStack,&and);
	pop_ExpectAndReturn(&dataStack, &answer2);
	pop_ExpectAndReturn(&dataStack, &numberToken);
	createNumberToken_ExpectAndReturn(17, &answer3);
	push_Expect(&dataStack,&answer3);
	pop_ExpectAndReturn(&operatorStack,NULL);
	
	
	
	
	 evaluate("211&22^23+24",&dataStack,&operatorStack);

}

void test_evaluate11(){
	Stack dataStack;
	Tokenizer tokenizer;
	Stack operatorStack;
	
	OperatorToken or = {.type = OPERATOR_TOKEN , .name = "|", .precedence=10};
	OperatorToken xor = {.type = OPERATOR_TOKEN , .name = "^", .precedence=50};
	OperatorToken plus = {.type = OPERATOR_TOKEN , .name = "+", .precedence=70};
	OperatorToken and = {.type = OPERATOR_TOKEN , .name = "&", .precedence=20};
	NumberToken numberToken = {.type = NUMBER_TOKEN, .value = 266};
	NumberToken numberToken1 = {.type = NUMBER_TOKEN, .value = 27};
	NumberToken answer1 = {.type = NUMBER_TOKEN, .value = 57};
	NumberToken numberToken2 = {.type = NUMBER_TOKEN, .value = 28};
	NumberToken answer2 = {.type = NUMBER_TOKEN, .value = 34};
	NumberToken numberToken3 = {.type = NUMBER_TOKEN, .value = 29};
	NumberToken answer3 = {.type = NUMBER_TOKEN, .value = 2};
	NumberToken numberToken4 = {.type = NUMBER_TOKEN, .value = 30};
	NumberToken answer4 = {.type = NUMBER_TOKEN, .value =266 };		
	
	tokenizerNew_ExpectAndReturn("266|27^28+29&30", &tokenizer);
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&numberToken);
	push_Expect(&dataStack,&numberToken);
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&or);
	pop_ExpectAndReturn(&operatorStack,NULL);
	push_Expect(&operatorStack,&or);
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&numberToken1);
	push_Expect(&dataStack,&numberToken1);
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&xor);
	pop_ExpectAndReturn(&operatorStack, &or);
	push_Expect(&operatorStack,&or);
	push_Expect(&operatorStack,&xor);
	
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&numberToken2);
	push_Expect(&dataStack,&numberToken2);
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&plus);
	pop_ExpectAndReturn(&operatorStack,&xor);
	push_Expect(&operatorStack,&xor);
	push_Expect(&operatorStack,&plus);
	
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&numberToken3);
	push_Expect(&dataStack,&numberToken3);
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&and);
	pop_ExpectAndReturn(&operatorStack,&plus);
	
	pop_ExpectAndReturn(&dataStack, &numberToken3);
	pop_ExpectAndReturn(&dataStack, &numberToken2);
	createNumberToken_ExpectAndReturn(57, &answer1);
	push_Expect(&dataStack,&answer1);
	
	pop_ExpectAndReturn(&operatorStack,&xor);
	pop_ExpectAndReturn(&dataStack, &answer1);
	pop_ExpectAndReturn(&dataStack, &numberToken1);
	createNumberToken_ExpectAndReturn(34, &answer2);
	push_Expect(&dataStack,&answer2);
	
	pop_ExpectAndReturn(&operatorStack,&or);
	push_Expect(&operatorStack,&or);
	push_Expect(&operatorStack,&and);
	
	
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&numberToken4);
	push_Expect(&dataStack,&numberToken4);
	nextToken_ExpectAndReturn(&tokenizer,NULL);

	pop_ExpectAndReturn(&operatorStack,&and);
	pop_ExpectAndReturn(&dataStack, &numberToken4);
	pop_ExpectAndReturn(&dataStack, &answer2);
	createNumberToken_ExpectAndReturn(2, &answer3);
	push_Expect(&dataStack,&answer3);
	
	pop_ExpectAndReturn(&operatorStack,&or);
	pop_ExpectAndReturn(&dataStack, &answer3);
	pop_ExpectAndReturn(&dataStack, &numberToken);
	createNumberToken_ExpectAndReturn(266, &answer4);
	push_Expect(&dataStack,&answer4);
	pop_ExpectAndReturn(&operatorStack,NULL);
	
	
	
	
	 evaluate("266|27^28+29&30",&dataStack,&operatorStack);

}


