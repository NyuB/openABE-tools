FROM ubuntu:latest
WORKDIR /oabe
ENV LD_LIBRARY_PATH=/usr/local/lib
ADD alter/ alter/
RUN apt-get update -y && \
    apt-get install -y g++-7 && \
    apt-get install -y g++ curl libssl-dev bison flex make unzip sudo bash git && \
    curl https://codeload.github.com/zeutro/openabe/zip/refs/tags/v1.0 > ./openabe-1.0.zip && \
    unzip ./openabe-1.0.zip && \
    cp alter/download_gtest.sh /oabe/openabe-1.0/deps/gtest/download_gtest.sh && \
    cp alter/Makefile /oabe/openabe-1.0/Makefile && \
    cd /oabe/openabe-1.0 && ./deps/install_pkgs.sh && \
    bash -c ". ./env && make && make test" && \
    bash -c ". ./env && make install" && \
    rm -rf /oabe/*
ENTRYPOINT ["/bin/bash"]