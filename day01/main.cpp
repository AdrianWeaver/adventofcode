/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 07:56:02 by aweaver           #+#    #+#             */
/*   Updated: 2022/12/02 09:48:14 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <vector>

int	ft_get_best_elf(std::vector<int> &elf)
{
	int	bestElf = 0;
	int max = 0;
	for (int i = 0; i < elf.size(); i++)
	{
		if (elf[i] > max)
		{
			max = elf[i];
			bestElf = i;
		}
	}
	std::cout << "Best elf is: " << bestElf << " he carries "
		<< max  << " calories." << std::endl;
	elf[bestElf] = 0;
	return (max);
}

int main(void)
{
	std::ifstream		infile;
	std::vector<int>			elf;
	std::string			buffer;
	int					number;

	number = 0;
	infile.open("input", std::fstream::in);
	while (std::getline(infile, buffer))
	{
		if (buffer.empty())
		{
			elf.push_back(number);
			number = 0;
		}
		else
			number += atoi(buffer.c_str());
	}
	int max;
	max = ft_get_best_elf(elf);
	max += ft_get_best_elf(elf);
	max += ft_get_best_elf(elf);
	std::cout << "The top 3 elves carry: " << max << " calories." << std::endl;
	infile.close();
	return (0);
}
