footBall: main.cpp classes/Player.cpp classes/Team.cpp classes/Simulation.cpp classes/gui.cpp
	g++ -o footBall main.cpp classes/Player.cpp classes/Team.cpp classes/Simulation.cpp classes/gui.cpp -lraylib -std=c++11
clean:
	rm -rf footBall