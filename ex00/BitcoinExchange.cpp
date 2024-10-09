/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:43:05 by ivotints          #+#    #+#             */
/*   Updated: 2024/09/24 15:43:48 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const char *database)
{
	std::ifstream file(database);

	if (!file.is_open())
	{
		std::cerr << "Error: could not open database.\n";
		throw std::invalid_argument("");
	}
	std::string price, date;
	std::getline(file, date);
	while (std::getline(file, date, ',') && std::getline(file, price))
	{
		double pricef;
		std::stringstream ss(price);
		ss >> pricef;
		if(ss.fail() || !ss.eof())
		{
			std::cerr << "Error: bad price in data.csv." << std::endl;
			continue;
		}
		exchangeRates[date] = pricef;
	}
	file.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &) {return (*this);}

BitcoinExchange::~BitcoinExchange() {}

static bool dateCheck(int month, int day, int year)
{
	if (month < 1 || month > 12 || day < 1)
		return (1);
	int m[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		m[1] = 29;
	if (day > m[month - 1])
		return (1);
	return (0);
}

void	BitcoinExchange::printExchangeRate(const char *input_file)
{
	std::ifstream file(input_file);
	if (!file.is_open())
	{
		std::cerr << "Error: could not open input file.\n";
		throw std::invalid_argument("");
	}
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		int		year;
		int		month;
		int		day;
		double	value;
		char	leftover;
		std::string date;
		if (line.size() < 14
			|| sscanf((line.c_str()), "%d-%d-%d | %lf%c", &year, &month, &day, &value, &leftover) != 4
			|| (date = line.substr(0, line.find(' '))).size() != 10
			|| dateCheck(month, day, year))
		{
			std::cout << "Error : bad input => " << line << std::endl;
			continue;
		}
		if (value > 1000)
		{
			std::cout << "Error: too large number.\n";
			continue;
		}
		if (value < 0)
		{
			std::cout << "Error: not a positive number.\n";
			continue;
		}
		std::map<std::string, double>::iterator it = exchangeRates.lower_bound(date);
		if (it == exchangeRates.begin())
		{
			std::map<std::string, double>::iterator it2 = exchangeRates.begin();
			std::cout << "Error. Database starts at " << (*it2).first << std::endl;
			continue;
		}
		if (it == exchangeRates.end() || (*it).first != date)
			--it;
		std::cout << date << " => " << value << " = " << value * (*it).second << std::endl;
	}
}
