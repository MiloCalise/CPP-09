/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 12:51:51 by miltavar          #+#    #+#             */
/*   Updated: 2026/02/14 14:10:07 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe& copy)
{
	*this = copy;
}

PmergeMe&	PmergeMe::operator=(const PmergeMe& copy)
{
	if (this != &copy)
	{
		_isOdd = copy._isOdd;
		_odd = copy._odd;
		_d = copy._d;
		_v = copy._v;
		_vpairs = copy._vpairs;
		_dpairs = copy._dpairs;
		_vmain = copy._vmain;
		_vpend = copy._vpend;
		_dmain = copy._dmain;
		_dpend = copy._dpend;
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{
}

void	PmergeMe::binaryInsertD(int value)
{
	std::deque<int>::iterator pos;

	pos = std::lower_bound(_dmain.begin(), _dmain.end(), value);
	_dmain.insert(pos, value);
}

void	PmergeMe::binaryInsertV(int value)
{
	std::vector<int>::iterator	pos;

	pos = std::lower_bound(_vmain.begin(), _vmain.end(), value);
	_vmain.insert(pos, value);
}

void	PmergeMe::buildDchains()
{
	for (size_t i = 0; i < _dpairs.size(); i++)
	{
		_dmain.push_back(_dpairs[i].second);
		_dpend.push_back(_dpairs[i].first);
	}
}

void	PmergeMe::buildVchains()
{
	for (size_t i = 0; i < _vpairs.size(); i++)
	{
		_vmain.push_back(_vpairs[i].second);
		_vpend.push_back(_vpairs[i].first);
	}
}

void	PmergeMe::parseInput(const std::string& str)
{
	char	*end;

	_isOdd = 0;
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

void	PmergeMe::display()
{
	int	len = _d.size();

	for (int i = 0; i < len && i < 5; i++)
		std::cout << _d[i] << " ";
	if (len > 5)
		std::cout << "[...]";
}

bool	comparePairs(const std::pair<int, int>& a, const std::pair<int, int>& b)
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
			_odd = f;
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
	sortDPairs();
	buildDchains();
	for (size_t i = 0; i < _dpend.size(); i++)
		binaryInsertD(_dpend[i]);
	if (_isOdd)
		binaryInsertD(_odd);
	_d.swap(_dmain);
}

void	PmergeMe::sortVector()
{
	if (_v.size() <= 1)
		return ;
	makeVPairs();
	sortVPairs();
	buildVchains();
	for (size_t i = 0; i < _vpend.size(); i++)
		binaryInsertV(_vpend[i]);
	if (_isOdd)
		binaryInsertV(_odd);
	_v.swap(_vmain);
}
