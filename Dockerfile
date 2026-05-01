# Dockerfile to create standard linux environment.
# To build:
#	docker build -t my-c-compiler
# To mount local directory and run container:
#	docker run  --rm -it -v ${PWD}:/usr/src/game <image_name>

# Base Ubuntu Image
FROM ubuntu:latest

# Update and Install C Compiler Toolchain
RUN apt-get update && apt-get install -y \
	build-essential \
	cmake \
	&& rm -rf /var/lib/apt/lists/*

# Set working directory inside container
WORKDIR /usr/src/

# Copy game files to inside of container
COPY game

# Default Command To Open a Shell
CMD ["/bin/bash"]
