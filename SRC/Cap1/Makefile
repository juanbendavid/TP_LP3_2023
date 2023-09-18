reciprocal: Listing1_1.o Listing1_2.o
	g++ $(CFLAGS) -o reciprocal Listing1_1.o Listing1_2.o
Listing1_1.o: Listing1_1.c Listing1_3.hpp
	gcc $(CFLAGS) -c Listing1_1.c
Listing1_2.o: Listing1_2.cpp Listing1_3.hpp
	g++ $(CFLAGS) -c Listing1_2.cpp
clean:
	rm -f *.o reciprocal
