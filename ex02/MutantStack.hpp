#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <string>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
    private:

    protected:

    public:
        typedef typename std::stack<T>::container_type::iterator    iterator;
        typedef typename std::stack<T>::container_type::reverse_iterator    reverse_iterator;

        MutantStack() : std::stack<T>() 
        {

        }

        MutantStack(const MutantStack& other) : std::stack<T>(other)
        {

        }

        MutantStack& operator=(const MutantStack& other)
        {
            if (this != other)
                std::stack<T>::operator=(other);
            return *this;
        }

        virtual ~MutantStack()
        {

        }

        iterator    begin()
        {
            return std::stack<T>::c.begin();
        }

        iterator end()
        {
            return std::stack<T>::c.end();
        }

        reverse_iterator    rbegin()
        {
            return std::stack<T>::c.rbegin();
        }

        reverse_iterator rend()
        {
            return std::stack<T>::c.rend();
        }
};

#endif