FROM ubuntu:latest

ENV DEBIAN_FRONTEND noninteractive
RUN apt-get update && apt-get upgrade -y
RUN apt-get install build-essential -y
RUN apt-get install gdb -y
RUN apt-get install nasm -y
RUN apt-get install gcc-multilib -y