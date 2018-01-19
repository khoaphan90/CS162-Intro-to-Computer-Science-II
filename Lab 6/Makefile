PROJECT = Lab6_Phan_Khoa
CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -g
LDFLAGS = -lboost_date_time

OBJS = main.o numberList.o validation.o

SRCS = main.cpp numberList.cpp validation.cpp 

HEADERS = numberList.hpp validation.hpp 

#target: dependencies

dieGame: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SRCS} -o  linkedList

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm -f *.o

zip:
	zip ${PROJECT}.zip *.cpp *.hpp  Makefile
