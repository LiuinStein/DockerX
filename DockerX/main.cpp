#include <iostream>
#include <string>
#include <cstdlib>
#include "Help.h"
#include "Version.h"
#include <algorithm>

int main(int argc, char * argv[])
{
	if (argc == 1)
	{
		// no input params
		std::cout << g_HelpDocs[DOCS_GLOBAL] << std::endl;
		return 0;
	}

	// load additional function 
	if (argv[1] == std::string{ "registry" })
	{


	}
	else if (argv[1] == std::string{ "version" } || argv[1] == std::string{ "-v" } || argv[1] == std::string{ "--version" })
	{
		// output version information
		std::cout << "DockerX:" << std::endl;
		for (auto var : g_ver)
		{
			std::cout << var << std::endl;
		}
		std::cout << std::endl;
		system(("docker " + std::string{ argv[1] }).c_str());
	}
	else
	{
		// send request to docker
		std::string cmd;
		for (int i = 1; i < argc; i++)
		{
			cmd += argv[i] + std::string{ " " };
		}
		system(("docker " + cmd).c_str());
	}
	return 0;
}
