# uvicorn server:rest_api --port 8000 --reload
# cmake -S . -B build && cmake --build build && cmake --install build
# python3 -m uvicorn server:rest_api --port 8000 --reload

from handelsplatz import Nutzer,Angebot,Markt
from simple_term_menu import TerminalMenu
import requests

url="http://127.0.0.1:8000/"

handelsgueter = ["Bronze", "Silber", "Gold", "Diamant", "Rubin", "Saphir", "Smaragd", "Citrin", "Opal", "Amethyst"]

markt = Markt()

def login():
    l = TerminalMenu(["Einloggen", "Registrieren"],title="Login")
    auswahl = l.show()

    if auswahl == 0:
        benutzername = input("Gebe deinen Benutzernamen ein \n")
        passwort = input("Gebe dein Passwort ein \n")
        header= {'pw': passwort}

        resp=requests.get(url+f"authentification/{benutzername}", headers=header)
        resp_json=resp.json()
        success=resp_json["success"]

        while success=="false":
            benutzername=input("Benutzername oder Passwort falsch. Bitter versuches sie es erneut. \n Benutzername: ")
            passwort = input("Passwort: ")

            resp=requests.get(url+f"authentification/{benutzername}")
            resp_json=resp.json()
            success=resp_json["success"]
        

    if auswahl == 1:
        benutzername = input("Gebe deinen Benutzernamen ein \n")
        leer = " "

        while True:
            try:
                while leer in benutzername:
                    benutzername = input("Du darfst keine Leerzeichen im Benutzernamen eingeben. Gebe einen neuen Benutzernamen ein \n")
                break
            except:
                benutzername = input("Du darfst keine Leerzeichen im Benutzernamen eingeben. Gebe einen neuen Benutzernamen ein \n")
                break


        passwort = input("Gebe dein Passwort ein \n")

        while True:
            try:
                while leer in passwort:
                    passwort = input("Du darfst keine Leerzeichen im passwort eingeben. Gebe einen neuen passwort ein \n")
                break
            except:
                passwort = input("Du darfst keine Leerzeichen im passwort eingeben. Gebe einen neuen passwort ein \n")
                break
        
        header={"pw": passwort}

        r = requests.get(url + f"nutzer/{benutzername}", headers=header)
        pjson = r.json()
        if(pjson["message"]=="failed"):
            print("Der Benutzername ist bereits vergeben, möchten Sie sich einloggen?")
            login()
        print(pjson["message"])


        r2 = requests.get("http://127.0.0.1:8000/size")
        pjson2 = r2.json()
        print(pjson2["user_size"])



    def menu():
        m = TerminalMenu(["Profil","Markt ansehen"],title="Hauptmenü")
        auswahl = m.show()

        if auswahl == 0:
            def profil():
                p = TerminalMenu(["Kontostand einsehen","Inventar","Deine Angebote zeigen","zurück zum Hauptmenü"], title="Profil")
                auswahl = p.show()

                if auswahl == 0:
                    resp = requests.get(f"http://127.0.0.1:8000/get_berry/{benutzername}", headers=header)
                    pjson = resp.json()
                    print("In deinem Kontostand hast du: ", pjson["get_berry"], " Berry")
                    menu()                  

                if auswahl == 1:
                    resp = requests.get(f"http://127.0.0.1:8000/get_inventar/{benutzername}", headers=header)
                    pjson = resp.json()
                    print(pjson["get_inventar"])
                    menu()

                if auswahl == 2:
                    resp = requests.get(f"http://127.0.0.1:8000/get_my_offer/{benutzername}", headers=header)
                    pjson6 = resp.json()
                    print("\nID:              Ware:          Menge:       Preis:")
                    for v in pjson6['offers'].values():
                        print(v['ID'],":   ",v['Ware']+"       ", v['Menge'],"karat     ", v['Preis'], "Berry \n")

                    p2 = TerminalMenu(["zurück zum Profil"])
                    auswahl2 = p2.show()

                    if auswahl2 == 0:
                        profil()


                if auswahl == 3:
                    menu()

            profil()

        if auswahl == 1:
            def marktplatz():
                mp = TerminalMenu(["Angebot erstellen","Angebot löschen","Markt stöbern","Marktpreise","zurück zum Hauptmenü"], title="Marktplatz")
                auswahl = mp.show()

                if auswahl == 0:
                    resp = requests.get(f"http://127.0.0.1:8000/get_inventar/{benutzername}", headers=header)
                    pjson = resp.json()
                    print("Du hast folgende Waren in deinem Inventar:  ", pjson["get_inventar"], "\n Wähle eine Ware aus")
                    ware = input()

                    print("Wie viel ", ware, " möchtest du verkaufen?\n")
                    menge = input()
                    while True:
                        try:
                            menge = int(menge)
                            break
                        except ValueError:
                            menge = input("Das ging nicht. Gebe eine valide Anzahl ein\n")

                    print("Wie teuer soll 1x", ware, "sein? Währung: Berry \n")
                    preis = input()
                    while True:
                        try:
                            preis = float(preis)
                            break
                        except ValueError:
                            preis = input("Deine Eingabe muss einen Preis als Zahl darstellen\n")

                    print("Eingegebener Preis:", preis)

                    menge = int(menge)
                    preis = float(preis)

                    r3 = requests.get(url + f"create_offer/{benutzername}/{ware}/{menge}/{preis}", headers=header)
                    pjson3 = r3.json()
                    print(pjson3["status"])

                    r4 = requests.get("http://127.0.0.1:8000/size_offer")
                    pjson4 = r4.json()
                    print(pjson4["offer_size"])

                    r5 = requests.get(f"http://127.0.0.1:8000/size_my_offer/{benutzername}", headers=header)
                    pjson5 = r5.json()
                    print(pjson5["my_offer_size"])                        

                    menu()

                if auswahl == 1:
                    id = input("Gebe die ID der Ware an, die du löschen möchtest \n")
                    resp = requests.get(f"http://127.0.0.1:8000/delete_my_offer/{benutzername}/{id}", headers=header)
                    pjson7 = resp.json()
                    print(pjson7["status"])

                    r4 = requests.get("http://127.0.0.1:8000/size_offer")
                    pjson4 = r4.json()
                    print(pjson4["offer_size"])

                    r5 = requests.get(f"http://127.0.0.1:8000/size_my_offer/{benutzername}", headers=header)
                    pjson5 = r5.json()
                    print(pjson5["my_offer_size"])

                    menu()   

                if auswahl == 2:
                    resp = requests.get(url + "get_offers")
                    resp_json=resp.json()
                    print("ID           Ware          Menge     Preis")
                    for v in resp_json['offers'].values():
                        print("\n", v['ID'],":   ",v['Ware']+"       ", v['Menge'],"kt     ", v['Preis'], "B \n")

                    menu()


                if auswahl == 3:
                    def submenu():
                        submenu_list = handelsgueter.copy()
                        submenu_list.append("Zurück zum Marktplatz")
                        submenu_menu = TerminalMenu(submenu_list, title="Markt stöbern")
                        submenu_choice = submenu_menu.show()

                        if submenu_choice == len(handelsgueter):
                            marktplatz()
                        else:
                            handelsgut = submenu_list[submenu_choice]
                            resp = requests.get(url + f"preise/{handelsgut}")
                            pjson = resp.json()
                            print(f"Preis für {handelsgut}: {pjson['preis']} Berry")
                            submenu()
                    submenu()

                if auswahl == 4:
                    menu()

            marktplatz()
    menu() 
login()
