#include "cParser.h"
#include <algorithm>

std::string cParser::parse_token()
{
	while (std::isspace(*sInput)) sInput++;

	if (std::isdigit(*sInput))
	{
		std::string sNumber;

		while (std::isdigit(*sInput) || *sInput == '.')
			sNumber.push_back(*sInput++);

		return sNumber;
	}

	static const std::string Tokens[] = { 
		"+", "-", "^", "*", "/", "%", "abs", "sin", "cos", "tan", "(", ")", "!",
		"sqrt", "asin", "acos", "atan"
	};

	for (auto& t : Tokens)
		if (std::strncmp(sInput, t.c_str(), t.size()) == 0)
		{
			sInput += t.size();
			return t;
		}

	return "";

}

Expression cParser::parse_simple_expression()
{
	std::string sToken = parse_token();

	if (sToken.empty())
		sState = "Invalid input";

	if (sToken == "(")
	{
		Expression result = parse_binary_expression(0);

		if (parse_token() != ")")
			sState = "Expected ')'";

		return result;
	}

	if (std::isdigit(sToken[0]))
		return Expression(sToken);

	return Expression(sToken, parse_simple_expression());
}

int cParser::get_priority(const std::string& binary_op)
{
	if (binary_op == "+") return 1;
	if (binary_op == "-") return 1;
	if (binary_op == "*") return 2;
	if (binary_op == "/") return 2;
	if (binary_op == "%") return 2;
	if (binary_op == "^") return 3;

	return 0;
}

Expression cParser::parse_binary_expression(int min_priority)
{
	Expression left_expr = parse_simple_expression();

	while (1)
	{
		std::string op = parse_token();
		int priority = get_priority(op);

		if (priority <= min_priority)
		{
			sInput -= op.size();
			return left_expr;
		}

		Expression right_expr = parse_binary_expression(priority);
		left_expr = Expression(op, left_expr, right_expr);
			
	}

}

long double cParser::Get(std::string input, bool in_radians)
{
	for (int i = 0; i < input.length(); i++)
		if (isalpha(input[i]))
			input[i] = tolower(input[i]);

	std::string sFrom = "pi";
	std::string sTo = std::to_string(PI);

    size_t start_pos = 0;

    while ((start_pos = input.find(sFrom, start_pos)) != std::string::npos) 
	{
        input.replace(start_pos, sFrom.length(), sTo);
        start_pos += sTo.length();
    }

	sInput = (char*)input.c_str();

	bRadians = in_radians;

	return evaluate(parse_binary_expression(0));
}

const char* cParser::GetState() const
{
	return sState.c_str();
}

long double cParser::evaluate(const Expression& e)
{
	switch (e.args.size())
	{
	case 2:
	{
		long double a = evaluate(e.args[0]);
		long double b = evaluate(e.args[1]);

		if (e.token == "+") return a + b;
		if (e.token == "-") return a - b;
		if (e.token == "*") return a * b;
		if (e.token == "/") return a / b;
		if (e.token == "^") return pow(a, b);
		if (e.token == "%") return (int)a % (int)b;

		sState = "Unknown binary operator";
	}

	case 1:
	{
		long double a = evaluate(e.args[0]);

		if (e.token == "+") return a;
		if (e.token == "-") return -a;
		if (e.token == "abs") return abs(a);
		if (e.token == "sin") return bRadians ? sin(a) : sin(a * PI / 180.0);
		if (e.token == "cos") return bRadians ? cos(a) : cos(a * PI / 180.0);
		if (e.token == "tan") return bRadians ? tan(a) : tan(a * PI / 180.0);
		if (e.token == "asin") return bRadians ? asin(a) : asin(a) / PI * 180.0;
		if (e.token == "acos") return bRadians ? acos(a) : acos(a) / PI * 180.0;
		if (e.token == "atan") return bRadians ? atan(a) : atan(a) / PI * 180.0;
		if (e.token == "sqrt") return sqrt(a);
		if (e.token == "!")
		{
			long int nResult = 1;
			for (long int i = 1; i <= (long int)a; i++)
				nResult *= i;

			return nResult;
		}

		sState = "Unknown unary operator";
	}

	case 0:
		return strtod(e.token.c_str(), nullptr);

	}

	sState = "Unknown expression type";
	return 0.0f;

}
