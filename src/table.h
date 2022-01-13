#ifndef TOYROBOT_TABLE_H_
#define TOYROBOT_TABLE_H_

#include "isurface.h"

namespace ToyRobot
{
    class Table : public ISurface
    {
    public:
        Table();
        virtual ~Table();

        bool is_valid_location(int x, int y) override;

    private:
        int m_width;
        int m_height;
    };
}


#endif
