footBall: main.cpp classes/Player.cpp classes/Team.cpp classes/Simulation.cpp classes/Gui.cpp
	g++ -o footBall main.cpp classes/Player.cpp classes/Team.cpp classes/Simulation.cpp classes/Gui.cpp -lraylib -std=c++11
clean:
	rm -rf footBall