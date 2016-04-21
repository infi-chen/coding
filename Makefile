CXXFLAGS = -O2 -g -fmessage-length=0

OBJS =	main.o  UnitTest.o

LIBS =

TARGET = hello

$(TARGET):	$(OBJS)
	$(info build $(OBJS))
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	$(info clean...)
	rm -fv $(OBJS) $(TARGET)
