#### Autor: Jakub Poznański 
#### Data: 06.04.2023
### Opis działania
Program implementuje problem producenta-konsumenta przy użyciu potoku 
nazwanego. Składa się z dwóch oddzielnych programów - jeden dla producenta,
drugi dla konsumenta. Nazwy plików potoku i plików tekstowych, któremają
być przesyłane, powinny być podawane jako argumenty wywołania 
każdego z programów.
### Jak uruchomić program ?
```bash
make all
make run ARGS="in.txt out.txt"
```
- kompiluje i uruchamia program

```bash 
make clean 
```
- Usuwa wszystkie skompilowane pliki

```bash
make tar
```
- Archiwizuje plik

### Obsługa programów z poziomu powłoki
```bash
 mkfifo myfifo
```
- tworzenie potoku

```bash
./in in.txt myfifo
```
- uruchomienie programu producenta

```bash
./out out.txt myfifo
```
- uruchomienie programu konsumenta

```bash
rm myfifo
```
- usunięcie potoku

______________________