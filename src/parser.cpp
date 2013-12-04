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
Content-Transfer-Encoding: quoted-printable\n\
\n\
Leave those apples and come join us Steve!\n\
\n\
>Yep\n\
>\n\
>>Tommorow the same DUDE?");

// emlParser

    string temp;
    size_t foundBeg, foundEnd;


void analyseField(string toFind) {
        foundBeg = eml.find(toFind);
        if (foundBeg!=string::npos) {
            //cout << "Field '"<< toFind << "' found at position: " << foundBeg << '\n';
            foundEnd=eml.find("\n",foundBeg+1);
            //cout << "Line end found at position: " << foundEnd << '\n';
            if (foundEnd!=string::npos)
            temp = eml.substr(foundBeg+toFind.length()+1,foundEnd-(foundBeg+toFind.length()+1));
            cout << "Field '" << toFind << "' \tcontains:\t "<< temp << '\n';
            //insert to object pointed by *temp_email
        }
        else
            cout << "Field '"<< toFind << "' didn't found!" <<  '\n';
            // throw exception
        }

void analyseContent() {
        temp = eml.substr(foundEnd+1);
        cout << "Field 'Content' \tcontains:\t " << temp << '\n';
    }

void emlParser (string eml_content) {
    //cout << "Eml content to analyse:\n" << endl << eml << endl;
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
    emlParser(eml);
    return 0;
}
