/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 11:49:44 by miltavar          #+#    #+#             */
/*   Updated: 2026/02/12 12:44:21 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

int	main(int argc, char **argv)
{
	RPN	stack;

	if (argc != 2)
		return (std::cerr << "only one argument required" << std::endl, 1);
	std::string	str(argv[1]);
	if (str.empty())
		throw std::runtime_error("Empty list of argument");
	try
	{
		stack.processLine(str);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
