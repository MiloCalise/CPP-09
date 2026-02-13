/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 12:51:51 by miltavar          #+#    #+#             */
/*   Updated: 2026/02/13 15:05:34 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}

void	PmergeMe::parseInput(const std::string& str)
{
	char	*end;

	if (str.empty())
		throw std::runtime_error("input is invalid");
	for (unsigned long i = 0; i < str.size(); i++)
		if (!isdigit(str[i]))
			throw std::runtime_error("input is invalid");
	long long value = strtol(str.c_str(), &end, 10);
	if (*end != '\0')
		throw std::runtime_error("input is invalid");
	if (value < 0 || value > 2147483647)
		throw std::runtime_error("input is invalid");
	if (std::find(_v.begin(), _v.end(), value) != _v.end())
		throw std::runtime_error("duplicate");
	_v.push_back(value);
	_d.push_back(value);
}

void	PmergeMe::displayLists()
{
	std::vector<int>::iterator	vit = _v.begin();
	std::vector<int>::iterator	vite = _v.end();
	std::deque<int>::iterator	dit = _d.begin();
	std::deque<int>::iterator	dite = _d.end();

	std::cout << "vector : ";
	while (vit != vite)
	{
		std::cout << *vit;
		++vit;
		if (vit != vite)
			std::cout << " ";
	}
	std::cout << std::endl << "deque : ";
	while (dit != dite)
	{
		std::cout << *dit;
		++dit;
		if (dit != dite)
			std::cout << " ";
	}
}

bool	PmergeMe::comparePairs(std::pair<int, int>& a, std::pair<int, int>& b)
{
	return (a.second < b.second);
}

void	PmergeMe::sortDPairs()
{
	std::sort(_dpairs.begin(), _dpairs.end(), comparePairs);
}

void	PmergeMe::sortVPairs()
{
	std::sort(_vpairs.begin(), _vpairs.end(), comparePairs);
}

void	PmergeMe::makeDPairs()
{
	std::deque<int>::iterator	it = _d.begin();
	std::deque<int>::iterator	ite = _d.end();
	int							f;
	int							s;

	while (it != ite)
	{
		f = *it;
		++it;
		if (it != ite)
		{
			s = *it;
			++it;
		}
		else
		{
			_isOdd = 1;
			_dpairs.push_back(std::make_pair(f, 0));
			break ;
		}
		if (f > s)
			std::swap(f, s);
		_dpairs.push_back(std::make_pair(f, s));
	}
}

void	PmergeMe::makeVPairs()
{
	std::vector<int>::iterator	it = _v.begin();
	std::vector<int>::iterator	ite = _v.end();
	int							f;
	int							s;

	while (it != ite)
	{
		f = *it;
		++it;
		if (it != ite)
		{
			s = *it;
			++it;
		}
		else
		{
			_isOdd = 1;
			_vpairs.push_back(std::make_pair(f, 0));
			break ;
		}
		if (f > s)
			std::swap(f, s);
		_vpairs.push_back(std::make_pair(f, s));
	}
}

void	PmergeMe::sortDeque()
{
	if (_d.size() <= 1)
		return ;
	makeDPairs();
}

void	PmergeMe::sortVector()
{
	if (_v.size() <= 1)
		return ;
	makeVPairs();
}
