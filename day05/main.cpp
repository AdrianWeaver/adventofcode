/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 07:56:02 by aweaver           #+#    #+#             */
/*   Updated: 2022/12/05 07:26:49 by aweaver          ###   ########.fr       */
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
		int	origin = 0;
		int	destination = 0;
		int	iteration = 0;
		if (buffer[0] == '[')
		{
			if (isalpha(buffer[1]))
				stack[1].push_back(buffer[1]);
			if (isalpha(buffer[5]))
				stack[2].push_back(buffer[5]);
			if (isalpha(buffer[9]))
				stack[3].push_back(buffer[9]);
			if (isalpha(buffer[13]))
				stack[4].push_back(buffer[13]);
			if (isalpha(buffer[17]))
				stack[5].push_back(buffer[17]);
			if (isalpha(buffer[21]))
				stack[6].push_back(buffer[21]);
			if (isalpha(buffer[25]))
				stack[7].push_back(buffer[25]);
			if (isalpha(buffer[29]))
				stack[8].push_back(buffer[29]);
			if (isalpha(buffer[33]))
				stack[9].push_back(buffer[33]);
		}
		if (buffer[0] == 'm')
		{
			iteration = std::atoi(&buffer[5]);
			origin = std::stoi(buffer.substr(buffer.find("from") + 5));
			destination = std::stoi(buffer.substr(buffer.find("to") + 3));
			//std::cout << "iteration: " << iteration << std::endl;
			//std::cout << "origin: " << origin << std::endl;
			//std::cout << "destination: " << destination << std::endl;
			for (int i = 0; i < iteration; i++)
			{
				stack[destination].insert(stack[destination].begin() + i, stack[origin][i]);
			}
			for (int i = 0; i < iteration; i++)
				stack[origin].erase(stack[origin].begin());
		}
	}
	for (int i = 1; i < 10; i++)
	{
		//std::cout << "stack " << i << " first item: " << stack[i][0] << std::endl;
		std::cout << stack[i][0];
	}
	infile.close();
	return (0);
}
