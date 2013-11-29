#Marisa Reddy
#mpr2zp
#23 November 2013
#Makefile

CXX = clang++
CXXFLAGS = -Wall -O2 -g
OFILES  = HuffmanNode.o Heap.o HuffmanEnc.o
.SUFFIXES: .o .c


main:   $(OFILES)
	$(CXX) $(CXXFLAGS) $(OFILES)

clean:
	/bin/rm -f *.o *~

