/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:36:10 by ivotints          #+#    #+#             */
/*   Updated: 2024/09/26 09:03:29 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <stack>

class RPN
{
	private:
		std::stack<double> stack;
		RPN();
		RPN(const RPN &);
		RPN &operator=(const RPN &);

	public:
		RPN(const std::string &expression);
		~RPN();
};
