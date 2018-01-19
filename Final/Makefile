PROJECT = ProjectFinal_Phan_Khoa
CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -g
LDFLAGS = -lboost_date_time

OBJS = main.o arrowRoom.o battery.o crowbar.o inventory.o items.o key.o player.o powerRoom.o room.o spikeRoom.o startRoom.o validation.o wallRoom.o wrench.o zombie.o zombieRoom.o

SRCS = main.cpp arrowRoom.cpp battery.cpp crowbar.cpp inventory.cpp items.cpp key.cpp player.cpp powerRoom.cpp room.cpp spikeRoom.cpp startRoom.cpp validation.cpp wallRoom.cpp wrench.cpp zombie.cpp zombieRoom.cpp

HEADERS = arrowRoom.hpp battery.hpp crowbar.hpp inventory.hpp items.hpp key.hpp player.hpp powerRoom.hpp room.hpp spikeRoom.hpp startRoom.hpp validation.hpp wallRoom.hpp wrench.hpp zombie.hpp zombieRoom.hpp

#target: dependencies

game: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SRCS} -o finalProject

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm -f *.o

zip:
	zip ${PROJECT}.zip *.cpp *.hpp *.pdf Makefile
