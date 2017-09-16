#./linux make executable ex=ex1

CC=/usr/bin/gcc
CFLAGS=-fopenmp

.PHONY: output presentation autorebuild

all: presentation

presentation:
	pdflatex -shell-escape -interaction=batchmode -halt-on-error -output-directory=build presentation/openmp_intro.tex

autorebuild:
	fswatch -0 presentation | xargs -0 -n 1 make presentation

executable:
	$(CC) $(CFLAGS) -g -O0 src/$(ex).c -o build/$(ex)

output: executable
	build/$(ex) > output/$(ex).txt
	cat output/$(ex).txt

assembly:
	$(CC) $(CFLAGS) -S src/$(ex).c -o build/$(ex)

