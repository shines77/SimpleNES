#ifndef SNES_VIRTUALSCREEN_H
#define SNES_VIRTUALSCREEN_H

#pragma once

#include <SFML/Graphics.hpp>

namespace snes {

class VirtualScreen : public sf::Drawable
{
public:
    void create(unsigned int width, unsigned int height, float pixel_size, sf::Color color);
    void setPixel(std::size_t x, std::size_t y, sf::Color color);

private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    sf::Vector2u m_screenSize;
    // virtual pixel size in real pixels
    float m_pixelSize;
    sf::VertexArray m_vertices;
};

} // namespace snes

#endif // SNES_VIRTUALSCREEN_H
