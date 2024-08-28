#ifndef SPAN_HPP
# define SPAN_HPP

#include <exception>
#include <iterator>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>

class Span
{
    private:
        unsigned int        _length;
        std::vector<int>    _numbers; 
    protected:

    public:
        Span(unsigned int n);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();


        void    addNumber(int n);
        int    shortestSpan();
        int    longestSpan();

        template<typename Iterator>
        void    addNumbers(Iterator begin, Iterator end)
        {
            if (std::distance(begin, end) + _numbers.size() > _length)
                throw LimitReachedException();
            _numbers.insert(_numbers.end(), begin, end);
        }

        class LimitReachedException : public std::exception
        {
            virtual const char* what() const throw();
        };

        class NoSpanPossibleException : public std::exception
        {
            virtual const char* what() const throw();
        };

};

#endif