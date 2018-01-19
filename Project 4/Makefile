PROJECT = Project4_Phan_Khoa
CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -g
LDFLAGS = -lboost_date_time

OBJS = main.o menu.o validation.o barbarian.o blue_men.o creature.o die.o game.o harry_potter.o medusa.o vampire.o cQueue.o cStack.o

SRCS = main.cpp menu.cpp validation.cpp barbarian.cpp blue_men.cpp creature.cpp die.cpp game.cpp harry_potter.cpp medusa.cpp vampire.cpp cQueue.cpp cStack.cpp

HEADERS = menu.hpp validation.hpp barbarian.hpp blue_men.hpp creature.hpp die.hpp game.hpp harry_potter.hpp medusa.hpp vampire.hpp cQueue.hpp cStack.hpp

#target: dependencies

game: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SRCS} -o tournament

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm -f *.o

zip:
	zip ${PROJECT}.zip *.cpp *.hpp *.pdf Makefile
