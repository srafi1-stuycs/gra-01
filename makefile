compile: ppmaker.c
	gcc ppmaker.c -o ppmaker
run: compile ppmaker
	./ppmaker
feh: run
	feh basic.ppm
clean: ppmaker
	rm ppmaker
	rm basic.ppm
