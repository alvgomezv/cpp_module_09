#ifndef PmergeMe_hpp
# define PmergeMe_hpp

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <list>
#include <climits>
#include <ctime>


class PmergeMe
{
	private:
		std::vector<int>	_vector;
		std::list<int>		_list;

	public:
		PmergeMe(std::string numbers);
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe(void);

		void	checkNumbers(std::string numbers);
		void	fillVector(std::string numbers);
		void	fillList(void);
		void	SortVectorAndList(void);

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
