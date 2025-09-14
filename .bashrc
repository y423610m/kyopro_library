export KYOPRO_DOCKER_IMAGE_NAME=kyopro_image
export KYOPRO_DOCKER_CONTAINER_NAME=kyopro_container

function kyopro_build_docker(){
    docker compose -f ${MY_KYOPRO_LIBRARY_ROOT}/docker-compose.yml build
    # docker compose -f ~/kyopro_library/docker-compose.yml build
    # docker build -t ${KYOPRO_DOCKER_IMAGE_NAME} ${MY_KYOPRO_DOCKER_ROOT}
}

function kyopro_run_docker(){
    docker compose -f ${MY_KYOPRO_LIBRARY_ROOT}/docker-compose.yml run --rm -v $(pwd):/mnt/$(basename $(pwd)) kyopro
    # docker compose -f ~/kyopro_library/docker-compose.yml run -v $(pwd):/mnt/ kyopro
    # docker run -v ~/AtCoder:/root/AtCoder -v ~/kyopro_library:/root/kyopro_library --rm --name ${KYOPRO_DOCKER_CONTAINER_NAME} -it ${KYOPRO_DOCKER_IMAGE_NAME}
}

function kyopro_exec_docker(){
    docker compose -f ${MY_KYOPRO_LIBRARY_ROOT}/docker-compose.yml exec -it kyopro bash
    # docker exec -it ${KYOPRO_DOCKER_CONTAINER_NAME} bash
}

function kyopro_commit_docker(){
    docker commit ${KYOPRO_DOCKER_CONTAINER_NAME} ${KYOPRO_DOCKER_IMAGE_NAME}:latest
}

function kyopro_rm_docker(){
    containerid=$(docker ps | tail -n 1 | awk '{print $1}')
    docker kill ${containerid}
    containerid=$(docker ps -a | tail -n 1 | awk '{print $1}')
    docker rm ${containerid}
}