#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <list>
#include <queue>

using namespace std;

int printOptions(){
    cout << "1. FIRST\n2. CPP\n3. REVIEW\n4. PROGRAM\n5. ASSIGNMENT\n6. CECS\n7. BEACH\n8. ECS\n9. FALL\n10. SPRING\n11. OS\n12. MAC\n13. LINUX\n14. WINDOWS\n15. LAB\n0. Exit" << endl;
    cout << "Choice: ";

    int choice;
    cin >> choice;

    return choice;
}

int main()
{
    //Random Generator
    srand(time(NULL));

    //Range of the possible size for each Document
    int memoryRange;

    //Alphabet Storage
    char alphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O','P', 'Q', 'R', 'S', 'T', 'U','V', 'W', 'X',
        'Y', 'Z'
    };

    //Dictionary - Used to Locate Words
    char dictionary[15][20] = {"FIRST", "CPP", "REVIEW", "PROGRAM",
    "ASSIGNMENT", "CECS", "BEACH", "ECS", "FALL", "SPRING", "OS",
    "MAC", "LINUX", "WINDOWS", "LAB"};

    //Initializing Recent_List (Linked List)
    int recent_listSize = 127;
    list<char *> recent_list;

    for(int i = 0; i < recent_listSize; i++){
        //Generate Memory Range for Each Document
        int memoryRange = rand() % 300000 + 200000;

        //Generate Document
        char *ptr = new char[memoryRange];

        //Populate Document with Random Letters
        for(int j = 0; j < memoryRange; j++){
            //Generates Random Index Number Referenced to Dictionary Char Array
            int randIndex = rand() % 26;

            //Store Random Letter into current Index
            ptr[j] = alphabet[randIndex];
        }
        //Stores Document on to List (Order does not matter for recent_list)
        recent_list.push_front(ptr);
    }


    //Initializing Library (Vector)
    int library_size = 1027;
    queue<char *> library;

    for(int i = 0; i < library_size; i++){
        //Generate Memory Range for Each Document
        int memoryRange = rand() % 300000 + 200000;

        //Generate Document
        char *ptr = new char[memoryRange];

        //Populate Document with Random Letters
        for(int j = 0; j < memoryRange; j++){
            //Generates Random Index Number Referenced to Dictionary Char Array
            int randIndex = rand() % 26;

            //Store Random Letter into current Index
            ptr[j] = alphabet[randIndex];
        }

        //Stores Document on to List to the bottom of the library
        library.push(ptr);
    }


    //User Input
    int userChoice = 0;
    do{
        int numOfDocsDeleted = 0;                                        //Used to figure out how much documents to transfer from library, and how many new documents to add to library (after transfer)
        userChoice = printOptions();

        if(userChoice == 0) //User Exit
            break;
        else{
            //Search Keyword in recent_list documents
            char *word = new char[20];
            word = dictionary[userChoice - 1];
            for(list<char *>::iterator recent_listIterator = recent_list.begin(); recent_listIterator != recent_list.end(); recent_listIterator++){
                //Use an iterator to go through the list of documents

                //Search Keyword in Documents
                char *output = NULL;
                output = strstr(*recent_listIterator, word);

                //If the word does not exist in the current document, then delete and update recent_list
                if(!output){
                    //Delete the Node and Update
                    recent_listIterator = recent_list.erase(recent_listIterator);

                    //Counter
                    numOfDocsDeleted++;
                }
            }

            //Transfer (if any) documents to the recent_list from library
            for(int i = 0; i < numOfDocsDeleted; i++){
                //Copies value from current value of libraryIterator
                recent_list.push_back(library.front());

                //Deletes the Document from library
                library.pop();

                //Add the new initialized Document to the Library
                int memoryRange = rand() % 300000 + 200000;
                char *ptr = new char[memoryRange];
                for(int j = 0; j < memoryRange; j++){
                    int randIndex = rand() % 26;
                    ptr[j] = alphabet[randIndex];
                }
                library.push(ptr);
            }

            //Display Output
            cout << "====================================================" << endl;
            cout << "Keyword: " << word << endl;
            cout << numOfDocsDeleted << " documents ejected and reinitialized" << endl;
            cout << "====================================================" << endl;
        }
    }while(userChoice != 0);


    return 0;
}
