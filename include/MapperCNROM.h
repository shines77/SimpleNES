#ifndef SNES_MAPPER_CNROM_H
#define SNES_MAPPER_CNROM_H

#pragma once

#include "Mapper.h"

namespace snes {

class MapperCNROM : public Mapper
{
public:
    MapperCNROM(Cartridge& cart);
    void writePRG (Address addr, Byte value);
    Byte readPRG (Address addr);

    Byte readCHR (Address addr);
    void writeCHR (Address addr, Byte value);

private:
    bool m_oneBank;

    Address m_selectCHR;
};

} // namespace snes

#endif // SNES_MAPPER_CNROM_H
