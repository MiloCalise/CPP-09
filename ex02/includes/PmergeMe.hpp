/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 12:51:39 by miltavar          #+#    #+#             */
/*   Updated: 2026/02/14 13:57:42 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <deque>
#include <vector>
#include <sstream>
#include <string>
#include <iomanip>
#include <sys/time.h>
#include <stdlib.h>
#include <algorithm>

class PmergeMe
{
private:
	std::deque<int>							_d;
	std::vector<int>						_v;
	std::vector<std::pair<int, int> >		_vpairs;
	std::deque<std::pair<int, int> >		_dpairs;
	std::vector<int>						_vmain;
	std::vector<int>						_vpend;
	std::deque<int>							_dmain;
	std::deque<int>							_dpend;
	bool									_isOdd;
	int										_odd;
	void									makeVPairs();
	void									makeDPairs();
	void									sortDPairs();
	void									sortVPairs();
	void									buildDchains();
	void									buildVchains();
	void									binaryInsertD(int value);
	void									binaryInsertV(int value);
public:
	PmergeMe();
	PmergeMe(const PmergeMe& copy);
	PmergeMe&								operator=(const PmergeMe& copy);
	~PmergeMe();
	void									parseInput(const std::string& str);
	void									display();
	void									sortVector();
	void									sortDeque();
};

bool										comparePairs(const std::pair<int, int>& a, const std::pair<int, int>& b);
