from fastapi import FastAPI, Query

app = FastAPI()

@app.get('/api/hello')
def hello_world():
    return {'Hello':'World'}