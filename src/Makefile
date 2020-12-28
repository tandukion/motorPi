# target static library
TARGET := libmotorPi.a

# set of compiling flags
CXXFLAGS = -I.

# wildcard for all .cpp file
CPP_FILES := $(wildcard *.cpp)

# target object files
OBJECTS := $(CPP_FILES:.cpp=.o)
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# make commands
$(TARGET): $(OBJECTS)
	ar -crs $@ $^
	
all: $(TARGET)

clean: 
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(OBJECTS)
	rm -f $(TARGET)

