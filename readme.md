# Toy Robot

*Andrew Armstrong 2022*
This is a Toy Robot built according to the Iress specifications.

## Specifications

### Description

The application is a simulation of a toy robot moving on a square table top, of dimensions 5 units x 5 units. There are no other obstructions on the table surface. The robot is free to roam around the surface of the table, but must be prevented from falling to destruction. Any movement that would result in the robot falling from the table must be prevented, however further valid movement commands must still be allowed.

### Requirements

Create a console application that can read in commands of the following form -
 `PLACE X,Y,F`
 `MOVE`
 `LEFT`
 `RIGHT`
 `REPORT`
PLACE will put the toy robot on the table in position X,Y and facing NORTH, SOUTH, EAST or WEST. The origin (0,0) can be considered to be the SOUTH WEST most corner. It is required that the first command to the robot is a PLACE command, after that, any sequence of commands may be issued, in any order, including another PLACE command. The application should discard all commands in the sequence until a valid PLACE command has been executed.
MOVE will move the toy robot one unit forward in the direction it is currently facing.
LEFT and RIGHT will rotate the robot 90 degrees in the specified direction without changing the position of the robot.
REPORT will announce the X, Y and F of the robot. This can be in any form, but standard output is sufficient.
A robot that is not on the table can choose to ignore the MOVE, LEFT, RIGHT and REPORT commands.
Input can be from a file, or from standard input, as the developer chooses.
Provide test data to exercise the application.
It is not required to provide any graphical output showing the movement of the toy robot.
The application should handle error states appropriately and be robust to user input.

### Constraints

The toy robot must not fall off the table during movement. This also includes the initial placement of the toy robot. Any move that would cause the robot to fall must be ignored.

## Solution

### Implementation

This solution is built using C++11. Linux and Docker builds are supported.

### Design

This Toy Robot solution was designed to decouple components as much as possible in order to facilitate isolated unit testing. The primary domain objects were identified as the Table (a surface of fixed width and height) and the Robot (an entity that can be placed on a surface and move, turn or report its location). The Robot reports its location through a reporting interface, which has been implemented to report the location to standard output. Instructions are parsed with an independent parser, utilising the command pattern (and a factory for those commands) to isolate parsing the commands from executing them. A simulation function takes the output from the parser and executes the resulting commands.
Note that an `EXIT` command was added beyond the specifications to facilitate terminating the simulation without aborting (via Ctrl-C).

### Local Development

#### Local Dependencies

To build locally you will need:

* Make
* GCC
* GTest
* GMock

Note that GTest and GMock can be installed for Ubuntu distributions using Make with:
`sudo make ubuntu-setup`

#### Local Build

The project can be built through Make with:
`make build`

This creates the executable `bin/toy_robot`.

#### Local Test

Unit tests are provided through a Google Test application. These can be built & run using Make with:
`make test`

Integration / end-to-end tests are also provided through a Google Test application, but will execute the Toy Robot app as a forked process. These can be built & run using Make with:
`make integration-test`

#### Local Run

The Toy Robot application can be executed through:
`./bin/toy_robot`

This will accept commands provided via standard input. You can also provide commands via a file by passing the filename as the first argument to the application:
`./bin/toy_robot integration_tests/examples.txt`

### Docker Development

#### Docker Dependencies

To build with Docker you will need:

* Docker
* (Optional) Make

#### Docker Build

Local Docker builds can be performed either with Make:
`make docker-build`

Or with Docker directly:
`docker build -t andrew-j-armstrong/toyrobot .`

Note that unit and integration testing is automatically performed as part of the Docker build.

#### Docker Run

Docker builds of the Toy Robot can be performed either with Make:
`make docker-run`

Or with Docker directly:
`docker run -it --rm andrew-j-armstrong/toyrobot`

This will accept commands provided via standard input.
