#!/bin/bash

SCRIPT_DIR=$(cd $(dirname $0); pwd)
docker run -p 8888:8888 -v ${SCRIPT_DIR}/:/home/jovyan/work/ jupyter/datascience-notebook &
