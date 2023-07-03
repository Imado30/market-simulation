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

            std::pair<int,Angebot> create_offer(std::string name, std::string ware, int menge, double preis);
            void delete_offer(int id);
            void accept_offer(std::string name, int id);

            //Funktionen zum Handeln mit dem Markt 
            void sell(std::string name, std::string ware, int menge);
            void buy(std::string name, std::string ware, int menge);

            void add_offer_ids();

            Nutzer create_user(std::string name, std::string pw);
            void edit_user(std::string name, Nutzer n);
            bool auth(std::string name, std::string pw);

            void kursverlauf_berechnen(std::string handelsgut);
            void update_all();

            std::map<int, Angebot> get_offers();   
            int get_preis(std::string key);
            int get_size_user();
            int get_size_offers();
            Nutzer get_owner(int id);
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