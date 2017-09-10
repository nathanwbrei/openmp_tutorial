FROM ubuntu:latest
COPY . /src
WORKDIR /src
RUN apt-get update && apt-get install -y \
    autoconf automake gcc build-essential git libtool make nasm gdb valgrind likwid perf

CMD make
