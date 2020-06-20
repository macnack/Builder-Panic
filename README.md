# Builder-Panic

Odwzorowanie istniejącej gry Building Panic, w grze wcielasz się w murarza/malarza, który ma za zadanie pomalować jak najwięcej ścian, a w międzyczasie walczyć z murarzami z innego corpo, którzy malują ściany na inny kolor. :smile: <br/>
Gra poziomowa, po pomalowaniu wszystkich ścian przechodzi się do następnego poziomu. <br/>
![Image of Building Panic](https://github.com/macnack/Builder-Panic/blob/master/images/building-panic_3_big.jpg)

<br/><br/>
Ściana posiada 4 etapy elewacji {Brak, 1/3, 2/3, 3/3}, podczas 3 pierwszych etapów kolor ścian może być zmieniony przez przeciwnego malarza akcją malowania, aby zmienić kolor ostatniego etapu elewacji, tutaj stosuje się zasady z gry planszowej [**Reversi**](https://pl.wikipedia.org/wiki/Reversi) aka **Othello** aka **Kapsle**(¿?) <br/>
<br/> Poruszanie się <br/>
* :arrow_up: - skok o jedną platformę do góry
* :arrow_down: - skok o jedną platformę do dołu
* :arrow_left: i :arrow_right: poruszanie się lewo i prawo
* "**M**" szarża ( atak ), działa podczas przemieszczania sie postaci w wybranym kierunku
* "**N**" malowanie - przytrzymac
<br/> Dla drugiego gracza <br/>
* "**W**" - skok o jedną platformę do góry
* "**S**" - skok o jedną platformę do dołu
* "**A**" i "**D**" poruszanie się lewo i prawo
* "**E**" szarża ( atak ), działa podczas przemieszczania sie postaci w wybranym kierunku
* "**Q**" malowanie - przytrzymac

## MINI TUTORIAL

* Zmiana koloru sciany przeciwnika odbywa się pod warunkiem że otoczymy je naszym kolorem. Odbywa się to w sposób prostopadły jak i po przekątnej...
![Image of malowanie](https://github.com/macnack/Builder-Panic/blob/master/images/malowanko.gif)
* Pod warunkiem że zostały otoczone przez w pełni pomalowaną ściane 
![Image of malowanie](https://github.com/macnack/Builder-Panic/blob/master/images/malowanie.gif)

## Planowane do wykorzystania biblioteki:

* SFML : Window.hpp, Graphics.hpp , *Audio.hpp*
* vector
* memory
* time.h

## UML projektu
![Image of UML model](https://github.com/macnack/Builder-Panic/blob/master/images/uml_model.png)

### Przewidziane typy obiektu
* Gracz
* Przeciwnicy
* Żetony
* Ściany ( pola do malowania)
* Platforma / Podłoga

### Klasy
**GAME** - tworzy scenę gry, odbywa się tam pętla gry, eventy, rysowanie obiektów, spawn przeciwników, <br/>
**Player** - poruszanie, zadawanie obrażeń przeciwnika, malowanie, zbieranie monet, <br/>
**Enemy** - *"boty" atakowanie gracza*, poruszanie się *malowanie ścian*, *w zależności od pozycji otrzymanej z klasy **Player** przeciwnicy powinni być bardziej aktywni*, <br/>
**ObjectManager** - przechowuje w mapie nazwy obiektów oraz obiekty klas pochodnych od **Object** za pomocą mapy <br/>
**Object** - klasa bazowa tworząca obiekt,
* **Wall** - ściany (pola do malowania), tworzenie obiektu, scalowanie do 3 etapów elewacji {1/3 2/3 3/3} możliwość zmiany koloru przez klase **Player** i ***Enemy***, zmiana kolorów wykorzystując zasady gry Reversi, pomalowane ściany w kolorze gracza są przeliczane na punkty, które są dodawane do klasy **Player**,
* **Floor** - podloga, po której poruszają się postacie, informacja o kolizjach przekazywana do **Player** **Enemy** , przeciwnicy byliby aktywniejsi na tym poziomie, daje informacje o kolizjach dla klasy **Player**,
* **Coins** - dodaje punkty do klasy **Player** , pojawia się w losowym czasie w losowej lokalizacji, *czas istnienia przedmiotu*,
### Żródła
- link do img: https://images.app.goo.gl/8qSQiCF2y2jHCg2Y9
- zasady gry Reversi: https://pl.wikipedia.org/wiki/Reversi
- let's play Building Panic: https://youtu.be/CFZXPE8_2K8

#### Obecny stan gry :disappointed_relieved:
![Image of gra right now](https://github.com/macnack/Builder-Panic/blob/master/images/scena.png)
![Image of board](https://github.com/macnack/Builder-Panic/blob/master/images/reversi_board.png)
##### Małym druczkiem ...
<br/>*elementy zapisane w **Italic** proszę uznać za elementy, które mogą zostać zmodyfikowane, bądź pominięte*
<br/>*model uml nie pokrywa się z opisem klas, ponieważ podczas pisania opisu uległ lekkim modyfikacja, **do zaktualizowania w najbliższym czasie***
