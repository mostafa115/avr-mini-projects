FROM debian:bookworm-slim

RUN apt-get update \
 && apt-get install -y --no-install-recommends gcc-avr avr-libc binutils-avr make \
 && rm -rf /var/lib/apt/lists/*

WORKDIR /src
COPY . .

CMD ["make"]
