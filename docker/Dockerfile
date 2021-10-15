FROM ubuntu:xenial
RUN apt-get update \
  && DEBIAN_FRONTEND=noninteractive apt-get install --no-install-recommends --no-install-suggests -y \
      bzip2 \
      curl \
      net-tools \
      git \
      subversion \
      vim \
      software-properties-common \
      python-software-properties \
      wget \
      unzip \
      zip \
      python3-pip \
      locales \
      tzdata \
      openssh* \
       binutils \
       build-essential \
       libcurl3-dev\
       python3-setuptools \
       mlocate \
       locate \
       libboost-dev \
       libmysqlclient-dev \
       libcurl4-openssl-dev
RUN locale-gen en_US.UTF-8
ENV LANG en_US.UTF-8
ENV LANGUAGE en_US:en
ENV LC_ALL en_US.UTF-8
RUN updatedb
RUN \
curl -s https://packagecloud.io/install/repositories/github/git-lfs/script.deb.sh | bash &&\
apt-get install git-lfs &&\
git lfs install &&\
cp /usr/bin/git-lfs /usr/lib/git-core/
ENV TZ=Asia/Shanghai
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone
RUN rm  /bin/sh &&\
ln -s /bin/bash /bin/sh
RUN pip3 install lxml requests
CMD ["/bin/bash"]
