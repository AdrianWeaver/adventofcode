/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 07:56:02 by aweaver           #+#    #+#             */
/*   Updated: 2022/12/02 10:04:30 by aweaver          ###   ########.fr       */
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
		opponentScore += buffer[0] - 'A' + 1;
		score += buffer[2] - 'X' + 1;
		std::cout << "buffer: " << buffer << "score: " << buffer[2] - 'X' + 1 << std::endl;
		if (!buffer.empty())
		{
			if (buffer[0] == 'A')
			{
				if (buffer[2] == 'X')
				{
					score += 3;
					opponentScore += 3;
				}
				else if (buffer[2] == 'Y')
					score += 6;
				else if (buffer[2] == 'Z')
					opponentScore += 6;
			}
			else if (buffer[0] == 'B')
			{
				if (buffer[2] == 'Y')
				{
					score += 3;
					opponentScore += 3;
				}
				else if (buffer[2] == 'Z')
					score += 6;
				else if (buffer[2] == 'X')
					opponentScore += 6;
			}
			else if (buffer[0] == 'C')
			{
				if (buffer[2] == 'Z')
				{
					score += 3;
					opponentScore += 3;
				}
				else if (buffer[2] == 'X')
					score += 6;
				else if (buffer[2] == 'Y')
					opponentScore += 6;
			}
		}
	}
	std::cout << "Opponent score: " << opponentScore << " My score: " << score << std::endl;
	infile.close();
	return (0);
}
