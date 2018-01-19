PROJECT = Project1_Phan_Khoa
CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -g
LDFLAGS = -lboost_date_time

OBJS = main.o menu.o ant.o gameBoard.o validation.o

SRCS = main.cpp menu.cpp ant.cpp gameBoard.cpp validation.cpp

HEADERS = menu.hpp ant.hpp gameBoard.hpp validation.hpp

#target: dependencies

langstonAnt: ${OBJS} ${HEADERS}
	${CXX} ${SRCS} -o langstonAnt

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm -f *.o

zip:
	zip ${PROJECT}.zip *.cpp *.hpp *.pdf Makefile
