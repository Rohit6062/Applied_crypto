all: run
final: vish.o dlp.o diff_hell.o el_gamal.o
	g++ vish.o dlp.o diff_hell.o el_gamal.o -lntl -lgmp -pthread -o final

vish.o: vish.cpp
	g++ -c vish.cpp -o vish.o

dlp.o: dlp.cpp
	g++ -c dlp.cpp -o dlp.o

diff_hell.o: diff_hell.cpp
	g++ -c diff_hell.cpp -o diff_hell.o

el_gamal.o: el_gamal.cpp
	g++ -c el_gamal.cpp -o el_gamal.o

header: crypto.h 
	g++ crypto.h

clear:
	rm *.o final

run: ./final
	./final
