PROJECT = Project2_Phan_Khoa
CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -g
LDFLAGS = -lboost_date_time

OBJS = main.o menu.o item.o validation.o list.o

SRCS = main.cpp menu.cpp item.cpp list.cpp validation.cpp

HEADERS = menu.hpp item.hpp list.hpp validation.hpp

#target: dependencies

groceryList: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SRCS} -o groceryList

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm -f *.o

zip:
	zip ${PROJECT}.zip *.cpp *.hpp *.pdf Makefile
