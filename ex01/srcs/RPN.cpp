/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 11:49:39 by miltavar          #+#    #+#             */
/*   Updated: 2026/02/12 12:42:17 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

RPN::RPN()
{
}

RPN::~RPN()
{
}

void	RPN::apply_op(char op)
{
	int	a;
	int	b;

	a = _pile.top();
	_pile.pop();
	b = _pile.top();
	_pile.pop();
	if (op == '*')
		_pile.push(b * a);
	else if (op == '/')
		_pile.push(b / a);
	else if (op == '+')
		_pile.push(b + a);
	else if (op == '-')
		_pile.push(b - a);
	else
		throw std::runtime_error("Error: invalid character");
}

bool	RPN::isNumber(std::string& token)
{
	return (token.size() == 1 && isdigit(token[0]));
}

void	RPN::processLine(std::string &str)
{
	std::stringstream	s(str);
	std::string			token;
	char				*end;

	while (s >> token)
	{
		if (isNumber(token))
			_pile.push(strtol(token.c_str(), &end, 10));
		else
		{
			if (token.size() != 1)
				throw std::runtime_error("Error: invalid character");
			apply_op(token[0]);
		}
	}
	if (_pile.size() != 1)
		throw std::runtime_error("Error: RPN failed");
	std::cout << _pile.top() << std::endl;
}
