XX = g++
CXXFLAGS = -Wall -MMD -g
EXEC = cc3k
OBJECTS = cell.o character.o  elf.o game.o gold.o item.o  merchant.o passage.o player.o stairs.o vampire.o chamber.o dragon.o dwarf.o enemy.o goblin.o human.o level.o main.o orc.o phoenix.o potion.o troll.o werewolf.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}


