# Flash1M_Repro_SRAM_Patcher
GBA SRAM patcher for some chinese reproduction cartridges.


## Introduction

Int the recent past, many chinese repro or bootleg cartridges will come with 1MBit SRAM, even though only 512KBit can be natively addressed on the GBA.
On original 1MBit cartridges you have FLASH, which means the interaction with the memory will always take additional controlling commands. One of those (defined) controlling commands is bank switching on FLASH.
For normal (512KBit) games, other tools are patching SRAM just fine, as bank switching is not required.

## Why is this tool necessary?

Other tools do not implement bank switching for the current repros for the following reasons:
- Bank switching is not standardized
- Each repro may use its own command for bank switching
- Early emulators handled the bank switching differently

This tool tries to bridge the gap for those cartridges, as it implementsthe bank switching command.
The cartridge types supported are:
- [GE28F128W30](https://flashcartdb.com/index.php/GE28F128W30)
- [36L0R-DRV](https://flashcartdb.com/index.php/M36L0R706_36LOR-DRV) / [36L0R-DRV](https://flashcartdb.com/index.php/M36L0R705_36L0R)

...and probably more that also use 0x9000000 address for bank switching

