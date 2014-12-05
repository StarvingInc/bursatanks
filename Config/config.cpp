
class Config
{
    bool file_error(int error_no = 0)
    {

    }
    public:
    bool load_file(std::fstream &config_file,std::string &config_string)
{
            config_file.open("data.txt",std::ios::in | std::ios::out);
            if(!config_file.is_open())
            {
                file_error(1) ///Error no. 1 - File not found or permission denied.
                return false;
            }
            std::string flag,value,buf; ///Using to keep fragments of file.
            bool ex_int_is_set = false,ex_double_is_set = false,ex_string_is_set = false;
        config_file.seekg(0); ///Set fstream pointer on the start position.
        while (!config_file.eof()) ///If there is something to read, do it.
        {
        /* How the config file looks like:
            int_flag int_value
            double_flag double_value
            string_flag some text ended with EOL
            long_text_flag some text ended with # dun care if there's any EOL bytes
            list_of_values val0,val1,val2,val3... end with coma ','
        */
            getline(config_file,flag,' ');
            if(flag == "ex_int")
            {
                getline(config_file,value);
                ex_int = atoi(value.c_str());
                ex_int_is_set = true;   ///Flag with is telling us if the var was loaded. In the end of the loading it will be checked.
            }else
            if(flag == "ex_double")
            {
                getline(config_file,value);
                ex_double = atof(value.c_str());
                ex_double_is_set = true;
            }else
            if(flag == "ex_string")
            {
                getline(config_file,value);
                ex_string = value;
                ex_string_is_set = true;
            }else
            if(flag == "ex_list_of_values")
            {
                getline(config_file,buf);
                for(int i = 0;i < buf.size();++ i)
                {
                    if (buf[i] == ',')
                    {
                        ex_list_of_values.push_back(atoi(value.c_str()));
                        value = "";
                    }else
                        {
                            value +=buf[i];
                        }
                }
            }else ///If function load flag that doesn't mean anything
            {
                file_error(2) ///Warning, unknown flag.
            }
        }
        if(ex_int&&ex_string_is_set&&ex_double_is_set) return 0;
        else
        {
            file_error(3) ///Not all var has been loaded.
            return 0;
        }
}

    ///Lots of GETs
        ///There should be some error catching stuff, todo.

}
