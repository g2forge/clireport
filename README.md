# CLIReport

A tool to report CLI arguments.

# Build

## Windows

```
cl clireport.c
.\clireport.exe A B; echo $LastExitCode
.\clireport.exe --exit 1 A B; echo $LastExitCode
.\clireport.exe --exit x; echo $LastExitCode
```

## Linux

```
docker run --rm -v "$(pwd):/clireport" -w /clireport gcc:latest gcc -o clireport clireport.c
docker run --rm -v "$(pwd):/clireport" -w /clireport ubuntu:latest bash -c '/clireport/clireport A B; echo $?'
docker run --rm -v "$(pwd):/clireport" -w /clireport ubuntu:latest bash -c '/clireport/clireport --exit 1 A B; echo $?'
docker run --rm -v "$(pwd):/clireport" -w /clireport ubuntu:latest bash -c '/clireport/clireport --exit x; echo $?'
```

## Docker

```
docker build --tag=ghcr.io/g2forge/clireport:latest .
docker run ghcr.io/g2forge/clireport:latest A B
docker run ghcr.io/g2forge/clireport:latest --exit 1 A B
docker run ghcr.io/g2forge/clireport:latest --exit x
docker push ghcr.io/g2forge/clireport:latest
docker image tag ghcr.io/g2forge/clireport:latest ghcr.io/g2forge/clireport:v0.0.4
docker push ghcr.io/g2forge/clireport:v0.0.4
```

# Release

1. Update [pom.xml](pom.xml) to remove `-SNAPSHOT`, and commit.
2. Update [pom.xml](pom.xml) to update version and re-add `-SNAPSHOT`, and commit.
3. Open a PR
4. Create github release and upload pre-built binaries, tagging the commit created in step 1.
5. Update `HCLIReport` to use the new release, and to match any changes to the command line argument handling or expected output
