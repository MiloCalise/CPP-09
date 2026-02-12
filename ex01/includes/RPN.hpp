/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 11:49:34 by miltavar          #+#    #+#             */
/*   Updated: 2026/02/12 12:48:48 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <stdlib.h>

class RPN
{
private:
	std::stack<int>	_pile;
	void			apply_op(char op);
	bool			isNumber(std::string& token);
public:
	RPN();
	RPN(const RPN& copy);
	RPN&	operator=(const RPN& copy);
	~RPN();
	void	processLine(std::string& str);
};

#endif
