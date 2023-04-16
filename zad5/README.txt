Autor: Jakub Poznański 
Data: 06.04.2023
---------------------------OPIS PROGRAMu ZAD4---------------------------

(zad5)
Program implementuje problem producenta-konsumenta przy użyciu potoku 
nazwanego.Składa się z dwóch oddzielnych programów - jeden dla producenta,
drugi dla konsumenta. Nazwy plików potoku i plików tekstowych, któremają
być przesyłane, powinny być podawane jako argumenty wywołania 
każdego z programów.

-----------------------Jak uruchomić programy?---------------------------

1.kompilacja i uruchomienie:
        make all
        make run ARGS="in.txt out.txt"\

2.Obsługa programów z poziomu powłoki:

        mkfifo myfifo        //tworzenie potoku
        ./in in.txt myfifo   //uruchomienie programu producenta 
        ./out out.txt myfifo //uruchamianie programu konsumenta
        rm myfifo            //usunięcie potoku

3.polecenie "make clean" Usuwa wszystkie skompilowane pliki 

4.polecenie "make tar" służy do archiwizacji
---------------------------------------------------------------------------