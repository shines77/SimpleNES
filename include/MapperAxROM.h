#ifndef SNES_MAPPER_AXROM_H
#define SNES_MAPPER_AXROM_H

#pragma once

#include <functional>

#include "Mapper.h"
#include "PictureBus.h"

namespace snes {

class MapperAxROM : public Mapper
{
public:
    MapperAxROM(Cartridge &cart, std::function<void(void)> mirroring_cb);

    void writePRG(Address address, Byte value);
    Byte readPRG(Address address);

    Byte readCHR(Address address);
    void writeCHR(Address address, Byte value);

    NameTableMirroring getNameTableMirroring();

private:
    NameTableMirroring m_mirroring;

    std::function<void(void)> m_mirroringCallback;
    uint32_t m_prgBank;
    std::vector<Byte> m_characterRAM;
};

} // namespace snes

#endif // SNES_MAPPER_AXROM_H
