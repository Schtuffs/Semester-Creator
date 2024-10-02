CXX 	= g++
SRC		= ../src
INCLUDE	= ../include
CPPFLAGS= -I${INCLUDE} -c
OBJECTS	= main.o DirectoryHandler.o

Semester Creator: ${OBJECTS}
	${CXX} -o "Semester-Creator" ${OBJECTS}

main.o: ${SRC}/main.cpp
	${CXX} ${CPPFLAGS} $<

DirectoryHandler.o: ${SRC}/DirectoryHandler.cpp ${INCLUDE}/DirectoryHandler.h
	${CXX} ${CPPFLAGS} $<

clean:
	del -q *.o *.exe
