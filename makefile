src=$(wildcard *.c)
obj=$(src:.c=.o)

all: $(obj)

%.o: %.c
	@echo Compiling
	@gcc -Wall $< -lm -o $@
	@echo Done

clean:
	@rm -rf $(obj)

run: $(obj)
	./$(obj)
