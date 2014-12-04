
class Config
{
    ///
    public:
    bool load_file(std::fstream &config_file,std::string &config_string)
{
            int number_of = 0;
            int number_start = 0;
            config_file.open("data.txt",std::ios::in | std::ios::out);
            std::string flag,value;
        config_file.seekg(0); ///Set fstream pointer on the start position.
        while (!config_file.eof()) ///If there is something to read, do it.
        {
        /* How the config file looks like:
            int_flag int_value
            double_flag double_value
            string_flag some text ended with EOL
            long_text_flag some text ended with # dun care if there's any EOL bytes
            list_of_values val0,val1,val2,val3... end with $
        */
            getline(config_file,flag,' ');
            if(flag == "ex_int")
            {
                getline(config_file,value);
                ex_int = atoi(value.c_str());
                ///ex_int_is_set = true;   ///Flag with is telling us if the var was loaded. In the end of the loading it will be checked.
            }else
            if(flag == "ex_double")
            {
                getline(config_file,value);
                ex_double = atof(value.c_str());
                ///ex_double_is_set = true;
            }else
            if(flag == "ex_string")
            {
                getline(config_file,value);
                ex_string = value;
                ///ex_string_is_set = true;
            }//else
            /*if(flag == "ex_list_of_values")
            {
                number_start = config_file.tellg();
                getline(config_file,value);
                number_of = config_file.tellg();
                config_file.seekg(number_start);
                while(config_file.tellg() > number_of)
                {
                    getline(config_file,value,',');
                    ex_list_of_values.push_back(atoi(value.c_str()));
                }
            }*/ ///Todo make this shit working.
        }

}

    ///Lots of GETs
        ///There should be some error catching stuff, todo.

}

