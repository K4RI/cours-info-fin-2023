import os
import time

import redis
from flask import Flask

app = Flask(__name__)

var_env = os.environ.get('starwars')

def print_redis_error_and_exit():
    print(
        "INTERNAL ERROR: Redis can't be reached.. Are you sure Redis is up and running ?"
    )
    exit(1)


def test_redis_connection():
    cache = redis.Redis(host="redis", port=6379)
    try:
        cache.incr("test")
    except redis.exceptions.ConnectionError as exc:
        print_redis_error_and_exit()
    return cache

cache = test_redis_connection()
if var_env:
    print('Que la force soit avec toi !')
else:
    print("Docker-compose c'est pratique !")

@app.route('/')
def index():
    return 'hello'

if __name__ == '__main__':
    app.run()