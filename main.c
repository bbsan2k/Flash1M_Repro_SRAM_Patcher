#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#include "Patterns.h"

static const PatchPattern_t FLASH1M_V102_Patches[] = {{{&FLASH1M_V102_MARKER_1, FLASH1M_V102_MARKER_1_LENGTH},
                                                       {&FLASH1M_V102_REPLACE_1, FLASH1M_V102_MARKER_1_LENGTH}},
                                                      {{&FLASH1M_V102_MARKER_2, FLASH1M_V102_MARKER_2_LENGTH},
                                                       {&FLASH1M_V102_REPLACE_2, FLASH1M_V102_MARKER_2_LENGTH}},
                                                      {{&FLASH1M_V102_MARKER_3, FLASH1M_V102_MARKER_3_LENGTH},
                                                       {&FLASH1M_V102_REPLACE_3, FLASH1M_V102_MARKER_3_LENGTH}},
                                                      {{&FLASH1M_V102_MARKER_4, FLASH1M_V102_MARKER_4_LENGTH},
                                                       {&FLASH1M_V102_REPLACE_4, FLASH1M_V102_MARKER_4_LENGTH}},
                                                      {{&FLASH1M_V102_MARKER_5, FLASH1M_V102_MARKER_5_LENGTH},
                                                       {&FLASH1M_V102_REPLACE_5, FLASH1M_V102_MARKER_5_LENGTH}},
                                                      {{&FLASH1M_V102_MARKER_6, FLASH1M_V102_MARKER_6_LENGTH},
                                                       {&FLASH1M_V102_REPLACE_6, FLASH1M_V102_MARKER_6_LENGTH}}};


static const PatchPattern_t FLASH1M_V103_Patches[] = {{{&FLASH1M_V103_MARKER_1, FLASH1M_V103_MARKER_1_LENGTH},
                                                       {&FLASH1M_V103_REPLACE_1, FLASH1M_V103_MARKER_1_LENGTH}},
                                                      {{&FLASH1M_V103_MARKER_2, FLASH1M_V103_MARKER_2_LENGTH},
                                                       {&FLASH1M_V103_REPLACE_2, FLASH1M_V103_MARKER_2_LENGTH}},
                                                      {{&FLASH1M_V103_MARKER_3, FLASH1M_V103_MARKER_3_LENGTH},
                                                       {&FLASH1M_V103_REPLACE_3, FLASH1M_V103_MARKER_3_LENGTH}},
                                                      {{&FLASH1M_V103_MARKER_4, FLASH1M_V103_MARKER_4_LENGTH},
                                                       {&FLASH1M_V103_REPLACE_4, FLASH1M_V103_MARKER_4_LENGTH}},
                                                      {{&FLASH1M_V103_MARKER_5, FLASH1M_V103_MARKER_5_LENGTH},
                                                       {&FLASH1M_V103_REPLACE_5, FLASH1M_V103_MARKER_5_LENGTH}},
                                                      {{&FLASH1M_V103_MARKER_6, FLASH1M_V103_MARKER_6_LENGTH},
                                                       {&FLASH1M_V103_REPLACE_6, FLASH1M_V103_MARKER_6_LENGTH}},
                                                      {{&FLASH1M_V103_MARKER_7, FLASH1M_V103_MARKER_7_LENGTH},
                                                       {&FLASH1M_V103_REPLACE_7, FLASH1M_V103_MARKER_7_LENGTH}}};

static const FlashPattern_t FlashPatterns[] = {{{&IDENT_FLASH1M_V102, IDENT_FLASH1M_V102_LENGTH}, FLASH1M_V102_Patches, FLASH1M_V102_PATCH_COUNT, FLASH1M_V102},
                                               {{&IDENT_FLASH1M_V103, IDENT_FLASH1M_V103_LENGTH}, FLASH1M_V103_Patches, FLASH1M_V103_PATCH_COUNT, FLASH1M_V103}};




static unsigned char* filedata;
static uint32_t filesize;

static void readFile(char** filename)
{
    FILE *fileptr;

    fileptr = fopen(*filename, "rb");
    fseek(fileptr, 0, SEEK_END);
    filesize = ftell(fileptr);
    rewind(fileptr);

    filedata = (unsigned char *)malloc((filesize+1)*sizeof(char));
    fread(filedata, filesize, 1, fileptr);
    fclose(fileptr);
}


static void getPosition(unsigned char const pattern[], uint32_t pattern_size, int32_t* const position)
{
    uint32_t matched_idx = 0U;
    *position = -1;
    for (uint32_t i = 0; i < filesize; i++)
    {
        if (filedata[i] == pattern[matched_idx])
        {
            matched_idx++;
            if (pattern_size == matched_idx)
            {
                *position = (i - pattern_size) + 1;
                break;
            }
        }
        else
        {
            matched_idx = 0U;
        }
    }
}

static void getFlashPattern(FlashType_e* flashtype, FlashPattern_t* pattern)
{
    int32_t position;

    *flashtype = UNKNOWN;

    for (int i = 0; i < (sizeof (FlashPatterns)/ sizeof (FlashPatterns[0])); i++)
    {
        getPosition(FlashPatterns[i].IdentPattern.Pattern, FlashPatterns[i].IdentPattern.PatternLength, &position);
        if (position > 0)
        {
            *pattern = FlashPatterns[i];
            *flashtype = pattern->FlashType;
            break;
        }
    }
}

static void patch(FlashPattern_t* pattern)
{
    for (uint32_t i = 0; i < pattern->PatchCount; i++)
    {
        int32_t position = -1;
        getPosition((pattern->Patches[i].Marker.Pattern), (pattern->Patches[i].Marker.PatternLength), &position);
        if (position > 0)
        {
            memcpy(&filedata[position], (pattern->Patches[i].Replace.Pattern), (pattern->Patches[i].Marker.PatternLength));
        }
    }
}

int main(int argc, char* argv[])
{
    int retCode;
    if (argc < 2)
    {
        printf("Error: Use Filename as argument!\n");
        retCode = 1;
    }
    else if (access(argv[1], F_OK) == -1)
    {
        printf("Error: File does not exist!\n");
        retCode = 1;
    }
    else
    {
        FlashType_e flashtype;
        FlashPattern_t pattern;
        FILE* outFile;
        readFile(&argv[1]);
        getFlashPattern(&flashtype, &pattern);

        switch (flashtype) {
            case FLASH1M_V102:
                printf("FLASH1M_V102 detected. Start patching!\n");
                patch(&pattern);
                outFile = fopen("output.gba", "wb");
                fwrite(filedata, filesize, 1, outFile);
            break;
            case FLASH1M_V103:
                printf("FLASH1M_V103 detected. Start patching!\n");
                patch(&pattern);
                outFile = fopen("output.gba", "wb");
                fwrite(filedata, filesize, 1, outFile);
            break;
            default:
                printf("Error: Flash Type not detected.");
            break;
        }

        retCode = 0;
    }

    return retCode;
}
