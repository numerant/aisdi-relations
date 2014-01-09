//
//  GenerateRE.cpp
//  CreateEMLfile
//
//  Created by Maciej Safarzyński on 08/01/14.
//  Copyright (c) 2014 Maciej Safarzyński. All rights reserved.
//

#include "GenerateRE.h"

void GenerateRE(From from, To to, Subject subject, MessageID messageidINRPLY, Date date, Rest rest, Contents contents, int ile)
           {
               if (ile!=0) {
               MessageID remessageid;
                Subject resubject("Re:", subject.text);
                From refrom(to.text);
                To reto(from.text);
                Contents recontents(contents.text);
               remessageid.SetID(remessageid.strID=IDgen(20));
               messageidINRPLY.SetIDINRPLY(messageidINRPLY.strID);
               string nazwapliku="Mails temp/IDnr" + remessageid.strID + ".eml";
               WriteLineInFile(refrom.linijka, nazwapliku);
               WriteLineInFile(reto.linijka, nazwapliku);
               WriteLineInFile(resubject.linijka, nazwapliku);
               WriteLineInFile(remessageid.linijka, nazwapliku);
               WriteLineInFile(messageidINRPLY.linijka, nazwapliku);
               WriteLineInFile(date.linijka, nazwapliku);
               WriteLineInFile(rest.linijka, nazwapliku);
               WriteLineInFile(recontents.linijka, nazwapliku);
               ile--;
               if (ile!=0) {
                   GenerateRE(refrom, reto, resubject, remessageid, date, rest, recontents, ile);
               }
               }
           }