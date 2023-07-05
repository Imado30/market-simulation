#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include "../include/Nutzer.hpp"
#include "../include/Angebot.hpp"

namespace Handelsplatz{

    class Markt{
        public:

            Markt();

            /**
             * @brief erstellt Angebot, speichert dieses in einem Paar. Paar wird sowohl in offers im Markt, als auch in my_offers im Nutzer
             * 
             * @param name   Benutzername des Erstellers
             * @param ware   zu verkaufendes Handelsgut
             * @param menge  Menge des zum Verkauf stehenden Handelsguts
             * @param preis  Preis für ein Karat des handelsguts
             * @return std::pair<int,Angebot> 
             */
            std::pair<int,Angebot> create_offer(std::string name, std::string ware, int menge, double preis);

            /**
             * @brief das Offer, das unter der übergenen ID gespeichert ist, wird gelöscht
             * 
             * @param id 
             */
            void delete_offer(int id);

            /**
             * @brief Angebot unter übergebener ID wird angenommen
             * 
             * @param name Benutzername des Users, der das ANgebot annimmt
             * @param id Id des angenommenen Angebots
             */
            void accept_offer(std::string name, int id);

            /**
             * @brief verkauft Ware direkt an den Marktplatz, Preis entspricht synthetisch generiertem Preis - 10% Gebühr
             * 
             * @param name Benutzername des Users, der verkauft
             * @param ware Handelsgut, das verkauft wird 
             * @param menge zu verkaufende Stückzahl
             * @return * void 
             */
            void sell(std::string name, std::string ware, int menge);

            /**
             * @brief kauft Güter direkt vom Marktplatz, Preis entspricht synthetisch generiertem Preis + 10% Gebühr
             * 
             * @param name Benutzername, des Käufers
             * @param ware Handelsgut, das erworben wird
             * @param menge zu kaufende Stückzahl
             */
            void buy(std::string name, std::string ware, int menge);

            /**
             * @brief Hilfsfunktion, die neue Offer-IDs erstellt, sofern kein Offer-Ids mehr verfügbar sind
             * 
             */
            void add_offer_ids();

            /**
             * @brief Create a user object, wird im Markt gespeichert
             * 
             * @param name Benutzername
             * @param pw Passwort
             * @return Nutzer 
             */
            Nutzer create_user(std::string name, std::string pw);

            /**
             * @brief Hilfsfunktion, dient der Speicherung von Nutzern, die von Requests bearbeitet werden
             * 
             * @param name Benutzername, des bearbeiteten Nutzers
             * @param n bearbeitetes Nutzerobjekt
             */
            void edit_user(std::string name, Nutzer n);

            /**
             * @brief Authentifizierungsfunktion, überprüft ob übergebenes Passwort mit dem Passwort des Nutzers übereinstimmt
             * 
             * @param name 
             * @param pw 
             * @return true wenn übergenes Passwort mit dem Passwort des Nutzers übereinstimmt
             * @return false sonst
             */
            bool auth(std::string name, std::string pw);

            /**
             * @brief berechnet synthetischen Marktpreis nach vorgegebener Formel
             * 
             * @param handelsgut Ware, deren Preis berechnet werden soll
             */
            void kursverlauf_berechnen(std::string handelsgut);

            /**
             * @brief aktualisiert Preise aller Handelsgüter
             * 
             */
            void update_all();

            /**
             * @brief Get the offers object
             * 
             * @return std::map<int, Angebot> 
             */
            std::map<int, Angebot> get_offers();  

            /**
             * @brief Get the preis object
             * 
             * @param key 
             * @return * int 
             */
            int get_preis(std::string key);

            /**
             * @brief Get the size user object
             * 
             * @return int 
             */
            int get_size_user();

            /**
             * @brief Get the size offers object
             * 
             * @return int 
             */
            int get_size_offers();

            /**
             * @brief Get the owner object
             * 
             * @param id 
             * @return Nutzer 
             */
            Nutzer get_owner(int id);

            /**
             * @brief Get the user object
             * 
             * @param name 
             * @return Nutzer 
             */
            Nutzer get_user(std::string name);


        private:
            /**
             * @brief speichert die Nutzer mit key: Benutzername, value: zugehöriges Nutzerobjekt
             * 
             */
            std::map<std::string, Nutzer> user;

            /**
             * @brief speichert die Angebote mit Key: ID des Angebots, value: zugehöriges Angebot (Gedanke ist, dass das Speichern mit ID das Löschen vereinfacht)
             * 
             */
            std::map<int, Angebot> offers;

            std::map<int, Nutzer> owner;

            std::queue<int> offer_ids;

            int max_o_id;

            std::vector<std::string> handelsgueter = {"Bronze", "Silber", "Gold", "Diamant", "Rubin", "Saphir", "Smaragd", "Citrin", "Opal", "Amethyst"};

            std::map<std::string, double> preise = 
            {
            {"Bronze", 5000},
            {"Silber", 5000},
            {"Gold", 5000},
            {"Diamant", 5000},
            {"Rubin", 5000},
            {"Saphir", 5000},
            {"Smaragd", 5000},
            {"Citrin", 5000},
            {"Opal", 5000},
            {"Amethyst", 5000},
            };
};
}