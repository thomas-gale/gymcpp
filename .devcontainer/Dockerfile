# My development machines all have nvidia gpus
FROM nvidia/opengl:1.0-glvnd-devel-ubuntu18.04

# Global settings
# Torch 1.4, only has Cuda 10.1 support (I think..)
ENV CMAKE_VERSION=3.17.2
ENV PROTO_VERSION=3.12.3

# Configure a SUDO non-root user (no password)
ARG USERNAME=vscode
ARG USER_UID=1000
ARG USER_GID=$USER_UID

RUN groupadd --gid $USER_GID $USERNAME \
    && useradd --uid $USER_UID --gid $USER_GID -m $USERNAME \
    && apt-get update \
    && apt-get install -y sudo \
    && echo $USERNAME ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/$USERNAME \
    && chmod 0440 /etc/sudoers.d/$USERNAME

# Set the non-root SUDO user as default user. 
USER $USERNAME

# Pre-requsities and development tools.
RUN sudo apt-get update \
    && sudo apt-get install -y software-properties-common \
        unzip wget git \
        build-essential gdb clang clang-format clang-tidy

# Install CMake binary
RUN mkdir -p ~/temp \
    && cd ~/temp \
    && wget https://github.com/Kitware/CMake/releases/download/v$CMAKE_VERSION/cmake-$CMAKE_VERSION-Linux-x86_64.sh \
    && sudo mkdir /opt/cmake \
    && sudo sh cmake-$CMAKE_VERSION-Linux-x86_64.sh --prefix=/opt/cmake --skip-license \
    && sudo ln -s /opt/cmake/bin/cmake /usr/local/bin/cmake \
    && cmake --version

# Protocolbuffers & compiler
# https://github.com/protocolbuffers/protobuf/blob/master/src/README.md#c-installation---unix
RUN cd /usr/local/src && sudo wget https://github.com/protocolbuffers/protobuf/releases/download/v$PROTO_VERSION/protobuf-cpp-$PROTO_VERSION.zip \
    && sudo unzip protobuf-cpp-$PROTO_VERSION.zip \
    && cd protobuf-$PROTO_VERSION \
    && sudo ./configure \
    && sudo make -j8 \
    && sudo make check \
    && sudo make install \
    && sudo ldconfig

# Clean up
RUN sudo rm -r ~/temp \ 
    && sudo apt-get autoremove -y \
    && sudo apt-get clean -y