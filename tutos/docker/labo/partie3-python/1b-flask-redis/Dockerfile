# application minimale Flask sur Docker, avec Redis
# https://github.com/docker/awesome-compose/tree/master/flask-redis

FROM python:3.7.3-slim

RUN python -m pip install 'Flask==2.0.2' 'redis==3.5.3'
COPY . .
ENV FLASK_APP=hello.py

CMD [ "python3", "-m" , "flask", "run", "--host=0.0.0.0"]