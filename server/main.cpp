#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
    std::string config_file_name;

	for(int i = 0; i < argc; ++i)
	{
		if(argv[i] == "-c")
		{
			if(i+1 >= argc)
			{
				std::cerr << "filename can't be empty" << std::endl;
				return 0;
			}
			config_file_name = std::string(argv[i + 1]);
			i++;
		}
		else if(argv[i] == "--help")
		{
			//todo write help
			std::cerr << "not writed yet" << std::endl;
		}
		else
		{
			std::cerr << "argument " << argv[i] << " is wrong" << std::endl;
		}
	}
    ///Opening and loading config.
    ///Reading opened file...
    Config config;
    config.load_file(config_file);

    Game game;
    while(game.is_on())
    {

    }



}
