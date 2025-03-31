all:
	g++ -g -Wall dpmain.cpp biggest-divisible-conglomerate.cpp -o bdc

run:
	./bdc

try: all run