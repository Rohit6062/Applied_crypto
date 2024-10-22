all: run
final: main.o dlp.o diff_hell.o el_gamal.o elliptic_curv_opr.o base.o# header
	g++ main.o dlp.o diff_hell.o el_gamal.o elliptic_curv_opr.o base_ntl.o -lntl -lgmp -pthread -o final

main.o: main.cpp
	g++ -c main.cpp 

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

base.o: base_ntl.cpp 
	g++ -c base_ntl.cpp

clean:
	rm *.o final

run: ./final
	clear && ./final
