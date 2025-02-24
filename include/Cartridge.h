#ifndef NES_CARTRIDGE_H
#define NES_CARTRIDGE_H

#pragma once

#include <vector>
#include <string>
#include <cstdint>

namespace snes {

using Byte = std::uint8_t;
using Address = std::uint16_t;

class Cartridge
{
public:
    Cartridge();
    bool loadFromFile(std::string path);
    const std::vector<Byte>& getROM();
    const std::vector<Byte>& getVROM();
    Byte getMapper();
    Byte getNameTableMirroring();
    bool hasExtendedRAM();

private:
    std::vector<Byte> m_PRG_ROM;
    std::vector<Byte> m_CHR_ROM;
    Byte m_nameTableMirroring;
    Byte m_mapperNumber;
    bool m_extendedRAM;
    bool m_chrRAM;
};

} // namespace snes

#endif // NES_CARTRIDGE_H
