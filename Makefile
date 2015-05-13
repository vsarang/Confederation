EXENAME = confederations

COMPILER = g++
WARNINGS = -Wchar-subscripts -Wparentheses -Wreturn-type -Wmissing-braces -Wundef -Wshadow
COMPILER_OPTS = -c -g -O0 -Wfatal-errors -Werror $(WARNINGS)

all: $(EXENAME)

$(EXENAME): main.o vector.o
	$(COMPILER) -o $@ $^ $(LSDL)

main.o: main.cpp vector.o
	$(COMPILER) $(COMPILER_OPTS) $<

vector.o: vector.cpp vector.h
	$(COMPILER) $(COMPILER_OPTS) $<

clean:
	-rm -f *.o *.h.gch $(EXENAME)
