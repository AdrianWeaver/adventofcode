/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 07:56:02 by aweaver           #+#    #+#             */
/*   Updated: 2022/12/04 17:58:20 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <vector>
#include <string>

void	ft_get_limits(std::string input, int &elfOneLowerLimit, int &elfOneUpperLimit, int &elfTwoLowerLimit, int &elfTwoUpperLimit)
{
		std::string	elfOneInput;
		std::string	elfTwoInput;
		size_t		found;
		found = input.find(",");
		if (found)
		{
			elfOneInput = input.substr(0, found);
			elfTwoInput = input.substr(found + 1, input.size());
		}
		{
		}
		found = elfOneInput.find("-");
		if (found)
		{
			elfOneLowerLimit = stoi(elfOneInput.substr(0, found));
			elfOneUpperLimit = stoi(elfOneInput.substr(found + 1, elfOneInput.size()));
		}
		found = elfTwoInput.find("-");
		if (found)
		{
			elfTwoLowerLimit = stoi(elfTwoInput.substr(0, found));
			elfTwoUpperLimit = stoi(elfTwoInput.substr(found + 1, elfTwoInput.size()));
		}
	return ;
}

int	ft_check_overlap(int firstLower, int firstUpper, int secondLower, int secondUpper)
{
	if (firstLower >= secondLower && firstLower <= secondUpper)
		return (1);
	else if (firstUpper >= secondLower && firstUpper <= secondUpper)
		return (1);
	else
		return (0);
}

int main(void)
{
	std::ifstream		infile;
	std::string			buffer;
	int					score = 0;
	int					opponentScore = 0;
	int					elfNumber = 0;
	int					overlap = 0;

	infile.open("input", std::fstream::in);
	while (std::getline(infile, buffer))
	{
		int	elfOneLowerLimit, elfOneUpperLimit, elfTwoLowerLimit, elfTwoUpperLimit;
		size_t	found;
		int		elfOverlap = 0;
		ft_get_limits(buffer, elfOneLowerLimit, elfOneUpperLimit, elfTwoLowerLimit, elfTwoUpperLimit);
		if (ft_check_overlap(elfOneLowerLimit, elfOneUpperLimit, elfTwoLowerLimit, elfTwoUpperLimit))
			elfOverlap = 1;
		if (ft_check_overlap(elfTwoLowerLimit, elfTwoUpperLimit, elfOneLowerLimit, elfOneUpperLimit))
			elfOverlap = 1;
		if (elfOverlap == 1)
		{
			std::cout << "elves number: " << elfNumber << " overlap!" << std::endl;
			overlap++;
		}
		elfNumber++;
	}
	std::cout << "number of elves overlaping: " << overlap << std::endl;
	std::cout << "number of pairs in total: " << elfNumber << std::endl;
	infile.close();
	return (0);
}
