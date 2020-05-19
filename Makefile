main: 0.3v_fun.o
	g++ -o main 0.3v.cpp 0.3v_fun.o
funkcijos:
	g++ -c 0.3v_fun.cpp
clean:
	rm main 0.3v_fun.o
