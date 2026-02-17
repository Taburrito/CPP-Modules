/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 11:32:22 by awaegaer          #+#    #+#             */
/*   Updated: 2026/01/28 17:02:25 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

int	main(int argc, char **argv)
{
	if (argc != 4)
		return(std::cout << "correct use: \"./sed_is_for_losers filename s1 s2" << std::endl, 1);

	std::string			filename = argv[1];
	std::string			outfile = filename + ".replace";
	std::string			s1 = argv[2];
	if (s1.empty())
		return (std::cout << "Can't replace nothing (s1 is empty)" << std::endl, 1);
	std::string			s2 = argv[3];

	std::ifstream		filename_stream(filename.c_str());
	if (!filename_stream.is_open())
		return (std::cout << "cannot open file" << std::endl, 1);
	std::stringstream	buffer;
	buffer << filename_stream.rdbuf();
	std::string			file_content = buffer.str();
	std::ofstream		outfile_stream(outfile.c_str());
	if (!outfile_stream.is_open())
		return (std::cout << "cannot open outfile" <<std::endl, 1);

	std::size_t			pos = 0;
	while ((pos = file_content.find(s1, pos)) != std::string::npos)
	{
		file_content.replace(pos, s1.length(), s2);
		pos += s2.length();
	}
	outfile_stream << file_content;
	outfile_stream.close();
	filename_stream.close();
	return (0);
}
