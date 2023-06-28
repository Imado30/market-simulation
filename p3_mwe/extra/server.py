from fastapi import FastAPI, Request
import os
import uvicorn
import handelsplatz

from handelsplatz import Markt, Nutzer, Angebot

markt=Markt()

rest_api=FastAPI()

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


@rest_api.get('/size')
async def get_nutzer_size():
    return {"user_size": markt.get_size_user()}

@rest_api.get("/create_offer/{name}")
async def create_offer(name: str, request: Request):
    pw=request.headers.get('pw')
    if markt.auth(name, pw):
        return{"status":"Angebot erfolgreich erstelt"}
    else:
        return{"status": "Benutzername oder Passwort falsch"}