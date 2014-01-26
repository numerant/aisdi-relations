==========================================================
Repozytorium projektu analizy relacji biznesowych na AISDI
==========================================================

----------------------------------------------------------
Zawartość repozytorium
----------------------------------------------------------
Folder bin
	Zawiera pliki projektu, w tym klasy paneli (bin/view), grafiki (bin/resources), pliki binarne kompilacji (bin/bin), w tym samodzielny program (bin/bin/Debug/AisdiRelations) oraz pliki i foldery na potrzeby biblioteki wxWidgets oraz Code::Blocks'a (bin/obj, bin/wxsmith, bin/AisdiRelations.cbp)
Folder src
	Zawiera pliki klas niezwiązanych bezpośrednio ze środowiskiem C::B i biblioteką WxW, ale zapewniające elementarną funkcjonalność programu, bazę danych, obróbkę emaili, sterowanie I/O, wszystkie algorytmy i inneia.
Folder project
	Zawiera wszystko co niezbędne do samodzielnego uruchomienia pliku, czyli plik binarny projektu 'AisdiRelations' oraz folder grafik. Jest tam również skrypt testujący program pod kątem operacji na pamięci (valgrind).
Folder testy
	Zawiera specjalnie przygotowane zestawy testów o różnej strukturze, ilości i stopniu skomplikowania
Folder dokumentacja
	Zawiera szczegółowy opis klas użytych w projekcie, zestaw sprintów z rozpisanymi user stories oraz sprawozdanie o pracy każdego członka projektu

Ponadto, w katalogu głównym, zamieszczony jest skrypt 'projectScript' tworzący i umieszczjący pliki w katalogu bin/project

----------------------------------------------------------
Kompilacja projektu
----------------------------------------------------------
Do poprawnej kompilacji niezbędne są biblioteki **libboost-filesystem** i **libboost-system** w wersji nie starszej niż **1.50**. Pliki libboost_filesystem.so oraz libboost_system.so (lub dowiązania do nich - jeżeli domyślnie instalowane są w /usr/lib/x86_64-linux-gnu/ - znajdować się muszą w katalogu **/usr/lib/**.

Wymagane jest wxWidgets w wersji 2.8. Uwaga - jeśli jednocześnie mamy zainstalowaną wersję 3.0, kompilacja się nie powiedzie, dlatego najlepiej się jej pozbyć (jeśli nie jest nam potrzebna), bądź w opcjach C::B (nie projektu) dodać parametry wskazane nam przez **wx-config --cxxflags** i **wx-config --libs**, zamieniając wszystkie "3.0" na "2.8".

Projekt stworzony jest w aplikacji **Code::Blocks** w wersji 12.10 wraz z dodatkami contrib oraz wxSmith. Najnowsza wersja dostępna jest na stronie projektu: <http://www.codeblocks.org/>. Użytkownikom **Debiana** zaleca się skorzystanie z repozytorium **http://apt.jenslody.de/** - pakiety domyślnie dostępne w systemie mają problemy z ładowaniem wxSmitha. Dla użytkowników Ubuntu dostępne jest repozytorium **ppa:pasgui/ppa**.
