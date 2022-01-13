CC = g++
CFLAGS = -Wall -g -std=c++17 -pthread
GTESTLIBFLAGS = -lgtest -lgtest_main
OBJDIR = obj
SRCDIR = src
INC = -Iinc
TARGET = toy_robot
TEST = toy_robot_test

_OBJS = direction.o ostreamreporter.o
OBJS = $(patsubst %,$(OBJDIR)/%,$(_OBJS))

_TESTOBJS = direction_test.o ostreamreporter_test.o
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
	${CC} ${CFLAGS} -o $(TARGET) $(OBJS)

$(TEST): $(OBJS) $(TESTOBJS)
	${CC} ${CFLAGS} -o $(TEST) $(OBJS) $(TESTOBJS) $(GTESTLIBFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp 
	$(CC) $(CFLAGS) -c $(INC) -o $@ $<

.PHONY: clean
clean:
	rm -f $(OBJDIR)/*.o $(TARGET) $(TEST)

.PHONY: setup
setup: libgtest objdir

.PHONY: libgtest
libgtest:
	sudo apt-get install libgtest-dev

.PHONY: objdir
objdir:
	mkdir -p obj
