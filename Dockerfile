FROM ubuntu:24.04

USER root

RUN echo "# --- my scripts ---" >> ~/.bashrc && echo "cd ~/" >> ~/.bashrc

RUN apt update && apt install -y software-properties-common less wget zip vim && \
    add-apt-repository -y ppa:ubuntu-toolchain-r/test

# GCC
RUN apt install -y g++-12

#GMP
RUN apt install -y libgmp3-dev

# ac library
RUN mkdir /opt/ac-library && \
    wget https://github.com/atcoder/ac-library/releases/download/v1.5.1/ac-library.zip -O /tmp/ac-library.zip && \
    unzip /tmp/ac-library.zip -d /opt/ac-library && echo "export MY_ATCODER_LIBRARY_ROOT=/opt/ac-library" >> ~/.bashrc

# boost
RUN apt install -y build-essential
RUN wget -q https://github.com/boostorg/boost/releases/download/boost-1.82.0/boost-1.82.0.tar.gz -O boost_1_82_0.tar.gz \
    && tar xf boost_1_82_0.tar.gz \
    && cd boost-1.82.0 \
    && ./bootstrap.sh --with-toolset=gcc --without-libraries=mpi,graph_parallel \
    && ./b2 -j3 toolset=gcc variant=release link=static runtime-link=static cxxflags="-std=c++2b" stage \
    && ./b2 -j3 toolset=gcc variant=release link=static runtime-link=static cxxflags="-std=c++2b" --prefix=/opt/boost/gcc install \
    && echo "export MY_BOOST_LIB_ROOT=/opt/boost/gcc/include" >> ~/.bashrc

#Eigen
RUN apt install -y libeigen3-dev=3.4.0-4 && echo "export MY_EIGEN_LIB_ROOT=/usr/include/eigen3" >> ~/.bashrc

# basic build command
# RUN echo "function f(){ g++ -std=c++23 $1.cpp -I ${MY_ATCODER_LIBRARY_ROOT} -I ${MY_BOOST_LIB_ROOT} -I ${MY_EIGEN_LIB_ROOT}; }" >> ~/.bashrc


# atcoder cli
RUN apt install -y npm 
RUN npm install -g atcoder-cli && acc config default-task-choice all
# acc login

# oj-tool
RUN apt install -y python3-pip && python3 -m pip install online-judge-tools online-judge-verify-helper --break-system-packages
# oj login https://atcoder.jp/

# optional
RUN apt install -y gdb

# kyopro commands
COPY ./.kyopro.bashrc /tmp/.kyopro.bashrc
RUN cat /tmp/.kyopro.bashrc >> /root/.bashrc && rm /tmp/.kyopro.bashrc

# vscode
RUN mkdir -p /root/.vscode
COPY ./kyopro.code-snippets /root/.vscode/

CMD ["bash"]