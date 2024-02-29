# CLIReport

A tool to report CLI arguments.

# Build

## Windows

```
cl clireport.c
clireport.exe A B
```

## Linux

```
docker run --rm -v "$(pwd):/clireport" -w /clireport gcc:latest gcc -o clireport clireport.c
docker run --rm -v "$(pwd):/clireport" -w /clireport ubuntu:latest /clireport/clireport A B
```

## Docker

```
docker build --tag=ghcr.io/g2forge/clireport:latest .
docker run ghcr.io/g2forge/clireport:latest A B
docker push ghcr.io/g2forge/clireport:latest
```