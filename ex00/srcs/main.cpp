/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 13:24:06 by miltavar          #+#    #+#             */
/*   Updated: 2026/02/11 18:50:28 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (std::cerr << "requires an input file" << std::endl, 1);
	std::setprecision(2);
	BitcoinExchange	map;
	try
	{
		map.loadDatabase("data.csv");
		map.loadInput(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
