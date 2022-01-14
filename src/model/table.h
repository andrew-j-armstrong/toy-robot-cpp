#ifndef TOYROBOT_TABLE_H_
#define TOYROBOT_TABLE_H_

#include "isurface.h"

namespace ToyRobot
{
    // Table encapsulates the table surface in our model, represented as a two dimensional array of locations
    class Table : public ISurface
    {
    public:
        // The constructor of Table can throw an invalid_argument exception if the width and or height aren't positive integers
        Table(int width, int height);
        virtual ~Table();

        bool is_valid_location(int x, int y) const override;

        int width() const { return m_width; }
        int height() const { return m_height; }

    private:
        int m_width;
        int m_height;
    };
}


#endif
