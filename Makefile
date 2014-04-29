CXX := g++
CXXFLAGS := -Wall -Wextra -pedantic
LD := g++
LDFLAGS := -O3
OBJS := $(patsubst %.cpp, %.o, $(wildcard *.cpp))
BINS := test

.PHONY : all
all : CXXFLAGS += -O3
all : $(BINS)

.PHONY : debug
debug : CXXFLAGS += -g -pg
debug : LDFLAGS += -pg
debug : $(BINS)

$(BINS) : $(OBJS)
	$(LD) $(LDFLAGS) $(OBJS) -o $@

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY : clean
clean :
	@rm -f $(OBJS) *.o test
