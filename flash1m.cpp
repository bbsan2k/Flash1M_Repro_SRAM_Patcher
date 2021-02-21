#include "flash1m.h"


FLASH1M_V102::FLASH1M_V102() : PatchSet("FLASH1M_V102")
{

    addPatch(std::vector<unsigned char> {(0x05), (0x4b), (0xaa), (0x21), (0x19), (0x70), (0x05), (0x4a),
                                         (0x55), (0x21), (0x11), (0x70), (0xb0), (0x21), (0x19), (0x70),
                                         (0xe0), (0x21), (0x09), (0x05), (0x08), (0x70), (0x70), (0x47)},
             std::vector<unsigned char> {(0x05), (0x4B), (0x80), (0x21), (0x09), (0x02), (0x09), (0x22),
                                         (0x12), (0x06), (0x9F), (0x44), (0x90), (0x21), (0x09), (0x05),
                                         (0x00), (0x00), (0x00), (0x00), (0x08), (0x70), (0x70), (0x47)});
    addPatch(std::vector<unsigned char> {(0x55), (0x55), (0x00), (0x0e), (0xaa), (0x2a), (0x00), (0x0e),
                                         (0x30), (0xb5), (0x91), (0xb0), (0x68), (0x46), (0x00), (0xf0),
                                         (0xf3), (0xf8), (0x6d), (0x46), (0x01), (0x35)},
             std::vector<unsigned char> {(0xFE), (0xFF), (0xFF), (0x01), (0x00), (0x00), (0x00), (0x00),
                                         (0x30), (0xB5), (0x91), (0xB0), (0x68), (0x46), (0x00), (0xF0),
                                         (0xF3), (0xF8), (0x6D), (0x46), (0x01), (0x35)});
    addPatch(std::vector<unsigned char> {(0x06), (0x4A), (0xAA), (0x20), (0x10), (0x70), (0x05), (0x49),
                                         (0x55), (0x20), (0x08), (0x70), (0x90), (0x20), (0x10), (0x70),
                                         (0x10), (0xA9), (0x03), (0x4A), (0x10), (0x1C), (0x08), (0xE0),
                                         (0x00), (0x00), (0x55), (0x55), (0x00), (0x0E), (0xAA), (0x2A),
                                         (0x00), (0x0E), (0x20), (0x4E), (0x00), (0x00), (0x08), (0x88),
                                         (0x01), (0x38), (0x08), (0x80), (0x08), (0x88), (0x00), (0x28),
                                         (0xF9), (0xD1), (0x0C), (0x48)},
             std::vector<unsigned char> {(0x06), (0x4A), (0xAA), (0x20), (0x00), (0x00), (0x05), (0x49),
                                         (0x55), (0x20), (0x00), (0x00), (0x90), (0x20), (0x00), (0x00),
                                         (0x10), (0xA9), (0x03), (0x4A), (0x10), (0x1C), (0x08), (0xE0),
                                         (0x00), (0x00), (0x55), (0x55), (0x00), (0x0E), (0xAA), (0x2A),
                                         (0x00), (0x0E), (0x20), (0x4E), (0x00), (0x00), (0x08), (0x88),
                                         (0x01), (0x38), (0x08), (0x80), (0x08), (0x88), (0x00), (0x28),
                                         (0xF9), (0xD1), (0x0C), (0x48), (0x13), (0x20), (0x13), (0x20),
                                         (0x00), (0x06), (0x04), (0x0C), (0xE0), (0x20), (0x00), (0x05),
                                         (0x62), (0x20), (0x62), (0x20), (0x00), (0x06), (0x00), (0x0E),
                                         (0x04), (0x43), (0x07), (0x49), (0xAA), (0x20), (0x00), (0x00),
                                         (0x07), (0x4A), (0x55), (0x20), (0x00), (0x00), (0xF0), (0x20),
                                         (0x00), (0x00), (0x00), (0x00)});
    addPatch(std::vector<unsigned char> {(0x14), (0x49), (0xAA), (0x24), (0x0C), (0x70), (0x13), (0x4B),
                                         (0x55), (0x22), (0x1A), (0x70), (0x80), (0x20), (0x08), (0x70),
                                         (0x0C), (0x70), (0x1A), (0x70), (0x10), (0x20), (0x08), (0x70)},
             std::vector<unsigned char> {(0x0E), (0x21), (0x09), (0x06), (0xFF), (0x24), (0x80), (0x22),
                                         (0x13), (0x4B), (0x52), (0x02), (0x01), (0x3A), (0x8C), (0x54),
                                         (0xFC), (0xD1), (0x00), (0x00), (0x00), (0x00), (0x00), (0x00)});
    addPatch(std::vector<unsigned char> {(0x13), (0x49), (0xAA), (0x25), (0x0D), (0x70), (0x13), (0x4B),
                                         (0x55), (0x22), (0x1A), (0x70), (0x80), (0x20), (0x08), (0x70),
                                         (0x0D), (0x70), (0x1A), (0x70), (0x30), (0x20), (0x20), (0x70)},
             std::vector<unsigned char> {(0x13), (0x49), (0xFF), (0x25), (0x08), (0x22), (0x00), (0x00),
                                         (0x52), (0x02), (0x01), (0x3A), (0xA5), (0x54), (0xFC), (0xD1),
                                         (0x00), (0x00), (0x00), (0x00), (0x00), (0x00), (0x00), (0x00)});
    addPatch(std::vector<unsigned char> {(0x0A), (0x4C), (0xAA), (0x22), (0x22), (0x70), (0x09), (0x4B),
                                         (0x55), (0x22), (0x1A), (0x70), (0xA0), (0x22), (0x22), (0x70),
                                         (0x02), (0x78), (0x0A), (0x70)},
             std::vector<unsigned char> {(0x0A), (0x4C), (0xAA), (0x22), (0x00), (0x00), (0x09), (0x4B),
                                         (0x55), (0x22), (0x00), (0x00), (0xA0), (0x22), (0x00), (0x00),
                                         (0x02), (0x78), (0x0A), (0x70)});
}


FLASH1M_V103::FLASH1M_V103() : PatchSet("FLASH1M_V103")
{

    addPatch(std::vector<unsigned char> {(0x05), (0x4b), (0xaa), (0x21), (0x19), (0x70), (0x05), (0x4a),
                                         (0x55), (0x21), (0x11), (0x70), (0xb0), (0x21), (0x19), (0x70),
                                         (0xe0), (0x21), (0x09), (0x05), (0x08), (0x70), (0x70), (0x47)},
             std::vector<unsigned char> {(0x05), (0x4B), (0x80), (0x21), (0x09), (0x02), (0x09), (0x22),
                                         (0x12), (0x06), (0x9F), (0x44), (0x90), (0x21), (0x09), (0x05),
                                         (0x00), (0x00), (0x00), (0x00), (0x08), (0x70), (0x70), (0x47)});
    addPatch(std::vector<unsigned char> {(0x55), (0x55), (0x00), (0x0e), (0xaa), (0x2a), (0x00), (0x0e),
                                         (0x30), (0xb5), (0x91), (0xb0), (0x68), (0x46), (0x00), (0xf0),
                                         (0xf3), (0xf8), (0x6d), (0x46), (0x01), (0x35)},
             std::vector<unsigned char> {(0xFE), (0xFF), (0xFF), (0x01), (0x00), (0x00), (0x00), (0x00),
                                         (0x30), (0xB5), (0x91), (0xB0), (0x68), (0x46), (0x00), (0xF0),
                                         (0xF3), (0xF8), (0x6D), (0x46), (0x01), (0x35)});
    addPatch(std::vector<unsigned char> {(0x06), (0x4A), (0xAA), (0x20), (0x10), (0x70), (0x05), (0x49),
                                         (0x55), (0x20), (0x08), (0x70), (0x90), (0x20), (0x10), (0x70),
                                         (0x10), (0xA9), (0x03), (0x4A), (0x10), (0x1C), (0x08), (0xE0),
                                         (0x00), (0x00), (0x55), (0x55), (0x00), (0x0E), (0xAA), (0x2A),
                                         (0x00), (0x0E), (0x20), (0x4E), (0x00), (0x00), (0x08), (0x88),
                                         (0x01), (0x38), (0x08), (0x80), (0x08), (0x88), (0x00), (0x28),
                                         (0xF9), (0xD1), (0x0C), (0x48)},
             std::vector<unsigned char> {(0x06), (0x4A), (0xAA), (0x20), (0x00), (0x00), (0x05), (0x49),
                                         (0x55), (0x20), (0x00), (0x00), (0x90), (0x20), (0x00), (0x00),
                                         (0x10), (0xA9), (0x03), (0x4A), (0x10), (0x1C), (0x08), (0xE0),
                                         (0x00), (0x00), (0x55), (0x55), (0x00), (0x0E), (0xAA), (0x2A),
                                         (0x00), (0x0E), (0x20), (0x4E), (0x00), (0x00), (0x08), (0x88),
                                         (0x01), (0x38), (0x08), (0x80), (0x08), (0x88), (0x00), (0x28),
                                         (0xF9), (0xD1), (0x0C), (0x48), (0x13), (0x20), (0x13), (0x20),
                                         (0x00), (0x06), (0x04), (0x0C), (0xE0), (0x20), (0x00), (0x05),
                                         (0x62), (0x20), (0x62), (0x20), (0x00), (0x06), (0x00), (0x0E),
                                         (0x04), (0x43), (0x07), (0x49), (0xAA), (0x20), (0x00), (0x00),
                                         (0x07), (0x4A), (0x55), (0x20), (0x00), (0x00), (0xF0), (0x20),
                                         (0x00), (0x00), (0x00), (0x00)});
    addPatch(std::vector<unsigned char> {(0x14), (0x49), (0xAA), (0x24), (0x0C), (0x70), (0x13), (0x4B),
                                         (0x55), (0x22), (0x1A), (0x70), (0x80), (0x20), (0x08), (0x70),
                                         (0x0C), (0x70), (0x1A), (0x70), (0x10), (0x20), (0x08), (0x70)},
             std::vector<unsigned char> {(0x0E), (0x21), (0x09), (0x06), (0xFF), (0x24), (0x80), (0x22),
                                         (0x13), (0x4B), (0x52), (0x02), (0x01), (0x3A), (0x8C), (0x54),
                                         (0xFC), (0xD1), (0x00), (0x00), (0x00), (0x00), (0x00), (0x00)});
    addPatch(std::vector<unsigned char> {(0x14), (0x49), (0xAA), (0x25), (0x0D), (0x70), (0x14), (0x4B),
                                         (0x55), (0x22), (0x1A), (0x70), (0x80), (0x20), (0x08), (0x70),
                                         (0x0D), (0x70), (0x1A), (0x70), (0x30), (0x20), (0x20), (0x70)},
             std::vector<unsigned char> {(0x14), (0x49), (0xFF), (0x25), (0x08), (0x22), (0x00), (0x00),
                                         (0x52), (0x02), (0x01), (0x3A), (0xA5), (0x54), (0xFC), (0xD1),
                                         (0x00), (0x00), (0x00), (0x00), (0x00), (0x00), (0x00), (0x00)});
    addPatch(std::vector<unsigned char> {(0x0C), (0x4A), (0xAA), (0x20), (0x10), (0x70), (0x0B), (0x49),
                                         (0x55), (0x20), (0x08), (0x70), (0xA0), (0x20), (0x10), (0x70),
                                         (0x27), (0x70), (0x09), (0x48)},
             std::vector<unsigned char> {(0x0C), (0x4A), (0xAA), (0x20), (0x00), (0x00), (0x0B), (0x49),
                                         (0x55), (0x20), (0x00), (0x00), (0xA0), (0x20), (0x00), (0x00),
                                         (0x27), (0x70), (0x09), (0x48)});
    addPatch(std::vector<unsigned char> {(0x0A), (0x4C), (0xAA), (0x22), (0x22), (0x70), (0x09), (0x4B),
                                         (0x55), (0x22), (0x1A), (0x70), (0xA0), (0x22), (0x22), (0x70),
                                         (0x02), (0x78), (0x0A), (0x70)},
             std::vector<unsigned char> {(0x0A), (0x4C), (0xAA), (0x22), (0x00), (0x00), (0x09), (0x4B),
                                         (0x55), (0x22), (0x00), (0x00), (0xA0), (0x22), (0x00), (0x00),
                                         (0x02), (0x78), (0x0A), (0x70)});
};