#uvicorn server:rest_api --port 8000 --reload
#cmake -S . -B build && cmake --build build && cmake --install build

import requests

url="http://127.0.0.1:8000/"
header={"pw":"1234"}

