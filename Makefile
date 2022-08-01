footBall: main.cpp Player.cpp Team.cpp Simulation.cpp
	g++ -o footBall main.cpp Player.cpp Team.cpp Simulation.cpp -std=c++11
clean:
	rm -rf footBall