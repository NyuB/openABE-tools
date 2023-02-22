FROM debian:bullseye-slim
WORKDIR /oabe
COPY --from=nyub:openabe-dev /usr/local/bin/oabe_* /usr/bin/
COPY --from=nyub:openabe-dev /usr/local/lib/librelic*.so /usr/lib/

ENTRYPOINT ["/bin/bash", "-c"]
