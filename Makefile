CC = g++
CFLAGS = -Wall -g -std=c++17 -pthread
GTESTLIBFLAGS = -lgtest -lgtest_main -lgmock
OBJDIR = obj
SRCDIR = src
INC = -Iinc
TARGET = bin/toy_robot
TEST = bin/toy_robot_test

_OBJS = direction.o ostreamreporter.o robot.o table.o movecommand.o
OBJS = $(patsubst %,$(OBJDIR)/%,$(_OBJS))

DEPS = $(OBJS:%.o=%.d)

_TESTOBJS = direction_test.o ostreamreporter_test.o robot_test.o table_test.o movecommand_test.o
TESTOBJS = $(patsubst %,$(OBJDIR)/%,$(_TESTOBJS))

all: test build

.PHONY: build
build: $(TARGET)

.PHONY: run
run: $(TARGET)
	./$(TARGET)

.PHONY: test
test: $(TEST)
	./$(TEST)

$(TARGET): $(OBJS)
	mkdir -p bin
	${CC} ${CFLAGS} -o $(TARGET) $(OBJS)

$(TEST): $(OBJS) $(TESTOBJS)
	mkdir -p bin
	${CC} ${CFLAGS} -o $(TEST) $(OBJS) $(TESTOBJS) $(GTESTLIBFLAGS)

# Include all .d files
-include $(DEPS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp 
	$(CC) $(CFLAGS) -MMD -c $(INC) -o $@ $<

.PHONY: clean
clean:
	rm -f $(OBJDIR)/*.o $(TARGET) $(TEST)

.PHONY: setup
setup: libgtest libgmock-dev objdir

.PHONY: libgtest
libgtest:
	sudo apt-get install libgtest-dev

.PHONY: libgmock-dev
libgmock-dev:
	sudo apt-get install libgmock-dev

.PHONY: objdir
objdir:
	mkdir -p obj
