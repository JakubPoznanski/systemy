#### Autor: Jakub Poznański 
#### Data: 16.05.2023
### Opis działania
Program realizuję zadanie wzajemnego wykluczania procesów przy pomocy semaforów nazwowych standardu POSIX. Czas operacji na wspólnym zasobie pamięci symulowany jest za pomocą funkcji `Sleep()`. 

- #### Polecenie:
- Semafor tworzyć z flagą O_EXCL.

- W programie powielaczu wypisać adres i wartość początkową stworzonego semafora.

- W programie do wzajemnego wykluczania wypisywać PID procesu oraz wartość semafora przed, wewnątrz i po sekcji krytycznej, a także numer wykonywanej sekcji krytycznej.

- Plik numer.txt najlepiej najpierw otworzyć w trybie tylko do odczytu, przeczytać zapisany w nim numer, zamknąć go, a następnie po zwiększeniu numeru o 1 otworzyć go ponownie w trybie do zapisu, wpisać do niego nową wartość numeru i zamknąć go - to wszystko powinno odbywać się w sekcji krytycznej programu.

- Po odczytaniu numeru z pliku wypisać go na ekranie, a po zakończeniu wszystkich procesów realizujących wzajemne wykluczanie wypisać jego końcową wartość i porównać z wartością oczekiwaną w przypadku poprawnej synchronizacji procesów.

- Wywołanie funkcji sleep() (np. z losowym czasem) wstawić w sekcji krytycznej między odczytem a zapisem numeru z/do pliku, a także przed wejściem do sekcji krytycznej.

- Przy wypisywaniu informacji w sekcji krytycznej na ekranie użyć dodatkowego odstępu po lewej stronie, np. tabulatora, by łatwiej było ją odróżnić od sekcji prywatnej procesu.
- Wyłączyć synchronizację semaforem (np. wykomentować odpowiednie operacje) i sprawdzić końcową wartość numeru (powinna być mniejsza od tej z użyciem semafora). 
- Kompilować/linkować programy z flagami: -Wall -std=c99 -pedantic
_________________________________________________________________________

### Jak uruchomić program ?
```bash
make zad3
```
- kompiluje i uruchamia program

```bash 
make clean 
```
- Usuwa wszystkie skompilowane pliki

```bash
make tar
```
- Archiwizuje pliku
__________________________
<br>

#### Opcje uruchamiania w pliku Makefile:
> SYNC = `0/1` 

- włącznie synchronizacji za pomocą semaforów `nie/tak`

> CROSS = `0/1`

- procesy obłusują jeden plik jednocześnie `nie/tak` 
__________________________________________