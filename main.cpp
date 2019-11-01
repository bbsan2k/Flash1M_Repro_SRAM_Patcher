#include "flash1m.h"
#include "flash512.h"
#include "flash.h"
#include "eeprom.h"

#include <vector>
#include <fstream>
#include <iterator>
#include <iostream>
#include <string>
#include <filesystem>
#include <sstream>

#define HEX_BASE ( 16 )

std::vector<PatchSet> patchsets;

static void init()
{
    patchsets.push_back(*(new FLASH512()));

    patchsets.push_back(*(new FLASH1M_V102()));

    patchsets.push_back(*(new FLASH1M_V103()));

    patchsets.push_back(*(new EEPROM()));

    patchsets.push_back(*(new EEPROM_V124()));

    patchsets.push_back(*(new EEPROM_V126));

    patchsets.push_back(*(new FLASH_1()));

    patchsets.push_back(*(new FLASH_2()));

    patchsets.push_back(*(new FLASH_3()));
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

        bool applied = false;

        try {

            for (PatchSet patchset : patchsets)
            {
                std::string applicableName;
                if (patchset.isApplicable(file_buffer, &applicableName))
                {
                    std::cout << "Applying patches for " << applicableName << std::endl;
                    patchset.applyPatches(&file_buffer);
                    applied = true;
                    break;
                }
            }

            if (!applied)
            {
                throw std::string("Error: Could not find applicable patchset.");
            }

            std::filesystem::path path(argv[1]);

            std::stringstream ss;
            ss << path.parent_path().string() << "output_" << path.filename().string();
            std::string outputfilename = ss.str();

            std::cout << "Success! Wrote " << outputfilename << std::endl;

            std::ofstream output(outputfilename, std::ios::out | std::ios::binary);
            output.write((char*) file_buffer.data(), file_buffer.size());
            output.close();
            retCode = 0;

        } catch (std::string& message) {
            std::cout << message << std::endl;
            retCode = 2;
        }

        

    }

    return retCode;
}
