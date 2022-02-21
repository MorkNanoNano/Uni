all: compila

compila: main.cpp funzioni.cc
	g++ -o compila main.cpp funzioni.cc

esegui:
	./compila

clean: 
	rm compila
