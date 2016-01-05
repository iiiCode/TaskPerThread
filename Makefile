all:
	g++ *.cpp -o app -g -Wall -std=c++11 -lpthread
clean:
	rm -rf app
