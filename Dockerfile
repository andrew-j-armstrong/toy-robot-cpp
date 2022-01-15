FROM alpine:latest as build

WORKDIR /usr/app

RUN apk update && apk add build-base && apk add make

COPY src/ /usr/app/src/
COPY integration_tests/ /usr/app/integration_tests/
COPY Makefile /usr/app/Makefile

RUN make alpine-setup

RUN make all

FROM alpine:latest as runtime

COPY --from=build /usr/app/bin/toy_robot /usr/app/toy_robot

CMD "/usr/app/toy_robot"
