# application minimale Flask sur Docker
# https://github.com/docker/awesome-compose/tree/master/flask/app

FROM python:3.7.3-slim

RUN python -m pip install 'Flask==2.0.2'
COPY . .
ENV FLASK_APP=hello.py
# EXPOSE 5000

CMD [ "python3", "-m" , "flask", "run", "--host=0.0.0.0"]

# docker run -p 5000:5000 flask-mwe