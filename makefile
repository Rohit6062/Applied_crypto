all: run
final: vish.o dlp.o diff_hell.o el_gamal.o elliptic_curv_opr.o # header
	g++ vish.o dlp.o diff_hell.o el_gamal.o elliptic_curv_opr.o -lntl -lgmp -pthread -o final

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

elliptic_curv_opr.o: elliptic_curv_opr.cpp 
	g++ -c elliptic_curv_opr.cpp  

clean:
	rm *.o final

run: ./final
	clear && ./final
