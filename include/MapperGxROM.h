#ifndef SNES_MAPPER_GXROM_H
#define SNES_MAPPER_GXROM_H

#pragma once

#include"Mapper.h"

#include <vector>
#include <functional>

namespace snes {

class MapperGxROM : public Mapper
{
public:
    MapperGxROM(Cartridge &cart, std::function<void(void)> mirroring_cb);

    NameTableMirroring getNameTableMirroring();
    void writePRG(Address address, Byte value);
    Byte readPRG(Address address);

    Byte readCHR(Address address);
    void writeCHR(Address address, Byte value);
    Byte prgbank;
    Byte chrbank;

private:
    NameTableMirroring m_mirroring;

    std::vector<Byte> m_characterRAM;
    std::function<void(void)> m_mirroringCallback;
};

} // namespace snes

#endif // SNES_MAPPER_GXROM_H
