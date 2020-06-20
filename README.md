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

* Zmiana koloru sciany przeciwnika odbywa się pod warunkiem że otoczymy je naszym kolorem. Odbywa się to w sposób prostopadły jak i po przekątnej... <br/>
![Image of malowanie](https://github.com/macnack/Builder-Panic/blob/master/images/malowanko.gif)
* Pod warunkiem że zostały otoczone przez w pełni pomalowaną ściane <br/>
![Image of malowanie](https://github.com/macnack/Builder-Panic/blob/master/images/malowanie.gif)
* Aby zaatakować należy poruszać się w kierunku którym chcemy go wykonać oraz wcisnąć przycisk ataku. Możliwośći ataku : <br/>
![Image of malowanie](https://github.com/macnack/Builder-Panic/blob/master/images/attack_tutorial.gif)

## Wykorzystane biblioteki:

* SFML : Window.hpp, Graphics.hpp
* cmath
* time.h
* map
* memory

### Typy obiektu
* GameObject - textury bloków sceny
* Object
* Żetony
* Ściany ( pola do malowania)
* Platforma / Podłoga

### Klasy
* **GAME : public sf::RenderWindow** - tworzy scenę gry, odbywa się tam pętla gry, eventy, rysowanie obiektów, spawn przeciwników,
* **Menu : public sf::RenderWindow** - obsługa ekranu startowego, pauzy, końca gry
* **Animation : public sf::Sprite** - animacja tekstur <br/>
  * **Entity : public Animation** - wykrywanie kolizji, interakcja ze sceneria
    * **Coin : public Entity** - tworzenie monet
    * **Hero : public Entity** - klasa postaci, poruszanie się, atak, cooldowny, 
      * **Player : public Hero** 
      * **Enemy : public Hero**
* **GameObject : public sf::Sprite** - obiekty gry
  * **Object : public GameObject** - sciany do malowania, zmiana rozmiaru, koloru
* **ObjectManager** - przechowywanie malowanych ścian, logika Reversi, zmiana koloru przez obiekty klasy **Hero***
* **Scena** - tworzenie scenerii gry, background, platformy
### Wykorzystane tekstury 
- Industrial pack - OllieBerzs https://ollieberzs.itch.io/industrial-pack
- Gems / Coins - 	La Red Games https://laredgames.itch.io/gems-coins-free
- Dungeons Walls - Evil_PoisonBR https://evil-poisonbr.itch.io/dungeons-walls
- Castle Platformer Tileset - RottingPixels https://rottingpixels.itch.io/castle-platformer-tileset-16x16free
### Czcionka
- Fjalla One - Sorkin Type https://fonts.google.com/specimen/Fjalla+One?sort=popularity#standard-styles
### Żródła
- link do img: https://images.app.goo.gl/8qSQiCF2y2jHCg2Y9
- zasady gry Reversi: https://pl.wikipedia.org/wiki/Reversi
- let's play Building Panic: https://youtu.be/CFZXPE8_2K8

