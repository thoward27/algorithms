FROM ubuntu:19.04

RUN apt-get -y update && apt-get -y upgrade && apt install -y make && apt install -y g++-8

COPY . /app

WORKDIR /app

ENTRYPOINT [ "make" ]

CMD []