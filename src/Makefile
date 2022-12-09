CXX = g++
CXXFLAGS = -Wno-unused-parameter -Wno-unused-function -Wno-ignored-qualifiers
CXXFLAGS += -std=c++14 -Wall -Wextra -g -MMD -O3
PROGRAM = X11BadApple
MAKEFLAGS += -j "$(nproc)"

OBJECTS = $(patsubst %.cc,%.o,$(wildcard **/*.cc)) main.o
DEPENDS = ${OBJECTS:.o=.d}

${PROGRAM}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${PROGRAM} -lX11
#rm ${OBJECTS} ${DEPENDS}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${DEPENDS} ${PROGRAM}
