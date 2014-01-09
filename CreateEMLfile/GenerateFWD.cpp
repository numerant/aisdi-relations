//
//  GenerateFWD.cpp
//  CreateEMLfile
//
//  Created by Maciej Safarzyński on 09/01/14.
//  Copyright (c) 2014 Maciej Safarzyński. All rights reserved.
//

#include "GenerateFWD.h"


void GenerateFWD(From from, To to, Subject subject, Date date, Rest rest, Contents contents, int ile)
{
    for (int i=0; i<ile; i++)
    {
        MessageID remessageid;
        Subject resubject("Fwd:", subject.text);
        From refrom(to.text);
        To reto;
        Contents recontents(contents.text);
        remessageid.SetID(remessageid.strID=IDgen(20));
        string nazwapliku="Mails temp/IDnr" + remessageid.strID + ".eml";
        WriteLineInFile(refrom.linijka, nazwapliku);
        WriteLineInFile(reto.linijka, nazwapliku);
        WriteLineInFile(resubject.linijka, nazwapliku);
        WriteLineInFile(remessageid.linijka, nazwapliku);
        WriteLineInFile(date.linijka, nazwapliku);
        WriteLineInFile(rest.linijka, nazwapliku);
        WriteLineInFile(recontents.linijka, nazwapliku);
    }
}
