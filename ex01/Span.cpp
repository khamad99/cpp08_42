/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:13:59 by kalshaer          #+#    #+#             */
/*   Updated: 2024/01/01 13:31:49 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) : _n(n)
{
	_v.reserve(n);
}

Span::Span(Span const & src)
{
	*this = src;
}

Span::~Span()
{
}

Span & Span::operator=(Span const & src)
{
	if (this != &src)
	{
		this->_n = src._n;
		this->_v = src._v;
	}
	return (*this);
}

void	Span::addNumber(int n)
{
	if (this->_v.size() >= this->_n)
		throw FullException();
	this->_v.push_back(n);
}

void	Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (this->_v.size() + std::distance(begin, end) > this->_n)
		throw FullException();
	this->_v.insert(this->_v.end(), begin, end);
}

int	Span::shortestSpan()
{
	if (this->_v.size() <= 1) 
		throw NoSpanException();
	std::sort(this->_v.begin(), this->_v.end());
	std::vector<int> differences(this->_v.size());
	std::adjacent_difference(this->_v.begin(), this->_v.end(), differences.begin());
	int minSpan = *std::min_element(differences.begin() + 1, differences.end());
	return minSpan;
}

int		Span::longestSpan()
{
	if (this->_v.size() <= 1)
		throw NoSpanException();
	std::vector<int> tmp = this->_v;
	std::sort(tmp.begin(), tmp.end());
	return (*(tmp.end() - 1) - *(tmp.begin()));
}

const char* Span::FullException::what() const throw()
{
	return ("Container is full");
}

const char* Span::NoSpanException::what() const throw()
{
	return ("No span to find");
}

