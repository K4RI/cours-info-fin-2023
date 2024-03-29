FROM python:3.7.3-slim

COPY . .
# RUN python -m pip install --upgrade pip
RUN python -m pip install -r requirements.txt
# WORKDIR /app
ENV FLASK_APP=main.py

CMD ["python", "-u", "main.py"]