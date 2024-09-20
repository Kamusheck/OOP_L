FROM gcc:14.2.0

RUN apt-get update && apt-get install -y git cmake g++

RUN apt-get update && apt-get install -y \
    g++ \
    cmake \
    && rm -rf /var/lib/apt/lists/*

RUN git clone https://github.com/google/googletest.git /googletest

RUN apt-get install -y git &&  \
    cd /googletest && \
    cmake . && \
    make && \
    cp -r include/* /usr/local/include/ && \
    cp -r lib/* /usr/local/lib/



WORKDIR /workspace


