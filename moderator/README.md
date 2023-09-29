# Docker image for running vsomeip
By following the instructions below you can run vsomeip application on MacOS!

## Requirements
First you need docker engine running on your mac to run docker commands.

Install docker desktop from [here](https://www.docker.com/products/docker-desktop/)

## Create docker image
```
docker build -t vsomeip -f Dockerfile . 
```

## Create docker volume
```
docker volume create vsomeip-volume
```

## Run docker container
```
docker run -it --rm -v vsomeip-volume:/root vsomeip
```

## Working with VSCode
If you install docker extension on VSCode you can attach editor on the running container by right click container -> Attach Visual Studio Code.

Have Fun!