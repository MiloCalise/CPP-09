/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 13:24:16 by miltavar          #+#    #+#             */
/*   Updated: 2026/02/11 19:07:34 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
}

static int daysInMonth(int month, int year)
{
	if (month == 2)
	{
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
			return 29;
		return 28;
	}
	if (month == 4 || month == 6 || month == 9 || month == 11)
		return 30;
	return 31;
}

static std::vector<std::string> split(const std::string& str, char delimiter)
{
	std::vector<std::string> result;
	size_t start = 0;
	size_t end = str.find(delimiter);
	while (end != std::string::npos)
	{
		result.push_back(str.substr(start, end - start));
		start = end + 1;
		end = str.find(delimiter, start);
	}
	result.push_back(str.substr(start));
	return result;
}

static std::string	trim(const std::string& str)
{
	size_t start = 0;
	while (start < str.size() && std::isspace(str[start]))
		start++;
	size_t end = str.size();
	while (end > start && std::isspace(str[end - 1]))
		end--;
	return (str.substr(start, end - start));
}

bool	BitcoinExchange::isValidDate(const std::string& date)
{
	if (date.size() != 10)
		return (std::cerr << "Error: bad input => " << date << std::endl, 0);
	if (date.find_first_of('-') != 4)
		return (std::cerr << "Error: bad input => " << date << std::endl, 0);
	if (date.find_first_of('-', 5) != 7)
		return (std::cerr << "Error: bad input => " << date << std::endl, 0);
	std::string year = date.substr(0, 4);
	std::string month = date.substr(5, 2);
	std::string days = date.substr(8, 2);
	for (int i = 0; year[i]; i++)
		if (!isdigit(static_cast<unsigned char>(year[i])))
			return (std::cerr << "Error: bad input => " << date << std::endl, 0);
	for (int i = 0; month[i]; i++)
		if (!isdigit(static_cast<unsigned char>(month[i])))
			return (std::cerr << "Error: bad input => " << date << std::endl, 0);
	for (int i = 0; days[i]; i++)
		if (!isdigit(static_cast<unsigned char>(days[i])))
			return (std::cerr << "Error: bad input => " << date << std::endl, 0);
	int m = atoi(month.c_str());
	if (m < 1)
		return (std::cerr << "Error: not a positive number" << std::endl, 0);
	if (m > 12)
		return (std::cerr << "Error: too large a number" << std::endl, 0);
	int d = atoi(days.c_str());
	int y = atoi(year.c_str());
	int max = daysInMonth(m, y);
	if (d < 1)
		return (std::cerr << "Error: not a positive number" << std::endl, 0);
	if (d > max)
		return (std::cerr << "Error: too large a number" << std::endl, 0);
	return (1);
}

bool	BitcoinExchange::isValidValue(const std::string& value)
{
	int				count = 0;
	int				pos = value.size();
	char			*end;

	if (!value.empty() && value[0] == '.')
		return (std::cerr << "Error: bad input => " << value << std::endl, 0);
	for (unsigned long i = 0; i < value.size(); i++)
	{
		if (value[i] == '.')
		{
			pos = i;
			count++;
		}
		if (!isdigit(value[i]) && value[i] != '.' && value[i] != '-')
			return (std::cerr << "Error: bad input => " << value << std::endl, 0);
	}
	if (count > 1)
		return (std::cerr << "Error: bad input => " << value << std::endl, 0);
	long long n = strtol(value.c_str(), &end, 10);
	if (n < 0)
		return (std::cerr << "Error: not a positive number" << std::endl, 0);
	if (n > 999)
		return (std::cerr << "Error: too large a number" << std::endl, 0);
	return (1);
}

float	BitcoinExchange::getExchangeRate(const std::string& date)
{
	std::map<std::string, float>::iterator	it = _db.lower_bound(date);
	if (it == _db.end())
	{
		if (_db.empty())
			throw std::runtime_error("Database empty");
		--it;
	}
	else if (it->first != date && it != _db.begin())
		--it;
	return (it->second);
}

void	BitcoinExchange::loadDatabase(const std::string& str)
{
	std::ifstream	file;
	std::string		date_buff;
	std::string		value_buff;
	char			*end;

	file.open(str.c_str(), std::fstream::in);
	if (file.fail() || file.bad())
		throw std::exception();
	std::getline(file, date_buff);
	while (std::getline(file, date_buff))
	{
		std::vector<std::string> vec = split(date_buff, ',');
		if (vec.size() != 2)
		{
			std::cerr << "Error: bad input => " << date_buff << std::endl;
			continue;
		}
		date_buff = vec[0];
		value_buff = vec[1];
		std::pair<std::string, float>	pair(date_buff, strtof(value_buff.c_str(), &end));
		_db.insert(pair);
	}
	if (file.bad() || (file.fail() && !file.eof()))
		throw std::runtime_error("file error");
	file.close();
}

void	BitcoinExchange::loadInput(const std::string& str)
{
	std::ifstream	file;
	std::string		date_buff;
	std::string		value_buff;
	char			*end;

	file.open(str.c_str(), std::fstream::in);
	if (file.fail() || file.bad())
		throw std::runtime_error("file error");
	std::getline(file, date_buff);
	while (std::getline(file, date_buff))
	{
		std::vector<std::string> vec = split(date_buff, '|');
		if (vec.size() != 2)
		{
			std::cerr << "Error: bad input => " << date_buff << std::endl;
			continue;
		}
		date_buff = vec[0];
		value_buff = vec[1];
		date_buff = trim(date_buff);
		value_buff = trim(value_buff);
		if (isValidDate(date_buff) && isValidValue(value_buff))
			std::cout << date_buff << " => " << value_buff << " = " << getExchangeRate(date_buff) * strtof(value_buff.c_str(), &end) << std::endl;
	}
	if (file.bad() || (file.fail() && !file.eof()))
			throw std::runtime_error("file error");
	file.close();
}
