PROJECT = Lab4_Phan_Khoa
CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -g
LDFLAGS = -lboost_date_time

OBJS = main.o menu.o validation.o building.o instructor.o people.o student.o university.o

SRCS = main.cpp menu.cpp validation.cpp building.cpp instructor.cpp people.cpp student.cpp  university.cpp 

HEADERS = menu.hpp validation.hpp building.hpp instructor.hpp people.hpp student.hpp university.hpp

#target: dependencies

dieGame: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SRCS} -o  universityIS

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm -f *.o

zip:
	zip ${PROJECT}.zip *.cpp *.hpp  Makefile
