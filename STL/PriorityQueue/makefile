CXX=g++
CXXFLAGS = -I. -Wall -std=c++17

TARGET=main.o

clean:
	rm -f *.o *.a *.so $(TARGET)

install:
	$(CXX) $(CXXFLAGS) main.cpp PriorityQueue.cpp Entity.cpp -o app_static