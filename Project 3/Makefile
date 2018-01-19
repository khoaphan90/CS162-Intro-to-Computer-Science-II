PROJECT = Project3_Phan_Khoa
CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -g
LDFLAGS = -lboost_date_time

OBJS = main.o menu.o validation.o barbarian.o blue_men.o creature.o die.o game.o harry_potter.o medusa.o vampire.o

SRCS = main.cpp menu.cpp validation.cpp barbarian.cpp blue_men.cpp creature.cpp die.cpp game.cpp harry_potter.cpp medusa.cpp vampire.cpp

HEADERS = menu.hpp validation.hpp barbarian.cpp blue_men.cpp creature.cpp die.cpp game.cpp harry_potter.cpp medusa.cpp vampire.cpp

#target: dependencies

game: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SRCS} -o game

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm -f *.o

zip:
	zip ${PROJECT}.zip *.cpp *.hpp *.pdf Makefile
