 
TARGET  = XXXX
TAGALIB	= libXServer.a

CC=gcc
 
CFLAGS_WARN = -Wall
 
DEFINE =
INCLUDE = -I.
 
SOURCES = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp,%.o,$(SOURCES))
LINK = 
LIBPATH = -L.

alib:$(OBJS)
	ar r $(TAGALIB) $(OBJS) 
	@rm $(OBJS)
 
#All:$(OBJS)
#	$(CC) -o $(TARGET) $(OBJS)	
 
%.o:%.cpp
	$(CC) -c $(CFLAGS_WARN) $(DEFINE) $(INCLUDE) $< -o $@	
	
clean:	
	rm -f $(OBJS)
	@rm -f $(TAGALIB)
	
	