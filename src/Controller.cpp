
#include "Controller.h"

#include <vector>
#include <SFML/Window.hpp>

namespace snes {

Controller::Controller() :
    m_keyStates(0),
    m_keyBindings(TotalButtons)
{
#if 0
    m_keyBindings[Buttons::A] = sf::Keyboard::J;
    m_keyBindings[Buttons::B] = sf::Keyboard::K;
    m_keyBindings[Buttons::Select] = sf::Keyboard::RShift;
    m_keyBindings[Buttons::Start] = sf::Keyboard::Return;
    m_keyBindings[Buttons::Up] = sf::Keyboard::W;
    m_keyBindings[Buttons::Down] = sf::Keyboard::S;
    m_keyBindings[Buttons::Left] = sf::Keyboard::A;
    m_keyBindings[Buttons::Right] = sf::Keyboard::D;
#endif
}

void Controller::setKeyBindings(const std::vector<sf::Keyboard::Key>& keys)
{
    m_keyBindings = keys;
}

void Controller::strobe(Byte b)
{
    m_strobe = ((b & 1) != 0);
    if (!m_strobe) {
        m_keyStates = 0;
        int shift = 0;
        for (int button = Buttons::A; button < Buttons::TotalButtons; button++) {
            m_keyStates |= (sf::Keyboard::isKeyPressed(m_keyBindings[static_cast<Buttons>(button)]) << shift);
            ++shift;
        }
    }
}

Byte Controller::read()
{
    Byte ret;
    if (m_strobe) {
        ret = sf::Keyboard::isKeyPressed(m_keyBindings[Buttons::A]);
    } else {
        ret = (m_keyStates & 1);
        m_keyStates >>= 1;
    }
    return (ret | 0x40);
}

} // namespace snes