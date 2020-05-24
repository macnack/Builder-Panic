# Builder-Panic

Odwzorowanie istniejacej gry Building Panic, w grze wcielasz się w murarza/malarza który ma za zadanie pomalować jak najwięcej ścian, a w między czasie walczyć z murarzami z innego corpo, którzy malują ściany na inny kolor. :smile: <br/>
Gra poziomowa, po pomalowaniu wszystkich ścian przechodzi się do następnęgo poziomu. <br/>
![Image of Building Panic](https://github.com/macnack/Builder-Panic/blob/master/images/building-panic_3_big.jpg)

<br/><br/>
Sciana posiada 4 etapy elewacji {Brak, 1/3, 2/3, 3/3}, podczas 3 pierwszych etapów kolor ścian może być zmieniony przez przeciwnego malarza akcją malowania, aby zmienić kolor ostatniego etapu elewacji - tutaj stosuje się zasady z gry planszowej [**Reversi**](https://pl.wikipedia.org/wiki/Reversi) aka **Othello** aka **Kapsle**(¿?) <br/> 
<br/> Poruszanie się <br/> 
* :arrow_up: - skok o jędną platformę do góry
* :arrow_down: - skok o jedną platformę do dołu
* :arrow_left: i :arrow_right: poruszanie się lewo i prawo
* "**Z**" rzut zaprawą ( atak ) 
* "**X**" malowanie 
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
* Sciany ( pola do malowania)
* Platforma / Podłoga

### Klasy 
**GAME** - tworzy scene gry, odbywa się tam pętla gry, eventy, rysowanie obiektów, spawn przeciwników, <br/>
**Player** - poruszanie, zadawanie obrazen przeciwniką, malowanie, zbieranie monet, <br/>
**Enemy** - *"boty" atakowanie gracza*, poruszanie się *malowanie scian*, *w zaleznosci od pozycji otrzymanej z klasy **Player** przeciwnicy powinni byc bardziej aktywni*, <br/>
**ObjectManager** - przechowuje w mapie nazwy obiektow oraz obiekty klas pochodnych od **Object** za pomocą mapy <br/>
**Object** - klasa bazowa tworzaca obiekt, 
* **Wall** - sciany(pola do malowania), tworzenie obiektu, scalowanie do 3 etapów elewacji {1/3 2/3 3/3} mozliwosc zmiany koloru przez klase **Player** i  ***Enemy***, zmiana kolorów wykorzystując zasady gry Reversi, pomalowane sciany w kolorze gracza są przeliczane na punkty i dodawnae do klasy **Player**,
* **Floor** - podloga po której poruszają się postacie, informacja o kolizjach przekazywana do **Player** **Enemy** , przeciwnicy byli by aktywniejsi na tym poziomie, daje informacje o kolizjach dla klasy **Player**,
* **Coins** - dodaje punkty do klasy **Player** , pojawia sie w losowym czasie w losowej lokalizacji, *czas istnienia przedmiotu*,
### Żródła
- link do img: https://images.app.goo.gl/8qSQiCF2y2jHCg2Y9
- zasady gry Reversi: https://pl.wikipedia.org/wiki/Reversi
- let's play Building Panic: https://youtu.be/CFZXPE8_2K8

#### Obecny stan gry :disappointed_relieved:
![Image of gra right now](https://github.com/macnack/Builder-Panic/blob/master/images/scena.png)
<br/>*elementy zapisane w **Italic** proszę uznać za elementy, które mogą zostać zmodyfikowane, bądź pominięte*
<br/>*model uml nie pokrywa się z opisem klas, ponieważ podczas pisania opisu uległ lekkim modifikacją, **do zaaktualizowania w najbliższym czasie***
