#ifndef SNES_MAPPER_SXROM_H
#define SNES_MAPPER_SXROM_H

#pragma once

#include "Mapper.h"

namespace snes {
    class MapperSxROM : public Mapper
    {
        public:
            MapperSxROM(Cartridge& cart, std::function<void(void)> mirroring_cb);
            void writePRG (Address addr, Byte value);
            Byte readPRG (Address addr);

            Byte readCHR (Address addr);
            void writeCHR (Address addr, Byte value);

            NameTableMirroring getNameTableMirroring();
        private:
            void calculatePRGPointers();

            std::function<void(void)> m_mirroringCallback;
            NameTableMirroring m_mirroing;

            bool m_usesCharacterRAM;
            int m_modeCHR;
            int m_modePRG;

            Byte m_tempRegister;
            int m_writeCounter;

            Byte m_regPRG;
            Byte m_regCHR0;
            Byte m_regCHR1;

            const Byte* m_firstBankPRG;
            const Byte* m_secondBankPRG;

            const Byte* m_firstBankCHR;
            const Byte* m_secondBankCHR;

            std::vector<Byte> m_characterRAM;
    };

} // namespace snes

#endif // SNES_MAPPER_SXROM_H
