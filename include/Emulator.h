#ifndef SNES_EMULATOR_H
#define SNES_EMULATOR_H

#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <vector>
#include <string>
#include <memory>
#include <chrono>

#include "CPU.h"
#include "PPU.h"
#include "MainBus.h"
#include "PictureBus.h"
#include "Controller.h"

namespace snes {

using TimePoint = std::chrono::high_resolution_clock::time_point;

static const int NESVideoWidth = ScanlineVisibleDots;
static const int NESVideoHeight = VisibleScanlines;

class Emulator
{
public:
    Emulator();

    void run(std::string rom_path);
    void setVideoWidth(int width);
    void setVideoHeight(int height);
    void setVideoScale(float scale);
    void setKeys(std::vector<sf::Keyboard::Key>& p1, std::vector<sf::Keyboard::Key>& p2);

private:
    void DMA(Byte page);

    MainBus m_bus;
    PictureBus m_pictureBus;
    CPU m_cpu;
    PPU m_ppu;
    Cartridge m_cartridge;
    std::unique_ptr<Mapper> m_mapper;

    Controller m_controller1, m_controller2;

    sf::RenderWindow m_window;
    VirtualScreen m_emulatorScreen;
    float m_screenScale;

    TimePoint m_cycleTimer;

    std::chrono::high_resolution_clock::duration m_elapsedTime;
    std::chrono::nanoseconds m_cpuCycleDuration;
};

} // namespace snes

#endif // SNES_EMULATOR_H
