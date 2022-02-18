#pragma once
#define EXPRESSIONANALYZER_H
#include <string>

class ExpressionAnalyzer{
    char c;
    std::string operatorList = "*/%+-()";
    // 0* , 1/ , 2% , 3+ , 4- , 5( , 6)
    int m_type;

    void getIdentifier();

public:
    ExpressionAnalyzer(char c);
    int getType() const;
};