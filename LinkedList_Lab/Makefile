CXX=g++
CXXFLAGS=-std=c++17 -Wall -Wextra
FILES= ll.cc main.cc ll.h
OFILES=main.o ll.o
default: $(OFILES)
	$(CXX) $(CXXFLAGS) $(FILES) -o link

main.o: main.cc ll.h
	$(CXX) $(CXXFLAGS) -c main.cc

ll.o: ll.cc ll.h
	$(CXX) $(CXXFLAGS) -c ll.cc

clean:
	-rm -f link *.o
