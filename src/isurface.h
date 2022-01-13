#ifndef TOYROBOT_ISURFACE_H_
#define TOYROBOT_ISURFACE_H_

/* ISurface
 * Interface for 2D surfaces to support testing valid locations.
 */
namespace ToyRobot
{
    class ISurface
    {
    public:
        virtual ~ISurface() {}

        virtual bool is_valid_location(int x, int y) = 0;

    protected:
        ISurface() {};
    };
}

#endif
