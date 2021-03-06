/**
 * @file main.cpp
 * @author Jann Arellano
 * @brief 
 * @version 0.1
 * @date 2022-02-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include "../headers/Node.h"
#include "../headers/Stack.h"
#include "../headers/ExpressionAnalyzer.h"

int main(){
    std::string input = ""; // ( 45 + 6 ) * ( 44 - 5 )
    std::string postFix = "";
    std::cout << "Expression?" << std::endl;
    std::getline(std::cin, input);

    Stack<char> operatorStack;
    for (int i = 0; i < input.length(); i++){ // Infix to Postfix
        char inp = input[i];
        ExpressionAnalyzer analyze(inp);
        int type = analyze.getType();
        if (type >= 1){ // checks if it is an operator
            if (!operatorStack.isEmpty()){ // checks if stack is empty
                ExpressionAnalyzer oldTerm(operatorStack.peek());
                int oldType = oldTerm.getType(); // assigns prio number to oldTerm
                if (oldType < type && type < 5){ // checks prio and if it's not a parentheses
                    while (!operatorStack.isEmpty()){
                        if (operatorStack.peek() == '(') break; // breaks if '(' is found
                        postFix += operatorStack.peek(); // adds to postfix expr
                        postFix += " ";
                        operatorStack.pop(); // deletes the last operator added
                    }
                    // if (operatorStack.peek() == '(') operatorStack.pop(); // pops the '('
                }
            }
            operatorStack.push(inp); // pushes operator to stack
            i++;
            // std::cout << "Pushed operator: " << operatorStack.peek() << std::endl;
            // std::cout << "Current postfix: " << postFix << std::endl;
        }
        else{
            postFix += inp; // adds to postfix if number
        }
        if (!operatorStack.isEmpty() && operatorStack.peek() == ')'){ // check if ')'
            operatorStack.pop(); // pops the ')'
            while (!operatorStack.isEmpty()){
                if (operatorStack.peek() == '(') break;
                postFix += operatorStack.peek(); // adds to postfix all ops within parentheses
                postFix += " ";
                operatorStack.pop();
            }
            // if (operatorStack.peek() == '(') operatorStack.pop(); // causes seg fault
        }

    }

    //Print Postfix
    while (!operatorStack.isEmpty()){
        if (operatorStack.peek() == '(') {operatorStack.pop();}
        if (operatorStack.isEmpty()) break;
        if (postFix[postFix.size()-1] != ' ') postFix += " ";
        postFix += operatorStack.peek(); // puts all ops leftover ops behind postfix
        postFix += " ";
        operatorStack.pop();
    }
    std::cout << "Postfix : " << postFix << std::endl;

    // Postfix to final

    Stack<int> finalStack;
    for (int i = 0; i < postFix.length(); i++){ // Infix to Postfix
        std::string charInp = "";
        charInp = postFix[i]; // to char
        for (int j = i+1; j < postFix.length(); j++){
            i=j; // bugs or something
            if (postFix[j] == ' ') break; 
            charInp += postFix[j]; // adds more numbers for multidigit numbers
        }
        // std::cout << "Current char: " << charInp << std::endl;
        int intInp = 0;
        ExpressionAnalyzer postFixAnalyzer(charInp[0]);
        if (postFixAnalyzer.getType() == -1){
            intInp = std::stoi(charInp); // to int
        } 
        // std::cout << "Current int: " << intInp << std::endl;

        ExpressionAnalyzer analyze(charInp[0]); // returns the first character (without null terminator)
        int type = analyze.getType(); // returns a number per op
        if (type >= 1){ // checks if it is an operator. prio algo
            int firstNumber = finalStack.peek(); // saves top to var
            finalStack.pop();
            int secondNumber = finalStack.peek(); // saves top-1 to var
            finalStack.pop(); // deletes the saves off of the stack
            int finalNumber = 0;
            switch(charInp[0]){ // might bug out because 
                case '+':
                    finalNumber = secondNumber+firstNumber;
                    break;
                case '-':
                    finalNumber = secondNumber-firstNumber;
                    break;
                case '*':
                    finalNumber = secondNumber*firstNumber;
                    break;
                case '/':
                    finalNumber = secondNumber/firstNumber;
                    break;
                case '%':
                    finalNumber = secondNumber%firstNumber;
                    break;
                // default:
                //     throw std::runtime_error("unknown op");
            }
            finalStack.push(finalNumber);
        }
        else{
            finalStack.push(intInp); // adds to postfix if number
            // std::cout << "Added to stack: " << finalStack.peek() << std::endl;
        }
        // std::cout << "Top of Stack: " << finalStack.peek() << std::endl << std::endl;
    }
    std::cout << "Final Result: " << finalStack.peek()<< std::endl;


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
    // We push if it???s lower in PEMDAS. 
    // There is an exception for parentheses. Consider only what???s inside the parentheses. Or you can say that the parenthesis is the lowest in PEMDAS for this scenario.

// Final Outcome (in std::string) : 42+5*3+

// To come from postfix to final:
// Create an operand stack. Only for ???final numbers???
// If number, push into an expression until operand is reached and do operand. This is done by pop, operand, pop.
// Push the expression result onto the stack