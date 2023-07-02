#### Autor: Jakub Poznański 
#### Data: 29.05.2023
### Opis działania

Program został zaprojektowany do uruchamiania centralnego serwera, który wykonuje obliczenia na żądanie podłączonych klientów. Przesyłanie danych między serwerem a klientami odbywa się przy użyciu kolejek komunikatów.

#### Polecenie:
- Nazwę kolejki serwera najlepiej zdefiniować w pliku nagłówkowym włączanym w programach serwera i klienta.

- Na początku niech serwer i klient wypisują na ekranie nazwę, deskryptor i atrybuty utworzonej kolejki.

- Następnie niech klient w pętli (do końca pliku EOF, czyli [Ctrl D] z klawiatury) wypisuje na ekranie prośbę o wpisanie z klawiatury odpowiedniego działania i wczytuje je.

- Serwer niech wypisuje na ekranie otrzymany komunikat oraz wynik wykonanego działania, a klient wynik otrzymany od serwera - sprawdzić, czy oba wyniki się zgadzają!
- W programach serwera oraz klienta wstawić funkcję sleep(), np. z losowym czasem, między odebraniem a wysłaniem komunikatu lub odwrotnie.
_________________________________________________________________________

### Jak uruchomić program ?
```bash
make run8
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