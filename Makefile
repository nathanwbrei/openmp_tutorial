CC=/usr/bin/gcc
CFLAGS=-fopenmp
#./linux make executable ex=ex1

.PHONY: output presentation

presentation:
	pdflatex -shell-escape -aux-directory=latex -output-directory=build presentation/openmp_intro.tex

executable:
	$(CC) $(CFLAGS) -g -O0 src/$(ex).c -o build/$(ex)

output: executable
	build/$(ex) > output/$(ex).txt
	cat output/$(ex).txt

assembly:
	$(CC) $(CFLAGS) -S src/$(ex).c -o build/$(ex)

