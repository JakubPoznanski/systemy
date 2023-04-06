Autor: Jakub Poznański 
Data: 06.04.2023
---------------------------OPIS PROGRAMu ZAD4---------------------------

(zad4) Problem producenta i konsumenta
Dane do potoku przesyłać/pobierać małymi porcjami (po kilka bajtów, 
nie wszystko naraz!) i wypisywać na ekranie dane przesyłane za każdym 
razem producenta i konsumenta. W ogólności porcje danych producenta i 
konsumenta mogą być różne, dlatego powinny zostać zdefiniowane oddzielnie.
Nazwy plików danych i wyników przekazywać przez argumenty wywołania programu.
Do czytania/pisania danych z/do pliku użyć funkcji read() i write(). 
Do wypisywania danych na ekranie również użyć funkcji write() z odpowiednim
deskryptorem. Do symulowania różnych szybkości działania procesów użyć 
funkcji sleep() z losowym czasem usypiania generowanym np. przez 
funkcję rand().Funkcją write() wpisywać liczbę faktycznie wczytanych 
przez read() bajtów (zwracaną prze nią).

-----------------------Jak uruchomić programy?---------------------------

1.kompilacja i uruchomienie 
        make run ARGS="in.txt out.txt"


2.polecenie "make clean" Usuwa wszystkie skompilowane pliki 

3.polecenie "make tar" służy do archiwizacji
---------------------------------------------------------------------------