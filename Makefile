
EXE := motor_test
CPPFILES := motor_test.cpp

SRCDIR = ./src

# set of compiling flags
CXXFLAGS = -I. -Isrc 
LFLAGS = -Lsrc -lmotorPi -lwiringPi

# creating executable file. Libraries need to be on the last.
$(EXE): $(CPPFILES)
	$(CXX) $(CXXFLAGS) -o $@ $< $(LFLAGS)

all: build_lib $(EXE)

build_lib:
	$(MAKE) -C $(SRCDIR)
	$(MAKE) -C $(SRCDIR) clean

clean:
	$(MAKE) -C $(SRCDIR) clean

fclean:
	$(MAKE) -C $(SRCDIR) fclean
