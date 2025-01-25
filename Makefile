all: src/axis.cpp
	g++ src/axis.cpp -o axis

clean:
	$(RM) axis
