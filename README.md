# openABE-tools
## Overview
Containers and utilities to ease integrate the openABE library in various systems.
OpenABE is an attribute-based-encryption C++ library and a command-line tool, developped for research purposes.
Installing from source can be tedious, the goal of this repository is to offer docker images to use the openabe tool directly or provide a development environment.

Original source code : https://github.com/zeutro/openabe

## Building the images
The base image is located in `images/openabe-dev`. 
Once builded, it can be used as a compile/development environment for projects requiring the openabe libraries. The project located at `images/openabe-dev/tests` is a minimal sample of such project. It is compiled and run during the CI build in the "Test openabe-dev" step in **build-image.yml**. Refer to the [openabe api documentation](https://github.com/zeutro/openabe/blob/master/docs/libopenabe-v1.0.0-api-doc.pdf) for more info on how to program with the openabe library.

A more restricted image containing only the binaries distributed with openabe (**oabe_setup**, **oabe_enc**_ **oabe_dec**, **oabe_keygen**) can be build in `images/openabe-tool`. It is based on the openabe-dev image and currently requires it to be tagged nyub:openabe-dev (you can also change the Dockerfile to suit whatever tag you might use). Refer to the [openabe cli documentation](https://github.com/zeutro/openabe/blob/master/docs/libopenabe-v1.0.0-cli-doc.pdf) for more information on the usage of these tools.
