/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:43:05 by ivotints          #+#    #+#             */
/*   Updated: 2024/09/24 15:43:48 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}
RPN::RPN(const RPN &) {}
RPN &RPN::operator=(const RPN &) {return (*this);}
RPN::~RPN() {}


RPN::RPN(const std::string &expression)
{
	for (int i = 0; expression[i]; ++i)
	{
		if (isspace(expression[i]))
			continue;
		else if (isdigit(expression[i]))
			stack.push(expression[i] - '0');
		else if (expression[i] == '-' && isdigit(expression[i + 1]))
		{
			double num = 0;
			while (isdigit(expression[i + 1]))
			{
				num *= 10;
				num += expression[i + 1] - '0';
				i++;
			}
			stack.push(num * -1);
		}
		else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/')
		{
			if (stack.size() < 2)
				throw std::invalid_argument("Error: not enough digits in stack.\n");
			double second = stack.top();
			stack.pop();
			double first = stack.top();
			stack.pop();

			if (expression[i] == '+')
				stack.push(first + second);
			else if (expression[i] == '-')
				stack.push(first - second);
			else if (expression[i] == '*')
				stack.push(first * second);
			else if (second == 0)
				throw std::invalid_argument("Error: division on zero.\n");
			else
				stack.push(first / second);
		}
		else
		{
			std::cerr << "Error: unknown symbol: " << expression[i] << "\n";
			throw std::invalid_argument("");
		}
	}
	if (stack.size() == 1)
		std::cout << "Result: " << stack.top() << std::endl;
	else if (stack.size() > 1)
		throw std::invalid_argument("Error: not all digits used.\n");
	else
		throw std::invalid_argument("Error: no digits in stack.\n");
}
