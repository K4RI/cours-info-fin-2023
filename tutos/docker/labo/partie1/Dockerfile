FROM alpine:3.14
RUN apk add --update npm

# FROM ubuntu
# RUN apt-get update -yq \
# && apt-get install curl gnupg -yq \
# && curl -sL https://deb.nodesource.com/setup_20.x | bash \
# && apt-get install nodejs -yq \
# && apt-get clean -y

# ADD . /app/
WORKDIR /app
COPY . .
RUN npm install

EXPOSE 2368
VOLUME /app/logs

CMD npm run start


# FROM ubuntu
# RUN mkdir /myvol
# RUN echo "hello world" > /myvol/greeting
# VOLUME /myvol