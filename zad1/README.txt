Autor: Jakub Poznański 
Data: 17.03.2023
---------------------------OPIS PROGRAMÓW ZAD1---------------------------

(A) program wypisujący identyfikatory UID, GID, PID, PPID i PGID procesu
_________________________________________________________________________

(B) program tworzący w pętli 3 razy procesy potomne i wypisujący 
identyfikatory każdego potomka. Proces macierzysty czeka na 
koniec procesow potomnych (wykorzystanie funkcji wait)
_________________________________________________________________________

(C) program tworzący w pętli 3 razy procesy potomne i wypisujący 
identyfikatory każdego potomka. Procesy potomne są spowalniane przez funckję
sleep() zostają adobtowane przez proces init ponieważ proces macierzysty
kończy działanie wcześniej niż potomne. 
_________________________________________________________________________

(D) program wypisujący pogrupowane procesy potomne od najstarszego do 
najmłodszego.
_________________________________________________________________________

(E) program sprawia ,że każdy proces potomny staje się liderem swojej grupy
funkcja setpgid().
___________________________________________________________________________


Katalog zawiera program Makefile do kompilacji i uruchamiania powyzszych 
programow, a takze czyszczenia katalogu 
i jego archiwizacji.

-----------------------Jak uruchomić programy?---------------------------

           "make a" Kompiluje oraz urachamia program (A)
           "make b" Kompiluje oraz urachamia program (B)
           "make c" Kompiluje oraz urachamia program (C)
           "make d" Kompiluje oraz urachamia program (D)
           "make e" Kompiluje oraz urachamia program (E)

W programie (C) aby zobaczyć procesy potomne należy wpisać:
"make c" oraz od razu "pstree -p". (pstree.png)

2.polecenie "make clean" Usuwa wszystkie skompilowane pliki 

3.polecenie "make tar" służy do archiwizacji
---------------------------------------------------------------------------


