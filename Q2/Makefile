CXX = g++
CXXFLAGS = -std=c++17 -Wall -c
LXXFLAGS = -std=c++17
OBJECTS = q2.o libArr.o libVec.o
TARGET = q2


$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) $(OBJECTS) -o $(TARGET)
q2.o: q2.cpp
	$(CXX) $(CXXFLAGS) q2.cpp
libArr.o: libArr.cpp libArr.h
	$(CXX) $(CXXFLAGS) libArr.cpp
libVec.o: libVec.cpp libVec.h
	$(CXX) $(CXXFLAGS) libVec.cpp
clean:
	rm -f $(TARGET) $(OBJECTS)
