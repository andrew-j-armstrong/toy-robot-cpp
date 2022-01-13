#include "table.h"

#include <stdexcept>

using namespace ToyRobot;

Table::Table(int width, int height)
: m_width(width)
, m_height(height)
{
    if (m_width <= 0)
        throw std::invalid_argument("width");
    if (m_height <= 0)
        throw std::invalid_argument("height");
}

Table::~Table()
{
}

bool Table::is_valid_location(int x, int y) const
{
    return false;
}
