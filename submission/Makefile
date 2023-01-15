CC = g++
CPP_FILES = $(wildcard *.cpp)
OBJ_FILES = $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))

.PHONY: all
all: trial rise redemption

trial: $(OBJ_FILES)
    $(CC) -o $@ $^

rise: $(OBJ_FILES)
    $(CC) -o $@ $^

redemption: $(OBJ_FILES)
    $(CC) -o $@ $^

obj/%.o: %.cpp
    $(CC) -c -o $@ $<

.PHONY: clean
clean:
    rm -f trial rise redemption $(OBJ_FILES)
