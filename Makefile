footBall: main.cpp classes/Player.cpp classes/Team.cpp classes/Simulation.cpp
	g++ -o footBall main.cpp classes/Player.cpp classes/Team.cpp classes/Simulation.cpp -std=c++11
clean:
	rm -rf footBall