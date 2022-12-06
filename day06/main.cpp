/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 07:56:02 by aweaver           #+#    #+#             */
/*   Updated: 2022/12/06 16:23:54 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <vector>
#include <string>



int main(void)
{
	std::ifstream		infile;
	std::string			buffer;
	std::vector<char>		stack[10];

	infile.open("input", std::fstream::in);
	while (std::getline(infile, buffer))
	{
		for (unsigned int i = 0; i < buffer.size() && i < buffer.size() - 4; i++)
		{
			int duplicate = 0;
			for (unsigned int j = 0; j < 13; j++)
			{
				if (duplicate == 1)
					break;
				for (unsigned int k = j + 1; k < 14; k++)
				{
					if (buffer[i + k] == buffer[i + j])
					{
						duplicate = 1;
						break;
					}
					else if (k == 13 && j == 12)
					{
						std::cout << "message at index: " << i + 14 << std::endl;
						return (0);
					}
				}
			}
		}
	}
	infile.close();
	return (0);
}
