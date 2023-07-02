#### Autor: Jakub Poznański 
#### Data: 29.05.2023
### Opis działania

Program realizuję problem producenta i konsumenta przy pomocy semaforów oraz pamięci dzielonej. 

#### Polecenie:
- Semafor tworzyć z flagą `O_EXCL`.

- Po utworzeniu semaforów wypisać ich adresy i wartości początkowe, a po utworzeniu pamięci dzielonej wypisać jej dekskryptor oraz rozmiar w bajtach.

- Producent i konsument niech wypiszą na początku adresy semaforów i deskryptor pamięci dzielonej, a potem w trakcie przesyłania danych niech wypisują wartości semaforów, bieżący indeks elementu bufora, liczbę wstawianych/pobieranych bajtów oraz przesyłany tekst.

- Rozmiar elementu bufora powinien być większy niż 1 bajt, a liczba elementów większa od 1.

- Programy producenta i konsumenta uruchamiać przez execlp w dwóch procesach potomnych tworzonych funkcją `fork()` przez proces macierzysty, który na początku powinien stworzyć semafory i pamięć dzieloną, poczekać na zakończenie swoich potomków, a następnie usunąć semafory i pamięć dzieloną.

- Nazwy semaforów, pamięci dzielonej oraz plików tekstowych przekazywać do producenta i konsumenta przez argumenty funkcji `execlp`.

- Do czytania/pisania danych z/do pliku użyć funkcji `read()`/`write()`i przesyłać surowe bajty, a nie formatowany tekst (ang. string).

- Jako sygnał końca danych producent może zapisać do bufora znak `'\0'`, a konsument po jego odczytaniu zakończyć pracę.

- Stworzyć dwa oddzielne moduły z funkcjami pomocniczymi dla semaforów oraz pamięci dzielonej

- Na końcu porównać pliki tekstowe producenta i konsumenta, np. wstawić polecenie diff -s w pliku Makefile po zakończeńczeniu działania programów.
_________________________________________________________________________

### Jak uruchomić program ?
```bash
make run7
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
__________________________________________