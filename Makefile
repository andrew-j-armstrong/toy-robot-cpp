CC = g++
CFLAGS = -Wall -g -std=c++11 -pthread
GTESTLIBFLAGS = -lgtest -lgtest_main -lgmock
OBJDIR = obj
SRCDIR = src
BINDIR = bin
INC = -Iinc
TARGET = bin/toy_robot
TEST = bin/toy_robot_test

SRCS := $(shell find $(SRCDIR) -type f \( -iname "*.cpp" ! -iname "*_test.cpp" \))
OBJS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCS))
DEPS = $(OBJS:%.o=%.d)
-include $(DEPS)

TESTSRCS := $(shell find $(SRCDIR) -type f -iname "*_test.cpp")
TESTOBJS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(TESTSRCS))
TESTDEPS = $(TESTOBJS:%.o=%.d)
-include $(TESTDEPS)

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
	@mkdir -p $(@D)
	${CC} ${CFLAGS} -o $(TARGET) $(OBJS)

$(TEST): $(OBJS) $(TESTOBJS)
	@mkdir -p $(@D)
	${CC} ${CFLAGS} -o $(TEST) $(OBJS) $(TESTOBJS) $(GTESTLIBFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -MMD -c $(INC) -o $@ $<

.PHONY: clean
clean:
	rm -rf $(OBJDIR) $(BINDIR)

.PHONY: setup
setup: libgtest libgmock-dev

.PHONY: libgtest
libgtest:
	sudo apt-get install libgtest-dev

.PHONY: libgmock-dev
libgmock-dev:
	sudo apt-get install libgmock-dev

