CXX = g++-5
CXXFLAGS = -std=c++14 -Wall -MMD -g -Werror=vla
EXEC = RAIInet
OBJECTS = main.o game.o player.o ability.o link.o subject.o TextDisplay.o graphics.o window.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
		${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11

-include ${DEPENDS}

.PHONY: clean

clean:
		rm ${OBJECTS} ${EXEC} ${DEPENDS}