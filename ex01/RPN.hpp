#ifndef RPN_hpp
# define RPN_hpp

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <stack>


class RPN
{
	private:
		std::string		_calc;
		std::stack<float>	_stack;

	public:
		RPN(std::string calc);
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN(void);

		void	checkNumbers(std::string calc);
		int		fillAndCalculate(void);

	class InvalidArgumentException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Error: invalid argument");
			}
	};
};


#endif
