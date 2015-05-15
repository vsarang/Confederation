EXENAME = confederations

COMPILER = g++
WARNINGS = -Wchar-subscripts -Wparentheses -Wreturn-type -Wmissing-braces -Wundef
COMPILER_OPTS = -c -g -O0 -std=c++11 -Wfatal-errors -Werror $(WARNINGS)

SFML = -lsfml-graphics -lsfml-window -lsfml-system

all: $(EXENAME)

$(EXENAME): main.o game.o gamestatestart.o gamestateeditor.o texturemanager.o
	$(COMPILER) -o $@ $^ $(SFML)

main.o: main.cpp game.o gamestatestart.o
	$(COMPILER) $(COMPILER_OPTS) $<

game.o: game.cpp game.h texturemanager.o
	$(COMPILER) $(COMPILER_OPTS) $<

gamestate.o: gamestate.h
	$(COMPILER) $(COMPILER_OPTS) $<

gamestatestart.o: gamestatestart.cpp gamestatestart.h gamestate.o game.o gamestateeditor.o
	$(COMPILER) $(COMPILER_OPTS) $<

gamestateeditor.o: gamestateeditor.cpp gamestateeditor.h gamestate.o game.o
	$(COMPILER) $(COMPILER_OPTS) $<

texturemanager.o: texturemanager.cpp texturemanager.h
	$(COMPILER) $(COMPILER_OPTS) $<

clean:
	-rm -f *.o *.h.gch $(EXENAME)
