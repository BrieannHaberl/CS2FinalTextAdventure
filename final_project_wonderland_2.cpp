#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

void print(vector<string> bag) {
    for (int i = 0; i < bag.size(); i++)
        cout << bag.at(i) << ' ';
}

void look(string currloc, map<string, vector<string>> exits, map<string, vector<string>> itemlocs, map<string, string> descriptions) {
    string outexits = "";
    string outitems = "";
    vector<string> exitstrs = exits.at(currloc);
    vector<string> itemstrs = itemlocs.at(currloc);


    for (string s : exitstrs) {
        outexits += s + ", ";
    }
    outexits = outexits.substr(0, outexits.size() - 2);
    outexits += ".";

    for (string s : itemstrs) {
        outitems += s + ", ";
    }
    outitems = outitems.substr(0, outitems.size() - 2);
    outitems += ".";

    cout << "You are currenty at: " << currloc << endl;
    cout << descriptions[currloc] << endl;
    cout << "Exits: " << outexits << endl;
   // cout << "You see the following items: " << outitems << endl;

    if (currloc == "Forest") {
        cout << "NPC: Cheshire Cat" << endl;
    }
    if (currloc == "Garden") {
        cout << "NPC: Mad Hatter" << endl;
    }
    if (currloc == "Castle") {
        cout << "NPC: Red Queen" << endl;
    }
    if (currloc == "Park") {
        cout << "NPC: White Rabbit" << endl;
    }
    if (currloc == "Fountain") {
        cout << "NPC: White Queen" << endl;
    }
    
}

int main() {

    vector<string> locations{"Entrance", "Forest", "Heart Door", "Spade Door", "Clover Door", "Diamond Door", "Garden", "Park", "Castle", "Fountain", "Town Square"};


    map<string, string> descriptions = {

        { "Entrance", "You appear to be at the entrance of a forest. There are 4 colorful doors and what looks to be a town square." },
        { "Forest", "You are in a forest. There are trees..." },
        { "Heart Door", "In front of you is a bright red door with a heart in its center." },
        { "Spade Door", "In front of you is a bright blue door with a spade in its center." },
        { "Clover Door", "In front of you is a bright green door with a clover in its center." },
        { "Diamond Door", "In front of you is a bright yellow door with a diamond in its center." },
        { "Garden", "In front of you is a very large garden." },
        { "Park", "There is a small park in front of you." },
        { "Castle", "The castle is red and black." },
        { "Fountain", "There is a fountain in the center of town square" },
        { "Town Square", "This is town square." },
    };

    map<string, vector<string>> exits = {

        { "Entrance", { "Forest", "Heart Door", "Spade Door", "Clover Door", "Diamond Door", "Castle", "Town Square" } },
        { "Forest", { "Entrance" }  },
        { "Heart Door", { "Entrance" } },
        { "Spade Door", { "Entrance" } },
        { "Clover Door", { "Entrance" } },
        { "Diamond Door", { "Entrance" } },
        { "Garden", { "Town Square" } },
        { "Park", { "Town Square" } },
        { "Castle", { "Town Square" } },
        { "Fountain", { "Town Square" } },
        { "Town Square", { "Entrance", "Fountain", "Garden", "Park", "Castle" } },
    };

    map<string, vector<string>> itemlocs = {

        { "Entrance", {  } },
        { "Forest", {  }  },
        { "Heart Door", {  } },
        { "Spade Door", {  } },
        { "Clover Door", {  } },
        { "Diamond Door", {  } },
        { "Garden", { "teacup" } },
        { "Park", {  } },
        { "Castle", {  } },
        { "Fountain", { "pocket watch" } },
        { "Town Square", {  } },

    };


    vector<string> items;

    auto iter = exits.begin();
    while (iter != exits.end()) {
        cout << "[" << iter->first << ", { ";
        vector<string> temp = iter->second;
        for (string s : temp) {
            cout << s << ", ";
        }
        cout << "} ]" << endl;
        iter++;
    }

   // vector<string> bag{};
    vector<string> bag = { "~pocket watch", "~teacup" };  // this is a bag test starting inventory
    const char* art =
        R"(
            _   _   _   _   _   _   _       _   _  
           / \ / \ / \ / \ / \ / \ / \     / \ / \ 
          ( W | e | l | c | o | m | e )   ( t | o )
           \_/ \_/ \_/ \_/ \_/ \_/ \_/     \_/ \_/ 
,--.   ,--.                  ,--.              ,--.                   ,--. 
|  |   |  | ,---. ,--,--,  ,-|  | ,---. ,--.--.|  | ,--,--.,--,--,  ,-|  | 
|  |.'.|  || .-. ||      \' .-. || .-. :|  .--'|  |' ,-.  ||      \' .-. | 
|   ,'.   |' '-' '|  ||  |\ `-' |\   --.|  |   |  |\ '-'  ||  ||  |\ `-' | 
'--'   '--' `---' `--''--' `---'  `----'`--'   `--' `--`--'`--''--' `---'  
                                                                           
                      /|      __
*             +      / |   ,-~ /             +
     .              Y :|  //  /                .         *
         .          | jj /( .^     *
               *    >-"~"-v"              .        *        .
*                  /       Y
   .     .        jo  o    |     .            +
                 ( ~T~     j                     +     .
      +           >._-' _./         +
               /| ;-"~ _  l
  .           / l/ ,-"~    \     +
              \//\/      .- \
       +       Y        /    Y
               l       I     !
               ]\      _\    /"\
              (" ~----( ~   Y.  )
          ~~~~~~~~~~~~~~~~~~~~~~~~~~
                                                      )";

   const char* note =
       R"( 
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
|        Welcome to Wonderland       |
 \                                    \
 |                                    |
 |        Find the four keys.         /
 /      -----------------------      |
 \        Open the four doors.       |
 /      -----------------------      \
|         Find the fifth door.        |
|       -----------------------      |
\           W a k e   u p             \
 \                                    |
  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

 )";

   const char* art2 =
       R"(
                                                   ,---.,---.,---. 
,--.   ,--.                 ,--.   ,--.,--.        |   ||   ||   | 
 \  `.'  /,---. ,--.,--.    |  |   |  |`--',--,--, |  .'|  .'|  .' 
  '.    /| .-. ||  ||  |    |  |.'.|  |,--.|      \|  | |  | |  |  
    |  | ' '-' ''  ''  '    |   ,'.   ||  ||  ||  |`--' `--' `--'  
    `--'  `---'  `----'     '--'   '--'`--'`--''--'.--. .--. .--.  
                                                   '--' '--' '--'                                
                               .------.                                             
            .------.           |A .   |      
            |A_  _ |    .------; / \  |   
            |( \/ )|-----. _   |(_,_) |   
            | \  / | /\  |( )  |  I  A|                                             
            |  \/ A|/  \ |_x_) |------'                                             
            `-----+'\  / | Y  A|                                
                  |  \/ A|-----'                                                    
                  `------'       

)";
   cout << art << endl;

   string go_to = "go to";
   int comm_goto = -1;
   string changeto = "";
   string command = "";
   string locationItems = "";
   string locationDis = "";
   string locationExits = "";
   string location = "Entrance";
   look(location, exits, itemlocs, descriptions );

   cout << "Type the word 'commands' to get started" << endl;
   while (true)
   {
       command.clear();
       cout << "command? ";
       getline(cin, command);
       cout << endl;
       comm_goto = command.find(go_to);
       if (comm_goto == 0) {
           changeto = command.substr(6, command.size());
           if (changeto == location) {
               cout << "You are already there." << endl;
               cout << endl;
               continue;
           }
           if (find(locations.begin(), locations.end(), changeto) != locations.end()) {
               // add check to see if the person can get to where they typed from their current location
               vector<string> exitcheck = exits[location];
               if (find(exitcheck.begin(), exitcheck.end(), changeto) != exitcheck.end()) {
                   location = changeto;
               }
               else {
                   cout << "You can't reach " << changeto << " from here." << endl;
                   cout << endl;
               }
           }
           else {
               cout << "Invalid location." << endl;
               cout << endl;
               continue;
           }
       }

       if (command == "commands") {
           cout << "Commands: look, items, go to, talk to, info" << endl;
       }
       if (command == "look") {
           look(location, exits, itemlocs, descriptions);
           cout << endl;
       }


       if (command == "take teacup") {
           string item = "teacup";
           vector<string> itemp = itemlocs[location];
           if (find(itemp.begin(), itemp.end(), item) != itemp.end()) {
               std::vector<string>::iterator it;
               it = find(itemp.begin(), itemp.end(), item);
               itemlocs[location].erase(it);
           }
           bag.push_back("~teacup");
       }
       if (command == "take pocket watch") {
           string item = "pocket watch";
           vector<string> itemp = itemlocs[location];
           if (find(itemp.begin(), itemp.end(), item) != itemp.end()) {
               std::vector<string>::iterator it;
               it = find(itemp.begin(), itemp.end(), item);
               itemlocs[location].erase(it);
           }
           bag.push_back("~pocket watch");
       }
       if (command == "items") {
           print(bag);
           cout << endl;
       }
       if (command == "info") {
           cout << note << endl;
       }


       if (command == "talk to White Rabbit") {
           string answer;
           cout << "White Rabbit: I am going to be late!" << endl;
           for (int i = 0; i < bag.size(); i++) {

               if (bag[i] == "~diamond") {
                   cout << "White Rabbit: Thank you for finding my pocket watch!" << endl;

               }



               for (int i = 0; i < bag.size(); i++) {

                   if (bag[i] == "~pocket watch") {
                       cout << "White Rabbit: I lost my pocket watch!" << endl;
                       cout << "Give the White Rabbit the pocket watch? yes/no" << endl;
                       cin >> answer;
                       if (answer == "yes") {
                           bag.erase(bag.begin() + i);
                           cout << "White Rabbit: You found my pocket watch here you can have this key!" << endl;
                           cout << "The White Rabbit gave you a bright yellow key with a diamond on it" << endl;
                           bag.push_back("~diamond");
                           bag.push_back("key");
                       }
                       if (answer == "no") {
                           cout << "You didn't give the pocket watch to the rabbit..." << endl;
                       }
                   }
               }
           }
       }
       if (command == "talk to Red Queen") {
           string answer1;
           string answer2;
           string answer3;
           cout << "Red Queen: Do you need something? yes/no" << endl;
           cin >> answer1;
           if (answer1 == "yes") {
               cout << "What do you want...?" << endl;
               cout << "option1: To play croquet" << endl;
               cout << "option2: I am looking for a key" << endl;
               cout << "option3: I want a flying pig" << endl;
               cin >> answer2;
               if (answer2 == "1") {
                   cout << "Red Queen: Now is not the time to play croquet" << endl;


               }
               if (answer2 == "2") {
                   cout << "Red Queen: I would fancy a hat..." << endl;
                   for (int i = 0; i < bag.size(); i++) {

                       if (bag[i] == "~hat") {

                           cout << "Do you want to give the hat to the Red Queen? yes/no" << endl;
                           cin >> answer3;
                           if (answer3 == "yes") {
                               bag.erase(bag.begin() + i);
                               cout << "Red Queen: Thanks for the hat. Here you can take this key I don't need it." << endl;
                               cout << "You have obtained the red heart key" << endl;
                               bag.push_back("~heart");
                               bag.push_back("key");

                           }
                           if (answer3 == "no") {
                               cout << "You decided not to give her the hat." << endl;
                           }
                       }
                   }
               }
               if (answer2 == "3") {
                   cout << "Red Queen: Don't we all... " << endl;


               }
               if (answer1 == "no") {
                   cout << "Red Queen: Well why are you here then? If you don't need anything then leave." << endl;
               }
           }
       }
       if (command == "talk to White Queen") {
           string answer;
           cout << "White Queen: ..." << endl;
           for (int i = 0; i < bag.size(); i++) {

               if (bag[i] == "~teacup") {

                   cout << "Give teacup to White Queen? yes/no" << endl;
                   cin >> answer;
                   if (answer == "yes") {
                       bag.erase(bag.begin() + i);
                       cout << "White Queen: Thank you..." << endl;
                       cout << "The White Queen silently handed you a bright blue key with a spade symbol on it." << endl;
                       bag.push_back("~spade");
                       bag.push_back("key");
                   }
                   if (answer == "no") {
                       cout << "You did not give her the teacup" << endl;
                   }
               }
           }
       }

       if (command == "talk to Mad Hatter") {
           string answer1;
           string answer2;    
           cout << "Mad Hatter: Do you like hats? yes/no" << endl;
               cin >> answer1;
               if (answer1 == "yes") {
                   cout << "Mad Hatter: Did the queen send you? yes/no" << endl;
                   cin >> answer2;

                   if (answer2 == "yes") {
                       cout << "Mad Hatter: She doesn't deserve a hat." << endl;
                   }
                   if (answer2 == "no") {
                        cout << "Mad Hatter: Here have a hat then." << endl;
                        cout << "The Mad Hatter gave you a hat." << endl;
                        bag.push_back("~hat");
                           
                       
                   }
               }
               if (answer1 == "no") {
                   cout << "Whats wrong with you..." << endl;
               }
           
       }
   
       if (command == "talk to Cheshire Cat") {
           string answer1;
           string answer2;
           cout << "Cheshire Cat: Hello there you look a little lost." << endl;
           cout << "option1: I am lost" << endl;
           cout << "option2: You are a talking cat..." << endl;
           cin >> answer1;
           if (answer1 == "1") {
               cout << "Cheshire Cat: If you don't know where you are going any road will take you there." << endl;
               cout << "option1: I want to go home!" << endl;
               cout << "option2: I must be going crazy..." << endl;
               cin >> answer2; 
               if (answer2 == "1") {
                   cout << "Cheshire Cat: Collect the keys and the path will open to go home. Good luck" << endl;
                   cout << "The Cheshire Cat handed you a bright green key with a clover on it." << endl;
                   bag.push_back("~clover");
                   bag.push_back("key");
               }
               if (answer2 == "2") {
                   cout << "Cheshire Cat: We are all mad here." << endl;
                   
               }
           }
           if (answer1 == "2") {
               cout << "Cheshire Cat: Your point is...?" << endl;
              
           }
       }
       if (bag.size() == 8) {
           cout << "You have collected all 4 keys. After opening the four doors you hear the sound of something falling in the forest" << endl;
           cout << "Investigating the sound in the forest you see another door with clouds and stars on it" << endl;
           cout << "The door is a shimmering gold and silver color. It almost doesn't seem real... like its a dream." << endl;
           cout << "You open the door and suddenly find your self back home in the real world." << endl;
           cout << art2 << endl;
           break;
       }
       
   }
}
