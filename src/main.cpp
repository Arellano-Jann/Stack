#include <iostream>
#include "../headers/Node.h"
#include "../headers/Stack.h"
#include "../headers/ExpressionAnalyzer.h"

int main(){
    std::string input = "";
    std::string postFix = "";
    std::cin >> input;

    Stack<char> operatorStack;
    for (int i = 0; i < input.length(); i++){ // Infix to Postfix
        char inp = input[i];
        ExpressionAnalyzer analyze(inp);
        int type = analyze.getType();
    //     if (type >= 0){ // checks if it is an operator
    //         if (operatorStack.isEmpty() != true){ // checks if stack is empty
    //             ExpressionAnalyzer oldTerm(operatorStack.peek());
    //             int oldType = oldTerm.getType(); // assigns prio number to oldTerm
    //             if (oldType < type && oldType < 5){ // checks prio and if it's not a parentheses
    //                 for (int j = 0; operatorStack.isEmpty(); j--){
    //                     if (operatorStack.peek() == '(') break; // breaks if '(' is found
    //                     postFix += operatorStack.peek(); // adds to postfix expr
    //                     operatorStack.pop(); // deletes the last operator added
    //                 }
    //                 if (operatorStack.peek() == '(') operatorStack.pop(); // pops the '('
    //             }
    //         }
    //         operatorStack.push(inp); // pushes operator to stack
    //     }
    //     else{
    //         postFix += inp; // adds to postfix if number
    //     }
    //     if (operatorStack.peek() == ')'){ // check if ')'
    //         operatorStack.pop(); // pops the ')'
    //         for (int j = 0; operatorStack.isEmpty(); j--){
    //             if (operatorStack.peek() == '(') break;
    //             postFix += operatorStack.peek(); // adds to postfix all ops within parentheses
    //             operatorStack.pop();
    //         }
    //         if (operatorStack.peek() == '(') operatorStack.pop();
    //     }
    }

    // Postfix to final
    std::cout << postFix;


    return 0;
}


// (4+2)*5+3
// Create a stack for operators only.
// If open parentheses, push on the operator stack.
// If not operator, add to post fix expression.
// If closed parentheses, pop operator stack until open parentheses. 
    // Every time we pop, we add to the postfix expression unless it is a parenthesis. 
    // This is done by peeking and adding.
// If we encounter different operators, 
    // we pop if old operator is higher up in PEMDAS. 
    // We push if it’s lower in PEMDAS. 
    // There is an exception for parentheses. Consider only what’s inside the parentheses. Or you can say that the parenthesis is the lowest in PEMDAS for this scenario.

// Final Outcome (in std::string) : 42+5*3+

// To come from postfix to final:
// Create an operand stack. Only for “final numbers”
// If number, push into an expression until operand is reached and do operand. This is done by pop, operand, pop.
// Push the expression result onto the stack