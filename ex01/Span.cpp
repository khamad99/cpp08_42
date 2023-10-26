/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:13:59 by kalshaer          #+#    #+#             */
/*   Updated: 2023/10/26 11:34:15 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) : _n(n)
{
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

int		Span::shortestSpan()
{
	if (this->_v.size() <= 1)
		throw NoSpanException();
	std::vector<int> tmp = this->_v;
	std::sort(tmp.begin(), tmp.end());
	int min = std::numeric_limits<int>::max();
	for (std::vector<int>::iterator it = tmp.begin(); it != tmp.end() - 1; it++)
	{
		if (*(it + 1) - *it < min)
			min = *(it + 1) - *it;
	}
	return (min);
}

int		Span::longestSpan()
{
	if (this->_v.size() <= 1)
		throw NoSpanException();
	std::vector<int> tmp = this->_v;
	std::sort(tmp.begin(), tmp.end());
	return (*(tmp.end() - 1) - *(tmp.begin()));
}


