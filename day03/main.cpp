/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 07:56:02 by aweaver           #+#    #+#             */
/*   Updated: 2022/12/04 20:04:57 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <vector>
#include <string>

int		ft_get_priorities(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 'a' + 1);
	if (c >= 'A' && c <= 'Z')
		return (c - 'A' + 27);
}

void	ft_split_halves(std::string input, std::string &firstHalf, std::string &secondHalf)
{
	//std::cout << "input: " << input << " input size: "  << input.size() << std::endl;
	firstHalf = input.substr(0, input.size() / 2);
	secondHalf = input.substr((input.size() / 2), input.size());
	//std::cout << "first half: " << firstHalf << " secondHalf: " << secondHalf << std::endl;
	//std::cout << "first half size: " << firstHalf.size() << " second half size: " << secondHalf.size() << std::endl;
	return ;
}

int	ft_check_duplicates(std::string firstLine, std::string secondLine, std::string thirdLine)
{
	int	tab[255];
	int ret = 0;

	for (int i = 0; i < 255; i++)
		tab[i] = 0;
	for (int i = 0; i < firstLine.size(); i++)
		tab[firstLine[i]] = 1;
	for (int i = 0; i < secondLine.size(); i++)
		if (tab[secondLine[i]] == 1)
			tab[secondLine[i]]++;
	for (int i = 0; i < thirdLine.size(); i++)
		if (tab[thirdLine[i]] == 2)
		{
			ret += ft_get_priorities(thirdLine[i]);
			tab[thirdLine[i]] = -1;
		}
	return (ret);
}

int main(void)
{
	std::ifstream		infile;
	std::string			buffer;
	int					elfNumber = 0;
	int					duplicates;
	int					totalPriorities;

	std::string firstLine, secondLine, thirdLine;
	infile.open("input", std::fstream::in);
	while (std::getline(infile, buffer))
	{
		int			hasDuplicates = 0;
		if (elfNumber % 3 == 0)
			firstLine = buffer;
		else if (elfNumber % 3 == 1)
			secondLine = buffer;
		else if (elfNumber % 3 == 2)
		{
			thirdLine = buffer;
			hasDuplicates += ft_check_duplicates(firstLine, secondLine, thirdLine);
			if (hasDuplicates)
			{
				duplicates++;
				totalPriorities += hasDuplicates;
				//std::cout << "elf number: " << elfNumber << " has duplicate items" << std::endl;
				//std::cout << "priorities: " << hasDuplicates << std::endl;
			}
		}
		elfNumber++;
	}
	std::cout << "number of duplicates in total: " << duplicates << std::endl;
	std::cout << "Priorities in total : " << totalPriorities << std::endl;
	infile.close();
	return (0);
}
