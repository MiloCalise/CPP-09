/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 12:51:44 by miltavar          #+#    #+#             */
/*   Updated: 2026/02/14 14:17:50 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

int	main(int argc, char **argv)
{
	PmergeMe	og;
	struct timeval start;
	struct timeval end;

	if (argc < 2)
		return (std::cerr << "list of integer requires" << std::endl, 1);
	try
	{
		for (int i = 1; i < argc; i++)
		{
			std::string	s(argv[i]);
			og.parseInput(s);
		}
		std::cout << "before: ";
		og.display();
		std::cout << std::endl;
		PmergeMe	Deque = og;
		PmergeMe	Vector = og;
		gettimeofday(&start, NULL);
		Deque.sortDeque();
		gettimeofday(&end, NULL);
		std::cout << "after:  ";
		Deque.display();
		std::cout << std::endl;
		double time = (end.tv_sec - start.tv_sec) * 1000.0;
		time += (end.tv_usec - start.tv_usec) / 1000.0;
		std::cout << std::fixed << std::setprecision(5) << "Time to process a range of " << argc - 1 << " elements with std::Deque : " << time << " ms" << std::endl;
		gettimeofday(&start, NULL);
		Vector.sortVector();
		gettimeofday(&end, NULL);
		time = (end.tv_sec - start.tv_sec) * 1000.0;
		time += (end.tv_usec - start.tv_usec) / 1000.0;
		std::cout << std::fixed << std::setprecision(5) << "Time to process a range of " << argc - 1 << " elements with std::Vector : " << time << " ms" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}
