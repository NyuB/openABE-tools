#!/bin/bash
VERSION=$1
if [[ $VERSION = "" ]]; then
    echo "[!] Missing version as argument"
    exit 0
fi

GTEST_VERSION=googletest-release-${VERSION}.zip
#Corrected link
GTEST_LINK=https://codeload.github.com/google/googletest/zip/refs/tags/release-${VERSION}

if [[ ! -f ${GTEST_VERSION} ]]; then
    wget -O ${GTEST_VERSION} ${GTEST_LINK} --no-check-certificate # accept old github certificate
fi