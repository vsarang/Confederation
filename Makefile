EXENAME = confederations

COMPILER = g++
WARNINGS = -Wchar-subscripts -Wparentheses -Wreturn-type -Wmissing-braces -Wundef -Wshadow
COMPILER_OPTS = -c -g -O0 -Wfatal-errors -Werror $(WARNINGS)

all: $(EXENAME)

$(EXENAME): main.o
	$(COMPILER) -o $@ $^ $(LSDL)

main.o: main.cpp
	$(COMPILER) $(COMPILER_OPTS) $<

clean:
	-rm -f *.o *.h.gch $(EXENAME)
