#### Autor: Jakub Poznański 
#### Data: 06.04.2023
### Opis działania 
Problem producenta i konsumenta
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
### Jak uruchomić program ?
```bash
make run ARGS="in.txt out.txt"
```
- Kompilacja i uruchamia program 

```bash 
make clean 
```
- Usuwa wszystkie skompilowane pliki

```
make tar
```
- Archiwizuje plik
___________