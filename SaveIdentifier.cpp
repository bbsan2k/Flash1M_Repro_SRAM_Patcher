#include <filesystem>
#include <vector>
#include <fstream>
#include <iterator>
#include <iostream>
#include <string>
#include <filesystem>
#include <sstream>


std::vector<std::string> types;

static void init()
{
    types = std::vector<std::string> ({"FLASH1M_V102",
                                       "FLASH1M_V103",
                                       "FLASH512",
                                       "EEPROM_V111",
                                       "EEPROM_V120",
                                       "EEPROM_V121",
                                       "EEPROM_V122",
                                       "EEPROM_V124",
                                       "EEPROM_V126",
                                       "FLASH_V120",
                                       "FLASH_V121",
                                       "FLASH_V123",
                                       "FLASH_V124",
                                       "FLASH_V125",
                                       "FLASH_V126",
                                       "SRAM"});


}

int main(int argc, char* argv[])
{
    init();
    int retCode;
    if (argc < 2)
    {
        std::cout << "Error: Use Filename as argument!" << std::endl;
        retCode = 1;
    }
    else if (!std::filesystem::exists(argv[1]))
    {
        std::cout << "Error: File does not exist!" << std::endl;
        retCode = 1;
    }
    else
    {
        std::ifstream input( argv[1], std::ios::binary );

        std::vector<unsigned char> file_buffer(std::istreambuf_iterator<char>(input), {});

        std::string type = "None";
        for (std::string& name : types)
        {
            std::vector< unsigned char > pattern;
            for(unsigned char character : name)
            {
                pattern.push_back(character);
            }

            auto it = std::search(std::begin(file_buffer), std::end(file_buffer), std::begin(pattern), std::end(pattern));

            if (std::end(file_buffer) != it)
            {
                type = name;
                break;
            }
        }
        std::cout << type << std::endl;


    }

    return retCode;
}
