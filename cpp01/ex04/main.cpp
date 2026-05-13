#include <iostream>
#include <fstream>
#include <string>

static int error(std::string message)
{
	std::cout << message << std::endl;
	return (1);
}

static std::string replaceAll(std::string const &src, std::string const &s1, std::string const &s2)
{
	std::string out;
	std::string::size_type pos = 0;
	std::string::size_type found;

	while (true)
	{
		found = src.find(s1, pos);
		if (found == std::string::npos)
		{
			out.append(src, pos, src.size() - pos);
			break;
		}
		out.append(src, pos, found - pos);
		out += s2;
		pos = found + s1.size();
	}
	return (out);
}

int main(int argc, char **argv)
{
	if (argc != 4)
		return (error("Error: expected 3 arguments"));

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (filename.empty())
		return (error("Error: filename is empty"));
	if (s1.empty())
		return (error("Error: s1 is empty"));

	std::ifstream in(filename.c_str());
	if (!in.is_open())
		return (error("Error: can't open input file"));

	std::string outname = filename + ".replace";
	std::ofstream out(outname.c_str());
	if (!out.is_open())
		return (error("Error: can't open output file"));

	std::string line;
	while (std::getline(in, line))
	{
		out << replaceAll(line, s1, s2);
		if (!in.eof())
			out << std::endl;
	}
	if (in.bad())
		return (error("Error: read error"));
	if (out.bad())
		return (error("Error: write error"));

	return (0);
}
