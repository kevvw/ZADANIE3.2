# ZADANIE3.2

AGH WIEiT 
KEVIN PIETRZYK

Druga czesc zadania trzeciego z Logiki matematycznej w informatyce.

Zadanie to polegalo na stworzeniu gry ktora by testowala u gracza znajomosc logiki i logicznego myslenia. Bazuje ona na logice wielowartociowej.

Gra jest zapisanie w jezyku c.

kompilacja: gcc -Wall -O2 -ansi -pedantic -std=c99 -o game game.c -lm
wywolanie: ./game --AND and.txt --OR or.txt --IMPL impl.txt --NOT not.txt

Najpierw trzeba wszystkie pliki zapisac w tym samym folderze a nastepnie skompilowac by dzialalo.

Gra sklada sie maksymalnie z 10 rund. Na poczatku kazdej rundy graczowi jest przedstawione zdanie logiczne ktore trzeba uzgodnic tak by spelnialo warunek obok zdania.
np. ~A ^ B  falszywe

A i B to beda podane proste nierownosci w ktorych sie podaje x i y np:
26 >= x
33 < y

Podajemy takie x i y by sformulowania A i B spelnialy nasze logiczne zdanie z sposob jaki chcemy.

Przyjmowane przez system sa liczby calkowite, kazda inna wartosc podana bedzie uznana z nieokreslona 'x'.

za poprawne uzgodnienie zdania jest 1 pkt.
za niepoprawne gra sie konczy
natomiast ze niejednoznaczna odpowiedz gracz gra dalej ale z koncowej puli punkt zostanie odjety odpowiedni odsetek.
Zatem mozna zauwazyc ze czasami lepiej jest odpowiedziec niejednoznacznie niz zle.

To by bylo z grubsza tyle, zapraszam serdecznie do gry!



