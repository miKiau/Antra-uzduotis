main: 0.2v_fun.o
	g++ -o main 0.2v.cpp 0.2v_fun.o
funkcijos:
	g++ -c 0.2v_fun.cpp
clean:
	rm main 0.2v_fun.o
