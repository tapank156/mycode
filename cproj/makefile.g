include def.mk

#SOURCES = $(wildcard *.cc)

SOURCES = implement/error.cc implement/first.cc  mainApp.cc

OBJECTS = $(SOURCES:.cc=.o)

all:	depend TAGS $(PROGRAMS)

$(PROGRAMS):	$(OBJECTS)
	$(CXX) $(LDFLAGS) -o $(PROGRAMS) $(OBJECTS)

clean:
	@echo "Deleting all object files ..." 
	rm -f $(OBJECTS)

realclean:	clean
	@echo "Deleting all tags and dependencies ..." 
	rm -f $(PROGRAMS) .depend TAGS

force:
	$(MAKE) realclean
	$(MAKE)

depend:
	rm -f .depend
	$(MAKE) .depend

.depend: $(SOURCES)
	rm -f .depend
	for source in $(SOURCES) ; do \
	 $(CXX) $(CPPFLAGS) -M -MM $$source | tee -a .depend ; \
	done

ifneq ($(wildcard .depend), '')
include .depend
endif

TAGS:	$(SOURCES)
	etags -o TAGS --typedefs-and-c++ $(SOURCES)

.PHONY:	all clean realclean force depend

