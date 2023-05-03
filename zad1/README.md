#### Autor: Jakub Poznański 
#### Data: 17.03.2023

### Opis działania 
#### Program (A) 
- Program wypisujący identyfikatory UID, GID, PID, PPID i PGID procesu

#### Program (B) 
- Program tworzący w pętli 3 razy procesy potomne i wypisujący identyfikatory każdego potomka. Proces macierzysty czeka na koniec procesow potomnych (wykorzystanie funkcji wait)

#### Program (C)
- Program tworzący w pętli 3 razy procesy potomne i wypisujący identyfikatory każdego potomka. Procesy potomne są spowalniane przez funckję sleep() zostają adobtowane przez proces init ponieważ proces macierzysty kończy działanie wcześniej niż potomne.

#### Program (D) 
- Program wypisujący pogrupowane procesy potomne od najstarszego do najmłodszego.

#### Program (E) 
- Program sprawia ,że każdy proces potomny staje się liderem swojej grupyfunkcja setpgid().
______________
#### Katalog zawiera program Makefile do kompilacji i uruchamiania powyzszych programow, a takze czyszczenia katalogu i jego archiwizacji.
_____________

### Jak uruchomić programy?
- Kompiluje oraz urachamia program (A)
```bash
make a
```
- Kompiluje oraz urachamia program (B)
```bash
make b
```
- Kompiluje oraz urachamia program (C)
```bash
make c
```
- Kompiluje oraz urachamia program (D)
```bash
make d
```
- Kompiluje oraz urachamia program (E)
```bash
make e
```
- Usuwa wszystkie skompilowane pliki 
```bash 
make clean 
```
- Archiwizuje plik
```
make tar
```
___________