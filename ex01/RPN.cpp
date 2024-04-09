#include"RPN.hpp"

RPN::RPN(std::string calc)
{
	this->checkNumbers(calc);
}

RPN::RPN(const RPN& other)
{
	*this = other;
}

RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
	{
		this->_calc = other._calc;
		this->_stack = other._stack;
	}
	return *this;
}

RPN::~RPN(void)
{
	return;
}

void	RPN::checkNumbers(std::string calc)
{
	for (int i = 0; calc[i]; i++)
	{
		if (calc[i] == ' ' || calc[i] == '\t')
		{
			// std::cout << calc[i] << std::endl;
			continue;
		}
		if (calc[i] == '+' || calc[i] == '-' || calc[i] == '/' || calc[i] == '*')
		{
			// std::cout << calc[i] << std::endl;
			continue;
		}
		if (calc[i] >= '0' && calc[i] <= '9' && (!calc[i + 1] || (calc[i + 1] < '0' || calc[i + 1] > '9')))
		{
			// std::cout << calc[i] << std::endl;
			continue;
		}
		throw RPN::InvalidArgumentException();
	}
	_calc = calc;
}

int	RPN::fillAndCalculate(void)
{
	for (int i = 0; _calc[i]; i++)
	{
		if (_calc[i] == ' ' || _calc[i] == '\t')
			continue;
		if (_calc[i] == '+' || _calc[i] == '-' || _calc[i] == '/' || _calc[i] == '*')
		{
			if (this->_stack.size() < 2)
				throw RPN::InvalidArgumentException();
			float a = this->_stack.top();
			this->_stack.pop();
			float b = this->_stack.top();
			this->_stack.pop();
			if (_calc[i] == '+')
				this->_stack.push(b + a);
			else if (_calc[i] == '-')
				this->_stack.push(b - a);
			else if (_calc[i] == '/')
			{
				if (a == 0)
					throw RPN::InvalidArgumentException();
				this->_stack.push(b / a);
			}
			else if (_calc[i] == '*')
				this->_stack.push(b * a);
			// std::cout << b << " " << _calc[i] << " " << a << " = " << this->_stack.top() << std::endl;
		}
		else
			this->_stack.push(_calc[i] - '0');
	}
	if (this->_stack.size() != 1)
		throw RPN::InvalidArgumentException();
	return this->_stack.top();
}