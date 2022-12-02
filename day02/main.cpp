/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 07:56:02 by aweaver           #+#    #+#             */
/*   Updated: 2022/12/02 10:23:33 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <vector>

int main(void)
{
	std::ifstream		infile;
	std::string			buffer;
	int					score = 0;
	int					opponentScore = 0;

	infile.open("input", std::fstream::in);
	while (std::getline(infile, buffer))
	{
		int current = buffer[0] - 'A' + 1;
		opponentScore += current;
		if (!buffer.empty())
		{
			if (buffer[2] == 'X')
			{
				if (current != 1)
					score += current - 1;
				else
					score += 3;
				opponentScore += 6;
			}
			else if (buffer[2] == 'Y')
			{
				score += current;
				score += 3;
				opponentScore += 3;
			}
			else if (buffer[2] == 'Z')
			{
				if (current != 3)
					score += current + 1;
				else
					score += 1;
				score += 6;
			}
		}
	}
	std::cout << "Opponent score: " << opponentScore << " My score: " << score << std::endl;
	infile.close();
	return (0);
}
