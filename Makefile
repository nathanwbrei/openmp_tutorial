#./linux make executable ex=ex1

CC=/usr/bin/gcc
CFLAGS=-fopenmp

.PHONY: output presentation autorebuild paper

all: presentation

presentation:
	pdflatex -shell-escape -interaction=batchmode -halt-on-error -output-directory=build presentation/openmp_intro.tex

presentation-auto:
	fswatch -0 presentation | xargs -0 -n 1 make presentation

paper:
	pdflatex -shell-escape -halt-on-error -interaction=batchmode -output-directory=build paper/brei.tex

paper-verbose:
	pdflatex -shell-escape -output-directory=build paper/brei.tex

paper-auto:
	fswatch -0 -o -r -l 1 -e ".*" -i"\.tex" paper | xargs -0 -n 1 -I NONE make paper


executable:
	$(CC) $(CFLAGS) -g -O0 src/$(ex).c -o build/$(ex)

output: executable
	build/$(ex) > output/$(ex).txt
	cat output/$(ex).txt

assembly:
	$(CC) $(CFLAGS) -S src/$(ex).c -o build/$(ex)

