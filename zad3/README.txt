Autor: Jakub Poznański 
Data: 02.04.2023
---------------------------OPIS PROGRAMÓW ZAD3---------------------------

(A) Program odpowiada za obsługę sygnałów 
    Funcja signal(rodzaj sygnału, operacja do wykonania)
    (1) wykonania operacji domyślnej
    (2) ignorowania
    (3) przechwycenia i własnej obsługi sygnału 
Program możemy zamknąć z poziomu nowego terminala poleceniem kill -9 <PID>
_________________________________________________________________________

(B) Program wywołuję funkcję fork() ,dla procesu potomnego za pomocą funckji
exelp() uruchamia program zad3_a. Proces macierzysty czeka na rozpoczęcie
procesu potomnego [sleep()] ,który sam nigdy nie zakończy 
działania (specyfika zad3_a). Następnie funkcja systemowa kill kończy
działanie procesu potomnego za pomocą wybranego przez nas sygnału.
Dzięki poleceniu wait(&status) oraz WIFSIGNALED(status) sprawdzamy czy
proces potomny został zakończony przez sygnał. WTERMSIG(status) podaje 
numer tego sygnału funkcja strsignal rodzaj.  
_________________________________________________________________________

(C) Dwa programy - pierwszy tworzy jeden proces potomny i uruchamia w nim 
drugi program, który ustawia ignorowanie sygnału, staje się liderem swojej
grupy procesów, a następnie tworzy kilka procesów potomnych, które 
uruchamiają program z podpunktu(A); pierwszy proces macierzysty,
po krótkim czasie uśpienia (funkcja sleep()) wysyła sygnał do całej grupy 
procesów; procesy macierzyste po utworzeniu wszystkich swoich procesów 
potomnych powinny na nie poczekać (funkcja wait()).

-----------------------Jak uruchomić programy?---------------------------
Każdy z programó podczas uruchomienia przyjmuje 2 argumenty:

argv1 - [int] rodzaj sygnału tabelka niżej
argv2 - [int] reakcja na sygnał:
        1-operacja domyślna
        2-ignorowanie 
        3-custom
1.  
    (A) make zad3_a kompilacja
        ./zad3 arg1 arg2 - uruchomienie
    (B) make zad3_b kompilacja 
        ./zad3_b arg1 arg2 -uruchomienie
        UWAGA program zad3_a musi być skompilowany aby B działał
    (C) make zad3_c kompilacja
        make sub_c  kompilacja
        ./zad3_c arg1 arg2 -uruchomienie

2.polecenie "make clean" Usuwa wszystkie skompilowane pliki 

3.polecenie "make tar" służy do archiwizacji
---------------------------------------------------------------------------

dodatkowo:
Numer	Nazwa	Opis
1	SIGHUP	Zakończenie procesu przez terminal
2	SIGINT	Przerwanie działania procesu (CTRL+C)
3	SIGQUIT	Zakończenie procesu i utworzenie pliku zrzutu pamięci
4	SIGILL	Wykrycie błędu wykonania lub naruszenie ochrony pamięci
5	SIGTRAP	Wykrycie pułapki lub zdarzenia debuggera
6	SIGABRT	Zakończenie procesu przez wywołanie abort()
7	SIGBUS	Wykrycie błędu związane z adresowaniem pamięci
8	SIGFPE	Wykrycie błędu zmiennoprzecinkowego
9	SIGKILL	Natychmiastowe zakończenie procesu
10	SIGUSR1	Sygnał zdefiniowany przez użytkownika nr 1
11	SIGSEGV	Wykrycie błędu odwołania do nieprawidłowego adresu pamięci
12	SIGUSR2	Sygnał zdefiniowany przez użytkownika nr 2
13	SIGPIPE	Zapis do potoku bez czytelnika
14	SIGALRM	Sygnał zegarowy
15	SIGTERM	Prośba o zakończenie procesu
16	SIGSTKFLT	Wykrycie błędu stosu
17	SIGCHLD	Zmiana stanu procesu potomnego
18	SIGCONT	Kontynuacja procesu zatrzymanego
19	SIGSTOP	Tymczasowe zatrzymanie procesu
20	SIGTSTP	Wstrzymanie procesu (CTRL+Z)
21	SIGTTIN	Zapisanie wejścia na tle procesu w tle
22	SIGTTOU	Zapisanie wyjścia na tle procesu w tle
23	SIGURG	Otrzymanie danych priorytetowych w gnieździe
24	SIGXCPU	Przekroczenie limitu czasu CPU
25	SIGXFSZ	Przekroczenie limitu rozmiaru pliku
26	SIGVTALRM	Wygaszenie zegara wirtualnego
27	SIGPROF	Wygaśnięcie zegara profil