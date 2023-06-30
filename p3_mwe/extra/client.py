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
    l = TerminalMenu(["Einloggen"],title="Login")
    auswahl = l.show()

    if auswahl == 0:
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
        print(pjson["message"])


        r2 = requests.get("http://127.0.0.1:8000/size")
        pjson2 = r2.json()
        print(pjson2["user_size"])


        n = Nutzer(benutzername, passwort)
        a = {}
        o = Angebot("gold",7,10)
        a["12345"] = o
        n.add("Citrine",6)

        def menu():
            m = TerminalMenu(["Profil","Markt ansehen"],title="Hauptmenü")
            auswahl = m.show()

            if auswahl == 0:
                def profil():
                    p = TerminalMenu(["Kontostand einsehen","Inventar","Deine Angebote zeigen","zurück zum Hauptmenü"], title="Profil")
                    auswahl = p.show()

                    if auswahl == 2:
                        print("\n Deine Angebote: ")
                        for k,v in a.items():
                            print(k, " : ",v.get_warentyp(), v.get_anzahl(), v.get_preis())
                        p2 = TerminalMenu(["zurück zum Profil"])
                        auswahl2 = p2.show()

                        if auswahl2 == 0:
                            profil()


                    if auswahl == 3:
                        menu()

                profil()

            if auswahl == 1:
                def marktplatz():
                    mp = TerminalMenu(["Angebot erstellen","Angebot löschen","Markt stöbern","Ware verkaufen","zurück zum Hauptmenü"], title="Marktplatz")
                    auswahl = mp.show()

                    if auswahl == 0:
                        print("Du hast folgende Waren in deinem Inventar:  ", n.get_inventar(), "\n Wähle eine Ware aus")
                        ware = input()
                        while True:
                            try:
                                while ware not in n.get_inventar():
                                    print("Die Ware ist nicht in deinem Inventar. Gebe eine Ware an die du besitzt \n")
                                    ware = input()
                                break
                            except:
                                ware = input("Die Ware ist nicht in deinem Inventar. Gebe eine Ware an die du besitzt \n")

                        print("Wie viel ", ware, " möchtest du verkaufen?")
                        menge = input()
                        while True:
                            try:
                                while n.get_menge(ware) < int(menge) or int(menge) < 1:
                                    print("Das ging nicht. Gebe eine valide Anzahl ein")
                                    menge = int(input())
                                break
                            except:
                                menge = input("Das ging nicht. Gebe eine valide Anzahl ein")

                        print("Wie teuer soll 1x", ware, "sein? Währung: Berry")
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

                    if auswahl == 4:
                        menu()

                marktplatz()
        menu()
            
login()
