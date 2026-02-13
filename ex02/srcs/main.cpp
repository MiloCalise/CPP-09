/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 12:51:44 by miltavar          #+#    #+#             */
/*   Updated: 2026/02/13 13:17:32 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (std::cerr << "list of integer requires" << std::endl, 1);
	PmergeMe	v;
	try
	{
		for (int i = 1; i < argc; i++)
		{
			std::string	s(argv[i]);
			v.parseInput(s);
		}
		v.displayLists();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
