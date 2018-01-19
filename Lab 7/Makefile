PROJECT = Lab7_Phan_Khoa
CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -g
LDFLAGS = -lboost_date_time

OBJS = main.o queue.o validation.o menu.hpp

SRCS = main.cpp queue.cpp validation.cpp menu.cpp

HEADERS = queue.hpp validation.hpp 

#target: dependencies

dieGame: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SRCS} -o  queue

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm -f *.o

zip:
	zip ${PROJECT}.zip *.cpp *.hpp  Makefile
