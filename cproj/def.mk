#definitions of all veriables
CXX = g++ 

CPPFLAGS = 

WARNCFLAGS = -Wall -W -Wshadow -Wpointer-arith -Wbad-function-cast \
             -Wcast-qual -Wcast-align -Wstrict-prototypes \
             -Wmissing-prototypes -Wmissing-declarations

WARNCXXFLAGS = $(WARNCFLAGS) -Wold-style-cast -Woverloaded-virtual

DBGCXXFLAGS = -g

OPTCXXFLAGS = #-O2

CXXFLAGS = $(WARNCXXFLAGS) $(DBGCXXFLAGS) $(OPTCXXFLAGS)

LDFLAGS = -g

LOADLIBES = -lefence

PROGRAMS = proj

