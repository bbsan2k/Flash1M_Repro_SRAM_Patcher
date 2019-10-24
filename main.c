#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#include "Patterns.h"

static const PatchPattern_t FLASH1M_V102_Patches[] = {{{(unsigned char *)FLASH1M_V102_MARKER_1, COUNT_OF(FLASH1M_V102_MARKER_1)},
                                                       {(unsigned char *)FLASH1M_V102_REPLACE_1, COUNT_OF(FLASH1M_V102_REPLACE_1)}},
                                                      {{(unsigned char *)FLASH1M_V102_MARKER_2, COUNT_OF(FLASH1M_V102_MARKER_2)},
                                                       {(unsigned char *)FLASH1M_V102_REPLACE_2, COUNT_OF(FLASH1M_V102_REPLACE_2)}},
                                                      {{(unsigned char *)FLASH1M_V102_MARKER_3, COUNT_OF(FLASH1M_V102_MARKER_3)},
                                                       {(unsigned char *)FLASH1M_V102_REPLACE_3, COUNT_OF(FLASH1M_V102_REPLACE_3)}},
                                                      {{(unsigned char *)FLASH1M_V102_MARKER_4, COUNT_OF(FLASH1M_V102_MARKER_4)},
                                                       {(unsigned char *)FLASH1M_V102_REPLACE_4, COUNT_OF(FLASH1M_V102_REPLACE_4)}},
                                                      {{(unsigned char *)FLASH1M_V102_MARKER_5, COUNT_OF(FLASH1M_V102_MARKER_5)},
                                                       {(unsigned char *)FLASH1M_V102_REPLACE_5, COUNT_OF(FLASH1M_V102_REPLACE_5)}},
                                                      {{(unsigned char *)FLASH1M_V102_MARKER_6, COUNT_OF(FLASH1M_V102_MARKER_6)},
                                                       {(unsigned char *)FLASH1M_V102_REPLACE_6, COUNT_OF(FLASH1M_V102_REPLACE_6)}}};


static const PatchPattern_t FLASH1M_V103_Patches[] = {{{(unsigned char *)FLASH1M_V103_MARKER_1, COUNT_OF(FLASH1M_V103_MARKER_1)},
                                                       {(unsigned char *)FLASH1M_V103_REPLACE_1, COUNT_OF(FLASH1M_V103_REPLACE_1)}},
                                                      {{(unsigned char *)FLASH1M_V103_MARKER_2, COUNT_OF(FLASH1M_V103_MARKER_2)},
                                                       {(unsigned char *)FLASH1M_V103_REPLACE_2, COUNT_OF(FLASH1M_V103_REPLACE_2)}},
                                                      {{(unsigned char *)FLASH1M_V103_MARKER_3, COUNT_OF(FLASH1M_V103_MARKER_3)},
                                                       {(unsigned char *)FLASH1M_V103_REPLACE_3, COUNT_OF(FLASH1M_V103_REPLACE_3)}},
                                                      {{(unsigned char *)FLASH1M_V103_MARKER_4, COUNT_OF(FLASH1M_V103_MARKER_4)},
                                                       {(unsigned char *)FLASH1M_V103_REPLACE_4, COUNT_OF(FLASH1M_V103_REPLACE_4)}},
                                                      {{(unsigned char *)FLASH1M_V103_MARKER_5, COUNT_OF(FLASH1M_V103_MARKER_5)},
                                                       {(unsigned char *)FLASH1M_V103_REPLACE_5, COUNT_OF(FLASH1M_V103_REPLACE_5)}},
                                                      {{(unsigned char *)FLASH1M_V103_MARKER_6, COUNT_OF(FLASH1M_V103_MARKER_6)},
                                                       {(unsigned char *)FLASH1M_V103_REPLACE_6, COUNT_OF(FLASH1M_V103_REPLACE_6)}},
                                                      {{(unsigned char *)FLASH1M_V103_MARKER_7, COUNT_OF(FLASH1M_V103_MARKER_7)},
                                                       {(unsigned char *)FLASH1M_V103_REPLACE_7, COUNT_OF(FLASH1M_V103_REPLACE_7)}}};

static const PatchPattern_t FLASH512_Patches[] = {{{(unsigned char *)FLASH512_MARKER_1, COUNT_OF(FLASH512_MARKER_1)},
                                                   {(unsigned char *)FLASH512_REPLACE_1, COUNT_OF(FLASH512_REPLACE_1)}},
                                                  {{(unsigned char *)FLASH512_MARKER_2, COUNT_OF(FLASH512_MARKER_2)},
                                                   {(unsigned char *)FLASH512_REPLACE_2, COUNT_OF(FLASH512_REPLACE_2)}},
                                                  {{(unsigned char *)FLASH512_MARKER_3, COUNT_OF(FLASH512_MARKER_3)},
                                                   {(unsigned char *)FLASH512_REPLACE_3, COUNT_OF(FLASH512_REPLACE_3)}},
                                                  {{(unsigned char *)FLASH512_MARKER_4, COUNT_OF(FLASH512_MARKER_4)},
                                                   {(unsigned char *)FLASH512_REPLACE_4, COUNT_OF(FLASH512_REPLACE_4)}},
                                                  {{(unsigned char *)FLASH512_MARKER_5, COUNT_OF(FLASH512_MARKER_5)},
                                                   {(unsigned char *)FLASH512_REPLACE_5, COUNT_OF(FLASH512_REPLACE_5)}}};

static const FlashPattern_t FlashPatterns[] = {{{(unsigned char *)IDENT_FLASH1M_V102, IDENT_FLASH1M_V102_LENGTH}, (PatchPattern_t*)FLASH1M_V102_Patches, FLASH1M_V102_PATCH_COUNT, FLASH1M_V102},
                                               {{(unsigned char *)IDENT_FLASH1M_V103, IDENT_FLASH1M_V103_LENGTH}, (PatchPattern_t*)FLASH1M_V103_Patches, FLASH1M_V103_PATCH_COUNT, FLASH1M_V103},
                                               {{(unsigned char *)IDENT_FLASH512, IDENT_FLASH512_LENGTH}, (PatchPattern_t*)FLASH512_Patches, FLASH512_PATCH_COUNT, FLASH512}};




static unsigned char* filedata;
static uint32_t filesize;

static void split_path_file(char** p, char** f, char *pf) {
    char *slash = pf, *next;
    while ((next = strpbrk(slash + 1, "\\/"))) slash = next;
    if (pf != slash) slash++;
    *p = strndup(pf, slash - pf);
    *f = strdup(slash);
}

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


static void getPosition(const unsigned char* const pattern, uint32_t pattern_size, int32_t* const position)
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

static int patch(FlashPattern_t* pattern)
{
    int retVal = 0;
    for (uint32_t i = 0; i < pattern->PatchCount; i++)
    {
        int32_t position = -1;
        getPosition((pattern->Patches[i].Marker.Pattern), (pattern->Patches[i].Marker.PatternLength), &position);
        if (position > 0)
        {
            memcpy(&filedata[position], (pattern->Patches[i].Replace.Pattern), (pattern->Patches[i].Replace.PatternLength));
        }
        else
        {
            printf("ERROR: didn't find pattern #%d\n", i);
            retVal = -1;
        }
    }

    return retVal;
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

        if (UNKNOWN == flashtype)
        {
            printf("Error: Flash Type not detected.");
            retCode = 1;
        }
        else
        {
            char* output_name  = malloc(strlen(argv[1]) + 7);
            char* path;
            char* filename;
            split_path_file(&path, &filename, argv[1]);
            strcpy(output_name, path);

            strcat(output_name, "output-");
            strcat(output_name, filename);
            outFile = fopen(output_name, "wb");
            printf("Start patching %s\n", pattern.IdentPattern.Pattern);

            if (0 == patch(&pattern))
            {
                printf("Patching done. Saved new file to %s\n", output_name);
                fwrite(filedata,filesize,1,outFile);
                fclose(outFile);
            }
            else
            {
                printf("Error - file could not be patched. Has it been patches before?\n");
            }
        }

        retCode = 0;
    }

    return retCode;
}
