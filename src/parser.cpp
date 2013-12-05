/*
    Program testujący parser eml dla przykładowego pliku.
    Nie stanowi części programu, ale może być przydatny do stwierdzenia,
    czy analiza emaila daje oczekiwane, poprawne wyniki
*/

#include <iostream>
#include <string>

using namespace std;

string eml("From: \"bob dylan\" <bob.dylan@mail.com>\n\
To: \"steve jobs\" <steve.jobs@mail.com>\n\
Subject: Fwd:Re: Meeting at the Bowling Club\n\
Message-ID: <0009@mail.com>\n\
Date: Wed, 29 May 2013 12:30:37 +0200\n\
MIME-Version: 1.0\n\
Content-Type: text/html;\n\
        charset=\"iso-8859-1\"\n\
Conten-Transfer-Encoding: quoted-printable\n\
\n\
Leave those apples and come join us Steve!\n\
\n\
>Yep\n\
>\n\
>>Tommorow the same DUDE?");

// emlParser

    string temp;
    string lastField = "Content-Transfer-Encoding:";
    size_t foundBeg, foundEnd;


void parseFrom(){
    string name, adress, current;
    int nameFlag = 0, adressFlag = 0;
    unsigned int i = 0;
    while(i <= temp.length()) {
        current = temp[i];
        if(!(current.compare("\""))) nameFlag++;
        else if(nameFlag == 1) name = name + current;
        else if(!(current.compare("<"))) adressFlag++;
        else if(!(current.compare(">"))) adressFlag++;
        else if(adressFlag == 1) adress = adress + current;
        i++;
    }
    if (adressFlag != 2 || nameFlag != 2) throw "Eml file corrupted!";
    cout << "'Name' in 'From:' contains: "<< name << endl;
    cout << "wywolany email.set..." << endl;
    cout << "'Adress' in 'From:'contains: "<< adress << endl;
    cout << "wywolany email.set..." << endl;
}
void parseTo() {
    string name, adress, current;
    int nameFlag = 0, adressFlag = 0;
    unsigned int i = 0;
    while(i <= temp.length()) {
        current = temp[i];
        if(!(current.compare("\""))) nameFlag++;
        else if(nameFlag == 1) name = name + current;
        else if(!(current.compare("<"))) adressFlag++;
        else if (!(current.compare(">"))) adressFlag++;
        else if(adressFlag == 1) adress = adress + current;
        i++;
    }
    if (adressFlag != 2 || nameFlag != 2) throw "Eml file corrupted!";
    cout << "'Name' in 'To:' contains: "<< name << endl;
    cout << "wywolany email.set..." << endl;
    cout << "'Adress' in 'To:' contains: "<< adress << endl;
    cout << "wywolany email.set..." << endl;
}

/*
void parseDate() {
    cout << "parse date" << endl;cout << "wywolany email.set..." << endl;
}
*/



void analyseField(string toFind) {
        foundBeg = eml.find(toFind);
        if (foundBeg!=string::npos) {
            //cout << "Field '"<< toFind << "' found at position: " << foundBeg << '\n';
            foundEnd=eml.find("\n",foundBeg+1);
            //cout << "Line end found at position: " << foundEnd << '\n';
            if (foundEnd!=string::npos)
            temp = eml.substr(foundBeg+toFind.length()+1,foundEnd-(foundBeg+toFind.length()+1));
            cout << "'" << toFind << "' contains: "<< temp << '\n';
            if(toFind == "From:") parseFrom();
            else if(toFind == "To:") parseTo();
            //else if(toFind == "Date:") parseDate();
            else cout << "wywolany email.set..." << endl;
            //insert to object pointed by *temp_email
        }
        else if(toFind.compare("Content-Transfer-Encoding:"))
            //cout << "Field '"<< toFind << "' didn't found!" <<  '\n';
            throw "Eml file corrupted!";
        }


void analyseContent() {
        temp = eml.substr(foundEnd+1);
        cout << "'Content' contains: " << temp << '\n';
        cout << "wywolany email.set..." << endl;
    }

void emlParser (string eml_content) {
    cout << "Eml content to analyse:\n" << endl << eml << endl << endl;
    analyseField("From:");
    analyseField("To:");
    analyseField("Subject:");
    analyseField("Message-ID:");
    analyseField("Date:");
    analyseField("MIME-Version:");
    analyseField("Content-Type:");
    analyseField("Content-Transfer-Encoding:");
    analyseContent();
    return;
}

int main()
{
    try {
    emlParser(eml);
    }
    catch (const char* msg) {
     cerr << "Eml file corrupted" << endl;
   }
    return 0;
}
