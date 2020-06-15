main: 0.4v_fun.o 0.4v.o
	g++ -o main 0.4v.cpp 0.4v_fun.o
funkcijos:
	g++ -c 0.4v_fun.cpp
clean:
	rm main 0.4v_fun.o d103.txt d104.txt d105.txt d106.txt d107.txt kietekai.txt vargseliai.txt
