CC = g++
CFLAGS = -Wall -g -std=c++11
LDFLAGS = -pthread -static
GTESTLDFLAGS = -pthread -lgtest -lgtest_main -lgmock
OBJDIR = obj
SRCDIR = src
BINDIR = bin
TARGET = bin/toy_robot
TEST = bin/toy_robot_test

SRCS := $(shell find $(SRCDIR) -type f \( -iname "*.cpp" ! -iname "*_test.cpp" ! -iname "main.cpp" \))
OBJS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCS))
DEPS = $(OBJS:%.o=%.d)

TESTSRCS := $(shell find $(SRCDIR) -type f -iname "*_test.cpp")
TESTOBJS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(TESTSRCS))
TESTDEPS = $(TESTOBJS:%.o=%.d)

all: build test

-include $(DEPS)
-include $(TESTDEPS)

.PHONY: docker-run
docker-run: docker-build
	docker run -it andrew-j-armstrong/toyrobot

.PHONY: docker-build
docker-build:
	docker build -t andrew-j-armstrong/toyrobot .

.PHONY: build
build: $(TARGET)

.PHONY: run
run: $(TARGET)
	./$(TARGET)

.PHONY: test
test: $(TEST)
	./$(TEST)

$(TARGET): $(OBJS) $(OBJDIR)/main.o
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(TARGET) $(OBJS) $(OBJDIR)/main.o

$(TEST): $(OBJS) $(TESTOBJS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $(TEST) $(OBJS) $(TESTOBJS) $(GTESTLDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -MMD -c -o $@ $<

.PHONY: clean
clean:
	rm -rf $(OBJDIR) $(BINDIR)

.PHONY: ubuntu-setup
ubuntu-setup: ubuntu-libgtest-dev ubuntu-libgmock-dev

.PHONY: ubuntu-libgtest-dev
ubuntu-libgtest-dev:
	apt install -y libgtest-dev

.PHONY: ubuntu-libgmock-dev
ubuntu-libgmock-dev:
	apt install -y libgmock-dev

.PHONY: alpine-setup
alpine-setup: alpine-gtest-dev alpine-gmock

.PHONY: alpine-gtest-dev
alpine-gtest-dev:
	apk add gtest-dev

.PHONY: alpine-gmock
alpine-gmock:
	apk add gmock

