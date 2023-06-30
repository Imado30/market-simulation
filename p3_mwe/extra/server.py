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
    o=markt.get_offers()
    out={}
    for k,v in o.items():
        a={ 'ID': k,
            'Preis':v.get_preis(),
            'Menge': v.get_anzahl(),
            'Ware': v.get_warentyp()}

        out[k]=a
    return{"offers": out}

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


@rest_api.get('/size_my_offer/{name}')
async def my_offer_size(name: str, request: Request):
    pw = request.headers.get('pw')
    if markt.auth(name, pw):
        n = markt.get_user(name)
        return {"my_offer_size" : n.get_my_offer_size()}
    else:
        return{"status": "Benutzername oder Passwort falsch"}


@rest_api.get('/size_offer')
async def get_nutzer_size():
    return {"offer_size": markt.get_size_offers()}

@rest_api.get('/authentification/{username}')
async def authentification(username: str, request: Request):
    pw= request.headers.get('pw')
    if markt.auth(username, pw):
        return{"success": "true"}
    else:
        return {"success": "false"}
