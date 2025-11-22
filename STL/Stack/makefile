#compiler and flags
CXX = g++
CXXFLAGS = -I. -Wall -std=c++17

clean:
	rm -f *.o *.a $(TARGET)

$(TARGET): main.o

install: $(TARGET)
	$(CXX) $(CXXFLAGS) main.cpp StackClass.cpp -o app_static


