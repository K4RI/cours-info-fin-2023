# pour résoudre le dernier exercice du 2

FROM openclassrooms/build_image

# CMD ["cat", "test.sh"]

RUN echo "deb http://archive.debian.org/debian/ stretch main" > /etc/apt/sources.list
RUN echo "deb-src http://archive.debian.org/debian/ stretch main" >> /etc/apt/sources.list

RUN apt-get update
RUN apt-get upgrade -y
RUN apt-get install nginx -y