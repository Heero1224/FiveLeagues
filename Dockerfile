# Dockerfile to create standard linux environment.
# To build:
#	docker build -t my-c-compiler
# To mount local directory and run container:
#	docker run  --rm -it -v ${PWD}:/usr/src/game <image_name>

# Base Ubuntu Image (Alpine is 5Mb)
FROM alpine as build-env
# Install build-base meta package inside build-env
RUN apk add --no--cache build-base
# Copy source files to container
COPY . /source
# Change directory to /game
WORKDIR /source
# Compile source code
RUN make

## To run the program in a new container
# FROM alpine
## Copy executable
# COPY --from=build-env /game/main /game/main
# WORKDIR /game
## Run program
# CMD ["/game/main"]
