/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 07:56:02 by aweaver           #+#    #+#             */
/*   Updated: 2022/12/02 08:50:00 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <vector>

int main(void)
{
	std::ifstream		infile;
	int					elf[1000];
	int					elfNumber = 0;
	std::string			buffer;
	int					number;
	int					bestElf;;

	number = 0;
	infile.open("input", std::fstream::in);
	while (std::getline(infile, buffer))
	{
		if (buffer.empty())
		{
			elf[elfNumber] = number;
			elfNumber++;
			number = 0;
		}
		else
			number += atoi(buffer.c_str());
	}
	int max = 0;
	for (int i = 0; i < elfNumber; i++)
	{
		if (elf[i] > max)
		{
			max = elf[i];
			bestElf = i;
		}
	}
	std::cout << "Best elf is: " << bestElf << " he carries "
		<< max  << " calories." << std::endl;
	infile.close();
	return (0);
}
