PROJECT = Lab3_Phan_Khoa
CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -g
LDFLAGS = -lboost_date_time

OBJS = main.o menu.o die.o loadedDie.o validation.o game.o

SRCS = main.cpp menu.cpp die.cpp loadedDie.cpp game.cpp validation.cpp

HEADERS = menu.hpp die.hpp loadedDie.hpp game.hpp validation.hpp

#target: dependencies

dieGame: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SRCS} -o dieGame

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm -f *.o

zip:
	zip ${PROJECT}.zip *.cpp *.hpp *.pdf Makefile
