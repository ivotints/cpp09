/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:58:09 by ivotints          #+#    #+#             */
/*   Updated: 2024/09/25 15:17:58 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
	try
	{
		if (ac == 2)
			RPN rpn(av[1]);
		else if (ac == 1)
			std::cout << "No input. Example of input: 2 3 +\n";
		else
		{
			std::stringstream ss;
			for (int i = 1; av[i]; ++i)
			{
				ss << av[i];
				ss << " ";
			}
			RPN rpn(ss.str());
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
		return (1);
	}
}
