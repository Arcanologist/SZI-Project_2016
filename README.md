# SZI-Project_2016

Czonkowie: Maksym Krawczyk, Piotr Beczyński, Rafal Pindzia

Temat: Inteligentny Traktor

Zadaniem inteligentnego traktora jest uprawianie pola. Traktor, przesuwając się po polu, sprawdza
stan gleby i upraw oraz podejmuje decyzje o zastosowaniu środków ochrony roślin, nawodnieniu,
zastosowaniu nawozów itp.

Język programowania: cpp
Reprezentacja graficzna: Tekstowy tryb graficzny + kolory + boczny pasek pełen dodatkowych informacji + action log na styl dwarf fortress:
http://postimg.org/gallery/1c7fq0bby/f71b0c22/


Projekt (zespołowo):
– Reprezentacja wiedzy
  • sieci semantyczne
	-ISA, HASA, AKO
		+ISA - is a - konkretna instancja obiektu jest obiektem klasy traktor
		+HASA - has a (Part) - relacja część-całość - poszczególny traktor może mieć elementy pozwalające spełniać kilka funkcji (nawodnienie, nawożenie, oranie, 		zbieranie itd.).
		+AKO - a kind of - ziemniak jest rośliną podziemną, sadzoną na wiosnę itd.
  • systemy ram
  • grafy konceptualne
  • logika pierwszego rzędu
  • logika klauzul/Prolog
  • zbiory rozmyte
  
– Planowanie ruchu
  •A*
  •IDA*
  +wysokopoziomowy system podejmujcy decyzje, kolejkujcy zadania, nadajacy priorytety itd.
  
– Zgodność ze specyfikacją zadania
  
– Bezawaryjne działanie
  
  
Metody uczenia:
	• uczenie drzew decyzyjnych
	• algorytmy genetyczne
	• algorytmy uczenia symbolicznego (alg. specjalizujący, generalizujący, eliminacja kandydatów)
	• sieci neuronowe (alg. propagacji wstecznej)
	• dowolna inna po uzgodnieniu z prowadzącym zajęcia

Traktor podejmuje decyzje co do upraw w danym sezonie, 'symuluje' cały sezon (w ramach możliwości stara się utrzymywać wszystkie rośliny podlane, nawiezione i zebrane w terminie), ostatecznie ocenia on swoją strategię na podstawie zysków które osiągnął (zarówno w postaci statystyk - ile czego zebrał, a później przeliczone na jednolitą walutę - 'pieniądze').
	
Każdy członek zespołu implementuje jedną z metod uczenia próbując rozwiązać ten problem, i jest oceniany w ramach:

Podprojekt (indywidualnie)
		– Przygotowanie danych wejściowych/zbioru treningowego i testowego
		– Poprawność implementacji/integracji opracowanej metody w projekcie
		– Pełność i poprawność omówienia tematu i przygotowanego raportu
		
Odpowiednia reprezentacja danych i odpowiednie napisanie / zrozumienie części wspólnej przez każdego członka zespołu jest kluczowe do sprawnej pracy - sensowniej rozwiazać problem raz w części wspólnej niż wielokrotnie pisać to samo.
