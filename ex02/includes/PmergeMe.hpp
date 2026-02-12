/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 12:51:39 by miltavar          #+#    #+#             */
/*   Updated: 2026/02/12 13:07:12 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <deque>
#include <vector>
#include <sstream>
#include <string>
#include <iomanip>
#include <time.h>

class PmergeMe
{
private:
	std::deque<int>		_d;
	std::vector<int>	_v;
public:
	PmergeMe();
	PmergeMe(const PmergeMe& copy);
	PmergeMe&	operator=(const PmergeMe& copy);
	~PmergeMe();
};
