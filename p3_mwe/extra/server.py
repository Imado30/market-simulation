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

handelsgueter = ["Bronze", "Silber", "Gold", "Diamant", "Rubin", "Saphir", "Smaragd", "Citrin", "Opal", "Amethyst"]

@rest_api.get("/")
async def welcome():
    return{"nachricht":"Willkommen"}


@rest_api.get('/nutzer/{benutzername}')
async def create_nutzer(benutzername: str, request: Request):
    # Speichere den Nutzer in der Map 
    try:
        passwort=request.headers.get('pw')
        erstellter_nutzer = markt.create_user(benutzername, passwort)
        markt.edit_user(benutzername, erstellter_nutzer)
        
        return {"message": f"Nutzer {benutzername} erfolgreich erstellt."}
    except:
        return{"message": "failed"}


@rest_api.get("/create_offer/{name}/{ware}/{menge}/{preis}")
async def create_offer(name: str,ware: str, menge: int, preis: float, request: Request):
    pw=request.headers.get('pw')
    if markt.auth(name, pw):
        n = markt.get_user(name)
        if ware not in n.get_inventar():
            return{"status" : "Du hast die Ware nicht im Inventar"}
        elif n.get_menge() < menge or menge < 1:
            return{"status" : "Das ging nicht. Gebe eine valide Anzahl ein"}
        else:
            paar = markt.create_offer(name,ware,menge,preis)
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


@rest_api.get('/get_my_offer/{name}')
async def get_my_offer(name: str, request: Request):
    pw = request.headers.get('pw')
    if markt.auth(name, pw):
        n = markt.get_user(name)
        mo = n.get_my_offer()
        out={}
        for k,v in mo.items():
            a={ 'ID': k,
                'Preis':v.get_preis(),
                'Menge': v.get_anzahl(),
                'Ware': v.get_warentyp()}

            out[k]=a
        return{"offers": out}
    else:
        return{"status": "Benutzername oder Passwort falsch"}


@rest_api.get('/delete_my_offer/{name}/{id}')
async def delete_my_offer(name: str, id: int, request: Request):
    pw = request.headers.get('pw')
    if markt.auth(name, pw):
        n = markt.get_user(name)
        if id not in n.get_my_offer():
            return {"status" : "Du hast kein Angebot mit dieser ID erstellt"}
        else:
            n.add_for_delete(id)
            n.remove_my_offer(id)
            markt.delete_offer(id)
            markt.edit_user(name,n)
            return {"status" : "Successfully removed"}
    else:
        return{"status": "Benutzername oder Passwort falsch"}
    

@rest_api.get('/get_berry/{name}')
async def get_berry(name: str, request: Request):
    pw = request.headers.get('pw')
    if markt.auth(name, pw):
        n = markt.get_user(name)
        markt.edit_user(name,n)
        return {"get_berry" : n.get_berry()}
    else:
        return{"status": "Benutzername oder Passwort falsch"}
    

@rest_api.get('/get_inventar/{name}')
async def get_inventar(name: str, request: Request):
    pw = request.headers.get('pw')
    if markt.auth(name, pw):
        n = markt.get_user(name)
        markt.edit_user(name,n)
        mo = n.get_inventar()
        out={}
        for k,v in mo.items():
            a={ 'Ware': k,'Menge': v}
            out=a
        return{"get_inventar": out}
    else:
        return{"status": "Benutzername oder Passwort falsch"}
    

@rest_api.get('/authentification/{username}')
async def authentification(username: str, request: Request):
    pw= request.headers.get('pw')
    try:
        if markt.auth(username, pw):
            return{"success": "true"}
        else:
            return {"success": "false"}
    
    except:
        return{"success": "false"}


@rest_api.get("/preisberechnung/{handelsgut}")
async def get_preis(handelsgut: str):
    if handelsgut not in handelsgueter:
        print("Dieses Gut ist momentan leider nicht verfügbar. Wir danken für Ihr Verständnis")
    
    markt.kursverlauf_berechnen(handelsgut)   
        
    return {"preis": markt.get_preis(handelsgut)}


@rest_api.get("/preise/{handelsgut}")
async def get_preis(handelsgut: str):
    if handelsgut not in handelsgueter:
        print("Dieses Gut ist momentan leider nicht verfügbar. Wir danken für Ihr Verständnis")
        
    return {"preis": markt.get_preis(handelsgut)}


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


@rest_api.get("/buy/{name}/{ware}/{menge}")
async def buy(name: str, ware: str, menge: int, request: Request):
    pw= request.headers.get('pw')
    if markt.auth(name, pw):
        try:
            markt.buy(name, ware, menge)
            return{"status": "Die Transaktion war erfolgreich. Vielen Dank für Ihren Einkauf"}
        except:
            return {"status":"Bei der Transaktion ist etwas schiefgelaufen. Bitte prüfen Sie ob Ihr Konto gedeckt ist."}
    
    else:
        return{"status": "Benutzername oder Passwort falsch"}
