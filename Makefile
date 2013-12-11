CXXFLAGS = -g -Wall -fmessage-length=0

OBJS =		WikipediaDumpConvertor.o

LIBS =

TARGET =	WikipediaDumpConvertor

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
