#ifndef SNES_PICTURE_BUS_H
#define SNES_PICTURE_BUS_H

#pragma once

#include "Cartridge.h"
#include "Mapper.h"

#include <vector>

namespace snes {

class PictureBus
{
public:
    PictureBus();

    Byte read(Address addr);
    void write(Address addr, Byte value);

    bool setMapper(Mapper *mapper);
    Byte readPalette(Byte paletteAddr);
    void updateMirroring();
    void scanlineIRQ();

private:
    // indices where they start in RAM vector
    std::size_t NameTable0, NameTable1, NameTable2, NameTable3;

    std::vector<Byte> m_palette;

    std::vector<Byte> m_RAM;
    Mapper* m_mapper;
};

} // namespace snes

#endif // SNES_PICTURE_BUS_H
