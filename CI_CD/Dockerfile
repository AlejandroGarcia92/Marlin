FROM ubuntu:latest

ENV WORK_DIR /work_dir
ENV BINARY_NAME arduino-cli

RUN mkdir --parent "${WORK_DIR}"
WORKDIR "${WORK_DIR}"

RUN apt-get update && apt-get upgrade --yes --quiet && apt-get install --yes --quiet \
    curl \
    wget \
    && \
    apt-get --yes autoremove && \
    apt-get --yes autoclean && \
    apt-get --yes clean

# Install compiler
RUN curl --silent https://api.github.com/repos/arduino/arduino-cli/releases/latest \
    | grep browser_download_url \
    | grep Linux_64 \
    | cut --delimiter '"' --fields 4 \
    | wget --quiet --input-file - \
    && \
    tar --get --file `ls *.tar.gz` -gzip "${BINARY_NAME}" && \
    chmod 755 "${BINARY_NAME}" && \
    mv "${BINARY_NAME}" /usr/local/bin && \
    rm `ls *.tar.gz`

RUN "${BINARY_NAME}" core update-index && \
    "${BINARY_NAME}" core install arduino:avr

# Build project
COPY . "${WORK_DIR}"

RUN "${BINARY_NAME}" compile --fqbn arduino:avr:mega Marlin/Marlin.ino
