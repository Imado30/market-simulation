#uvicorn server:rest_api --port 8000 --reload
#cmake -S . -B build && cmake --build build && cmake --install build

import requests

url="http://127.0.0.1:8000/"
header={"pw":"1234"}
benutzername="abc"


test = requests.get(url+f"nutzer/{benutzername}", headers=header)
pjson = test.json()

print(pjson["message"])


test2 = requests.get("http://127.0.0.1:8000/size")
pjson2 = test2.json()

print(pjson2["user_size"])


requests.get(url+f"create_offer/{benutzername}", headers=header)