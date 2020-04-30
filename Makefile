main: 0.1v_masyvas_funkcijos.o
	g++ -o main 0.1v_masyvas.cpp 0.1v_masyvas_funkcijos.o
funkcijos:
	g++ -c 0.1v_masyvas_funkcijos.cpp
clean:
	rm main 0.1v_masyvas_funkcijos.o
