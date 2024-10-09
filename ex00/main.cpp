/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:58:09 by ivotints          #+#    #+#             */
/*   Updated: 2024/09/24 15:40:29 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int, char** av)
{
	try
	{
		BitcoinExchange data("data.csv");
		data.printExchangeRate(av[1]);
		for (int i = 2; av[i]; ++i)
			data.printExchangeRate(av[i]);
	}
	catch (std::exception &)
	{
		return (1);
	}
	return (0);
}
