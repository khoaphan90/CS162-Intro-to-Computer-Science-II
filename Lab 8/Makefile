all: program1 program2 program3

PROJECT = Lab8_Phan_Khoa
CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -g
LDFLAGS = -lboost_date_time

OBJS1 = program1.o
OBJS2 = program2.o
OBJS3 = program3.o
SRCS1 = validation.cpp program1.cpp
SRCS2 = validation.cpp program2.cpp
SRCS3 = validation.cpp program3.cpp
HEADERS = validation.hpp

#target: dependencies

program1: ${OBJS1} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SRCS1} -o program1

program2: ${OBJS2} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SRCS2} -o program2
	
program3: ${OBJS3} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SRCS3} -o program3

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm -f -o program1 program2 program3

zip:
	zip ${PROJECT}.zip *.cpp *.hpp *.pdf *.txt Makefile
