#ifndef EEPROM_H
#define EEPROM_H

#include "patchset.h"

class EEPROM : public PatchSet
{
public:
    EEPROM();
};


class EEPROM_V124 : public PatchSet
{
public:
    EEPROM_V124();
};

class EEPROM_V126 : public PatchSet
{
public:
    EEPROM_V126();
};

#endif // EEPROM_H
