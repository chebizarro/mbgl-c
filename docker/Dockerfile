FROM ubuntu:latest
CMD bash

RUN apt-get update && apt-get -y install \
  apt-utils \
  build-essential \
  curl \
  git \
  tar \
  wget \
  zlib1g-dev \
  automake \
  libtool \
  xutils-dev \
  make \
  pkg-config \
  python-pip \
  libcurl4-openssl-dev \
  libpng-dev \
  libsqlite3-dev \
  cmake \
  clang \
  libxi-dev \
  libglu1-mesa-dev \
  x11proto-randr-dev \
  x11proto-xext-dev \
  libxrandr-dev \
  x11proto-xf86vidmode-dev \
  libxxf86vm-dev \
  libxcursor-dev \
  libxinerama-dev

#RUN mkdir -p /opt/src/mbgl-c
ADD . /opt/src/mbgl-c

RUN git -C /opt/src clone https://github.com/mapbox/mapbox-gl-native.git
RUN cd /opt/src/mapbox-gl-native && make linux-core

RUN cd /opt/src/mbgl-c && make

