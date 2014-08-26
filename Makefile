CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		Taichi_test.o

LIBS =

TARGET =	Taichi.exe

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
