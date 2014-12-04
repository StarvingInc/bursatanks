#include <iostream>
#include <string>

int main(int argc, char* argv[])
{


	for(int i = 0; i < argc; ++i)
	{
		switch(argv[i])
		{
			case "-c":
				if(i+1 <= argc)
				{
					std::cerr << "filename can't be empty" << std::endl;
					return 0;
				}
				config_file = argv[i + 1];
				i++;
				break;
			case "--help":
				//todo write help
				std::cerr << "not wried yet" << std::endl;
				break;
			default:
				std::cerr << "argument " << argv[i] << " is wrong" << std::endl;
		}
	}



}
