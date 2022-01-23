#pragma once

#include <string>
#include <vector>

struct Expression
{
	Expression(std::string token) : token(token) {}
	Expression(std::string token, Expression a) : token(token), args{ a } {}
	Expression(std::string token, Expression a, Expression b) : token(token), args{ a, b } {}

	std::string token;
	std::vector<Expression> args;
};

class cParser
{
public:
	cParser() { }
	virtual ~cParser() { }

	long double Get(std::string input, bool in_radians);

	const char* GetState() const;

private:

	std::string parse_token();

	Expression parse_simple_expression();
	Expression parse_binary_expression(int min_priority);
	long double evaluate(const Expression& e);
	int get_priority(const std::string& binary_op);

	char* sInput;

	std::string sState = "OK";
	bool bRadians = true;
	const long double PI = 3.141592653589793116;
};

