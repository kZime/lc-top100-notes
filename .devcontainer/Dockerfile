FROM ubuntu:24.04
LABEL authors="kzime"

ENV DEBIAN_FRONTEND=noninteractive

# Core build tools
RUN apt-get update && apt-get install -y --no-install-recommends \
    g++ \
    clang \
    gdb \
    cmake \
    make \
    ninja-build \
    curl \
    wget \
    git \
    ca-certificates \
    libstdc++-13-dev \
  && rm -rf /var/lib/apt/lists/*

# Go
ARG GO_VERSION=1.22.4
RUN curl -fsSL "https://go.dev/dl/go${GO_VERSION}.linux-amd64.tar.gz" \
    | tar -C /usr/local -xz
ENV PATH="/usr/local/go/bin:${PATH}"

WORKDIR /workspace

# Keep container running so CLion can exec into it
CMD ["sleep", "infinity"]
