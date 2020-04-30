main: 0.1v_vektorius_funkcijos.o
	g++ -o main 0.1v_vektorius.cpp 0.1v_vektorius_funkcijos.o
funkcijos:
	g++ -c 0.1v_vektorius_funkcijos.cpp
clean:
	rm main 0.1v_vektorius_funkcijos.o
