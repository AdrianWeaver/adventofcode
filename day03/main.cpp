/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 07:56:02 by aweaver           #+#    #+#             */
/*   Updated: 2022/12/04 19:53:59 by aweaver          ###   ########.fr       */
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

int	ft_check_duplicates(std::string firstHalf, std::string secondHalf)
{
	int	tab[255];
	int ret = 0;

	for (int i = 0; i < 255; i++)
		tab[i] = 0;
	for (int i = 0; i < firstHalf.size(); i++)
		tab[firstHalf[i]] = 1;
	for (int i = 0; i < secondHalf.size(); i++)
		if (tab[secondHalf[i]] == 1)
		{
			ret += ft_get_priorities(secondHalf[i]);
			//std::cout << "letter: " << secondHalf[i] << " ret: " << ret << std::endl;
			tab[secondHalf[i]] = -1;
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

	infile.open("input", std::fstream::in);
	while (std::getline(infile, buffer))
	{
		std::string firstHalf, secondHalf;
		int			hasDuplicates = 0;
		ft_split_halves(buffer, firstHalf, secondHalf);
		hasDuplicates += ft_check_duplicates(firstHalf, secondHalf);
		if (hasDuplicates)
		{
			duplicates++;
			totalPriorities += hasDuplicates;
			//std::cout << "elf number: " << elfNumber << " has duplicate items" << std::endl;
			//std::cout << "priorities: " << hasDuplicates << std::endl;
		}
		elfNumber++;
	}
	std::cout << "number of duplicates in total: " << duplicates << std::endl;
	std::cout << "Priorities in total : " << totalPriorities << std::endl;
	infile.close();
	return (0);
}
