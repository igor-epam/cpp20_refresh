ARG VARIANT=debian-11
FROM mcr.microsoft.com/vscode/devcontainers/base:0-${VARIANT}

# Install needed packages. Use a separate RUN statement to add your own dependencies.
#COPY library-scripts/meta.env /usr/local/etc/vscode-dev-containers
RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
    && apt-get -y install software-properties-common
#RUN grep ^ /etc/apt/sources.list /etc/apt/sources.list.d/*
RUN rm /etc/apt/sources.list
RUN add-apt-repository "deb http://deb.debian.org/debian/ testing non-free contrib main"
RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
    && apt-get -y install gcc-11 ninja-build cmake python3-pip 
RUN export DEBIAN_FRONTEND=noninteractive \
    && apt-get -y install ninja-build cmake cmake-format cppcheck lldb gdb \ 
    && apt-get autoremove -y && apt-get clean -y && rm -rf /var/lib/apt/lists/*
RUN add-apt-repository "deb http://deb.debian.org/debian/ bullseye non-free contrib main"
RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
    && apt-get -y install python3-pip clang-13 clang-format-13 clang-tidy-13

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