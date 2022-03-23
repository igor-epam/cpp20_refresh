ARG VARIANT=debian-11
FROM mcr.microsoft.com/vscode/devcontainers/base:0-${VARIANT}

# Install needed packages. Use a separate RUN statement to add your own dependencies.
#COPY library-scripts/meta.env /usr/local/etc/vscode-dev-containers
RUN apt-get update && export DEBIAN_FRONTEND=non-interactive \
    && apt-get -y install software-properties-common
RUN bash -c "$(wget -O - https://apt.llvm.org/llvm.sh)"
RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
    && apt-get -y install build-essential ninja-build cmake cppcheck valgrind lldb gdb python3-pip \ 
    && apt-get autoremove -y && apt-get clean -y && rm -rf /var/lib/apt/lists/*
RUN export DEBIAN_FRONTEND=noninteractive \
    && apt-get -y install clang-format clang-tidy

# Setup ENV vars for vcpkg
#ENV VCPKG_ROOT=/usr/local/vcpkg \
#    VCPKG_DOWNLOADS=/usr/local/vcpkg-downloads
#ENV PATH="${PATH}:${VCPKG_ROOT}"

ARG USERNAME=vscode

RUN pip3 install conan 

# Install vcpkg itself: https://github.com/microsoft/vcpkg/blob/master/README.md#quick-start-unix
#COPY base-scripts/install-vcpkg.sh /tmp/
#RUN /tmp/install-vcpkg.sh ${USERNAME} \
#    && rm -f /tmp/install-vcpkg.sh