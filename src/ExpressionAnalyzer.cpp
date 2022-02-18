#include "../headers/ExpressionAnalyzer.h"

ExpressionAnalyzer::ExpressionAnalyzer(char c)
	: c(c)
{
	getIdentifier();
}

void ExpressionAnalyzer::getIdentifier(){
	int type = operatorList.find(c);
	if (type != -1){ // might need -1 to be npos
		m_type = type; // returns priority number if operator
	}
	else{ m_type = type; } // returns -1 if number
}

int ExpressionAnalyzer::getType() const{ return m_type; }