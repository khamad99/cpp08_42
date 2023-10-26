/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:36:42 by kalshaer          #+#    #+#             */
/*   Updated: 2023/10/26 14:06:59 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int main()
{
	{
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		mstack.push(42);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	std::cout << "---------------------" << std::endl;
	{
		MutantStack<int> mstack;
		std::list<int> lst;

		mstack.push(5);
		mstack.push(17);
		lst.push_back(5);
		lst.push_back(17);

		std::cout << mstack.top() << std::endl;
		std::cout << lst.back() << std::endl;

		mstack.pop();
		lst.pop_back();

		std::cout << mstack.size() << std::endl;
		std::cout << lst.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		mstack.push(42);
		lst.push_back(3);
		lst.push_back(5);
		lst.push_back(737);
		lst.push_back(0);
		lst.push_back(42);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		std::list<int>::iterator lit = lst.begin();
		std::list<int>::iterator lite = lst.end();

		++it;
		--it;
		++lit;
		--lit;
		while (it != ite && lit != lite)
		{
			std::cout << *it << std::endl;
			std::cout << *lit << std::endl;
			++it;
			++lit;
		}

		std::stack<int> s(mstack);
	}

	return 0;
}