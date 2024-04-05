import redis
from flask import Flask

app = Flask(__name__)
cache = redis.Redis(host="redis", port=6379)


@app.route('/')
def index():
    cache.incr('test')
    return "<p>hello : " + str(cache.get('test'),'utf-8') + "</p>"

if __name__ == '__main__':
	app.run()