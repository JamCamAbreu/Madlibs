# makefile for the Madlib program
#

CXX = g++
CXXFLAGS = -std=c++0x
# CXXFLAGS += Wall
CXXFLAGS += -pedantic-errors
#LDFLAGS = -lboost_date_time

OBJS = Madlib.o textProcessor.o getAnswers.o searchFiles.o menu.o
SRCS = Madlib.cpp textProcessor.cpp getAnswers.cpp searchFiles.cpp menu.cpp
HEADERS = Madlib.hpp textProcessor.hpp getAnswers.hpp searchFiles.hpp

MadlibsTest: ${OBJS} ${HEADERS}
	${CXX} ${OBJS} -o MadlibsTest

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm -f *.o

