CXX = g++
CXXFLAGS = -I. -Wall -std=c++17

clean:
	rm -f *.o *.a  *.exe $(TARGET)

TARGET = main.o

install:
	$(CXX) $(CXXFLAGS) main.cpp QueueClass.cpp -o app_static