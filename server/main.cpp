#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
	std::string config_file;

	for(int i = 0; i < argc; ++i)
	{
		switch(argv[i])
		{
			case "-c":
				if(i+1 <= argc) 
				{
					std::cout << "filename can't be empty" << std::endl;
					return 0;
				}
				config_file = argv[i + 1];
				i++;
				break;
			case "--help":
				//todo write help
				std::cout << "not wried yet" << std::endl;
				break;
			default:
				std::cout << "argument " << argv[i] << " is wrong" << std::endl;
		}
	}
	
	Config config;
	config.load(config_file);

}
