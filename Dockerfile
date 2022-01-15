# Using alpine for build to keep docker image repository small and most people would likely have alpine locally anyway
FROM alpine:latest as build

WORKDIR /usr/app

RUN apk update && apk add build-base && apk add make

COPY Makefile /usr/app/Makefile

RUN make alpine-setup

COPY src/ /usr/app/src/
COPY integration_tests/ /usr/app/integration_tests/

RUN make test integration-test build-static

# Using scratch to keep the image size to a minimum
# If you were wanting to use docker for development you might prefer a base image with a debugger & development tools
FROM scratch as runtime

COPY --from=build /usr/app/bin/toy_robot_static /usr/app/toy_robot

ENTRYPOINT ["/usr/app/toy_robot"]
