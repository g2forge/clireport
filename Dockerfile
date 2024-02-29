FROM alpine:latest as build
RUN apk add --no-cache gcc musl-dev
RUN mkdir -p /clireport
COPY clireport.c /clireport
WORKDIR /clireport
RUN gcc -o clireport clireport.c

FROM alpine:latest
LABEL org.opencontainers.image.source="https://github.com/g2forge/clireport"
COPY --from=build /clireport/clireport /bin/clireport
ENTRYPOINT ["/bin/clireport"]
