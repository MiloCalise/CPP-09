/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 13:23:31 by miltavar          #+#    #+#             */
/*   Updated: 2026/02/12 12:48:04 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <utility>
#include <fstream>
#include <string>
#include <cctype>
#include <stdlib.h>
#include <vector>
#include <iomanip>

class BitcoinExchange
{
private:
	std::map<std::string, float>	_db;
	bool	isValidDate(const std::string& date);
	bool	isValidValue(const std::string& value);
	float	getExchangeRate(const std::string& date);
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& copy);
	BitcoinExchange&	operator=(const BitcoinExchange& copy);
	~BitcoinExchange();
	void	loadDatabase(const std::string& str);
	void	loadInput(const std::string& str);
};

#endif
