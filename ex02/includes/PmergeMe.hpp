/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 12:51:39 by miltavar          #+#    #+#             */
/*   Updated: 2026/02/13 14:59:16 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <deque>
#include <vector>
#include <sstream>
#include <string>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <algorithm>

class PmergeMe
{
private:
	std::deque<int>		_d;
	std::vector<int>	_v;
	std::vector<std::pair<int, int>>	_vpairs;
	std::deque<std::pair<int, int>>		_dpairs;
	void	makeVPairs();
	void	makeDPairs();
	void	sortDPairs();
	void	sortVPairs();
	bool	_isOdd = 0;
	bool	comparePairs(std::pair<int, int>& a, std::pair<int, int>& b);
public:
	PmergeMe();
	PmergeMe(const PmergeMe& copy);
	PmergeMe&	operator=(const PmergeMe& copy);
	~PmergeMe();
	void	parseInput(const std::string& str);
	void	displayLists();
	void	sortVector();
	void	sortDeque();
};
