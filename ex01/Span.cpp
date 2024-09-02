#include "Span.hpp"

Span::Span(unsigned int n)
{
    _length = n;
    _numbers = std::vector<int>();
    std::cout << "Default constructor called!" << std::endl;
}

Span::~Span()
{
    std::cout << "Destructor called!" << std::endl;
}

Span::Span(const Span& other)
{
    _length = other._length;
    _numbers.clear();
    _numbers = other._numbers;
    std::cout << "Copy constructor called!" << std::endl;
}

Span& Span::operator=(const Span &other)
{
    if(this != &other)
    {
        _numbers = other._numbers;
        _length = other._length;
    }
    return *this;
}

void    Span::addNumber(int number)
{
    if (_numbers.size() < _length)
    {
        _numbers.push_back(number);
        std::cout << "Succesfully added number " << number << " to the vector" << std::endl;
    }
    else
        throw LimitReachedException();
}

int     Span::shortestSpan()
{
    if (_numbers.size() < 2)
        throw NoSpanPossibleException();
    std::vector<int>    sortedVector(_numbers);
    std::sort(sortedVector.begin(), sortedVector.end());
    int shortest = sortedVector[1] - sortedVector[0];
    for (unsigned long i = 1; i < sortedVector.size() - 1; ++i)
    {
        int span = sortedVector[i + 1] - sortedVector[i];
        if (span < shortest)
            shortest = span;
    }
    return shortest;
}

int     Span::longestSpan()
{
    if (_numbers.size() < 2)
        throw NoSpanPossibleException();
    int max = *std::max_element(_numbers.begin(), _numbers.end());
    int min = *std::min_element(_numbers.begin(), _numbers.end());

    return (max - min);
}

const char* Span::LimitReachedException::what() const throw()
{
    return "Vector has reached the limit";
}

const char* Span::NoSpanPossibleException::what() const throw()
{
    return "No span possible";
}