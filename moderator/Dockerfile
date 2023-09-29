FROM ubuntu:20.04

RUN apt update
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y \
	git \
	python3 \
	python3-pip \
	cmake \
	libboost-all-dev \
	asciidoc \
	source-highlight \
	doxygen \
	graphviz

WORKDIR /root

RUN git clone https://github.com/COVESA/vsomeip.git vsomeip
RUN mkdir -p vsomeip/build
RUN cmake -S vsomeip -B vsomeip/build
WORKDIR /root/vsomeip/build
RUN make
RUN make install
RUN ldconfig

WORKDIR /root
COPY ./tools/entrypoint.sh /entrypoint.sh
RUN chmod	+x /entrypoint.sh

# ENTRYPOINT ["/entrypoint.sh"]