- Dwa programy - pierwszy tworzy jeden proces potomny i uruchamia w nim drugi program, który ustawia ignorowanie sygnału, staje się liderem swojej grupy procesów, a następnie tworzy kilka procesów potomnych, które uruchamiają program z podpunktu(A); pierwszy proces macierzysty, po krótkim czasie uśpienia (funkcja sleep()) wysyła sygnał do całej grupy procesów; procesy macierzyste po utworzeniu wszystkich swoich procesów potomnych powinny na nie poczekać (funkcja wait()).
___________________________
### Jak uruchomić programy?
#### Każdy z programów podczas uruchomienia przyjmuje 2 argumenty:
- argv1 - *[ int ]* **rodzaj sygnału** 
- argv2 - *[ int ]* **operacja**

#### Program (A)
- kompilacja
```bash
make zad3_a
```
- uruchomienie
```bash
./zad3_a arg1 arg2
```

#### Program (B)
- kompilacja
```bash
make zad3_a
make zad3_b
```
- uruchomienie
```bash
./zad3_b arg1 arg2
```

#### Program (C)
- kompilacja
```bash
make zad3_a
make zad3_c
make sub_c
```
- uruchomienie
```bash
./zad3_c arg1 arg2
```

#### Dodatkowo 
- Usuwa wszystkie skompilowane pliki 
```bash 
make clean 
```
- Archiwizuje folder
```bash 
make tar
```
__________________________________