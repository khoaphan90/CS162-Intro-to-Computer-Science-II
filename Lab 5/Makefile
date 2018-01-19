PROJECT = Lab5_Phan_Khoa
CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -g
LDFLAGS = -lboost_date_time

OBJS = main.o menu.o validation.o recursion.o

SRCS = main.cpp menu.cpp validation.cpp recursion.cpp

HEADERS = menu.hpp validation.hpp recursion.hpp

#target: dependencies

dieGame: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SRCS} -o  recursion

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm -f *.o

zip:
	zip ${PROJECT}.zip *.cpp *.hpp  Makefile
