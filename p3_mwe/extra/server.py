from fastapi import FastAPI, Request
from simple_term_menu import TerminalMenu

try:
    import handelsplatz
except ImportError as e:
  print(f"Importing the shared library 'handelsplatz' did not work.")
  print(f"Is (a link to) the shared library 'handelsplatz.____.so' in the same directory as this python script?")
  print(f"The import caused the following exception '{e}'")
  print(f"Exiting")
  exit(1)

import os
import uvicorn
from handelsplatz import Nutzer, Angebot,Markt

markt = Markt()

rest_api= FastAPI()

@rest_api.get("/")
async def welcome():
    return{"nachricht":"Willkommen"}

@rest_api.get("/get_offers")
async def get_offers():
    return{"offers": "x"}

@rest_api.get('/nutzer/{benutzername}')
async def create_nutzer(benutzername: str, request: Request):
    # Speichere den Nutzer in der Map 
    passwort=request.headers.get('pw')
    erstellter_nutzer = markt.create_user(benutzername, passwort)
    markt.edit_user(benutzername, erstellter_nutzer)
    
    return {"message": f"Nutzer {benutzername} erfolgreich erstellt."}


@rest_api.get("/create_offer/{name}/{ware}/{menge}/{preis}")
async def create_offer(name: str,ware: str, menge: int, preis: float, request: Request):
    pw=request.headers.get('pw')
    if markt.auth(name, pw):
        paar = markt.create_offer(name,ware,menge,preis)
        n = markt.get_user(name)
        n.offer_einfügen(paar)
        markt.edit_user(name,n)
        return{"status":"Angebot erfolgreich erstelt"}
    else:
        return{"status": "Benutzername oder Passwort falsch"}


@rest_api.get('/size')
async def get_nutzer_size():
    return {"user_size": markt.get_size_user()}


@rest_api.get('/size_offer')
async def get_nutzer_size():
    return {"offer_size": markt.get_size_offers()}


@rest_api.get('/size_my_offer/{name}')
async def my_offer_size(name: str, request: Request):
    pw = request.headers.get('pw')
    if markt.auth(name, pw):
        n = markt.get_user(name)
        return {"my_offer_size" : n.get_my_offer_size()}
    else:
        return{"status": "Benutzername oder Passwort falsch"}
  