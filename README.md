aisdi-relations
===============

Repozytorium projektu analizy relacji biznesowych na AISDI

###Kompilacja projektu

Do poprawnej kompilacji niezbędne są biblioteki **libboost-filesystem** i **libboost-system** w wersji nie starszej niż **1.50**. Pliki libboost_filesystem.so oraz libboost_system.so (lub dowiązania do nich - jeżeli domyślnie instalowane są w /usr/lib/x86_64-linux-gnu/ - znajdować się muszą w katalogu **/usr/lib/**.

Wymagane jest wxWidgets w wersji 2.8. Uwaga - jeśli jednocześnie mamy zainstalowaną wersję 3.0, kompilacja się nie powiedzie, dlatego najlepiej się jej pozbyć (jeśli nie jest nam potrzebna), bądź w opcjach C::B (nie projektu) dodać parametry wskazane nam przez **wx-config --cxxflags** i **wx-config --libs**, zamieniając wszystkie "3.0" na "2.8".

Projekt stworzony jest w aplikacji **Code::Blocks** w wersji 12.10 wraz z dodatkami contrib oraz wxSmith. Najnowsza wersja dostępna jest na stronie projektu: <http://www.codeblocks.org/>. Użytkownikom **Debiana** zaleca się skorzystanie z repozytorium **http://apt.jenslody.de/** - pakiety domyślnie dostępne w systemie mają problemy z ładowaniem wxSmitha. Dla użytkowników Ubuntu dostępne jest repozytorium **ppa:pasgui/ppa**.
