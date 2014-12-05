#include "config.cpp"

class Config
{
    bool file_error(int error_no = 0);
    ///
    public:
    bool load_file(std::fstream* config_file,std::string &config_string);
    ///Lots of GETs


}
