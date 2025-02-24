#ifndef SNES_MAPPER_UXROM_H
#define SNES_MAPPER_UXROM_H

#pragma once

#include "Mapper.h"

namespace snes {

class MapperUxROM : public Mapper
{
public:
    MapperUxROM(Cartridge& cart);

    void writePRG (Address addr, Byte value);
    Byte readPRG (Address addr);

    Byte readCHR (Address addr);
    void writeCHR (Address addr, Byte value);

private:
    bool m_usesCharacterRAM;

    const Byte* m_lastBankPtr;
    Address m_selectPRG;

    std::vector<Byte> m_characterRAM;
};

} // namespace snes

#endif // SNES_MAPPER_UXROM_H
