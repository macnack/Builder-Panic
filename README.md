# Builder-Panic
Gra dwuosobowa, celem gry jest zbieranie punktów poprzez malowanie ścian i zdobywanie monet, malowanie odbywa się 3 etapowo {1/3, 2/3, 3/3} uzupelnienia elewacji. Przy pierwszych 2 elewacjach gracze moga zmieniać kolor na własny, w przypadku gdy ściana jest w pełni pomalowana, można ją przechwycić zgodnie z zasadą gry Rewersi *(wiecej w mini tutorialu)*. Zakonczenie gry następuje gdy wszystkie ściany zostają zamalowanie. <br/>
![Image of Buider Panic](https://github.com/macnack/Builder-Panic/blob/master/images/builder_panic.png)
* Ekran startowy służy jako tutorial, po wciśnięciu *startu*, zdobyte punkty i pomalowane sciany zostana zresetowane, a ilosc monet na ekranie zostanie zmniejszona. 
* Podczas wciśniećia pauzy przycisk **ESC** , otrzymujemy obecną ilość zdobytych punktów mozna zresetować obecny stan gry, poprzez wsciśniecie przycisku *HOME*, lub wyjść *EXIT*

## Remake Building Panic
Jest to odwzorowanie istniejącej gry Building Panic, w grze wcielasz się w murarza/malarza, który ma za zadanie pomalować jak najwięcej ścian, a w międzyczasie walczyć z murarzami z innego corpo, którzy malują ściany na inny kolor. :smile: <br/>
![Image of Building Panic](https://github.com/macnack/Builder-Panic/blob/master/images/building-panic_3_big.jpg)

## Zdobywanie punktów
* Kazda pomalowana elewacja +25
* Wartości monet
  * Zlota +100
  * Srebrna +50
  * Brązowa +25
* Zakonczenie gry, każda pomalowana ściana to +175 

# Sterowanie
* Gracz pierwszy:
  * "**W**" - skok o jedną platformę do góry
  * "**S**" - skok o jedną platformę do dołu
  * "**A**" i "**D**" poruszanie się lewo i prawo
    * "**C**" szarża ( atak ), działa podczas przemieszczania sie postaci w wybranym kierunku
  * "**Q**" malowanie - przytrzymać
* Drugi gracz:
  * :arrow_up: - skok o jedną platformę do góry
  * :arrow_down: - skok o jedną platformę do dołu
  * :arrow_left: i :arrow_right: poruszanie się lewo i prawo
    * "**M**" szarża ( atak ), działa podczas przemieszczania sie postaci w wybranym kierunku
  * "**N**" malowanie - przytrzymać

## MINI TUTORIAL

* Zmiana koloru sciany przeciwnika odbywa się pod warunkiem że otoczymy je naszym kolorem. Odbywa się to w lini prostopadłej lub i po przekątnej <br/>
![Image of malowanie](https://github.com/macnack/Builder-Panic/blob/master/images/malowanko.gif)
* Pod warunkiem że zostały otoczone przez w pełni pomalowaną ściane <br/>
![Image of malowanie](https://github.com/macnack/Builder-Panic/blob/master/images/malowanie.gif)
* **Logika przechwytywania ścian** - [**Reversi**](https://pl.wikipedia.org/wiki/Reversi) aka **Othello** aka **Kapsle**(¿?) <br/>
* Aby zaatakować należy poruszać się w kierunku którym chcemy go wykonać oraz wcisnąć przycisk ataku. Możliwośći ataku : <br/>
![Image of malowanie](https://github.com/macnack/Builder-Panic/blob/master/images/attack_tutorial.gif)
* Gdy postać otrzymuje obrażenia, nie może się poruszać, następnie staje się nietykalna aby zapobiec ponownemu otrzymaniu obrażeń
## Wykorzystane biblioteki:
* SFML : Window.hpp, Graphics.hpp
* cmath
* time.h
* map
* memory

### Typy obiektu
* Scena - background gry, platformy
* Menu - ekran tekstowy
* Player i Enemy 
* Monety 
* ObjectManager - agregacja obiektów do malowania

### Klasy
* **GAME : public sf::RenderWindow** - tworzy scenę gry, pętla gry, zdarzenia, rysowanie obiektów, spawn postaci i  monet,
* **Menu : public sf::RenderWindow** - tworzenie i obsługa zdarzeń menu, wyswietlanie punktów obiektu klasy **Hero**
* **Animation : public sf::Sprite** - animacja tekstur <br/>
  * **Entity : public Animation** - wykrywanie kolizji, interakcja ze sceneria
    * **Coin : public Entity** - obiekt moneta, dodawanie punktow, jesli zostal zdobyty
    * **Hero : public Entity** - klasa postaci, poruszanie się, atak, cooldowny, 
      * **Player : public Hero** - sterowanie klawiatura, pętla zdarzeń
      * **Enemy : public Hero**
* **GameObject : public sf::Sprite** 
  * **Object : public GameObject** - obsługa zmiana koloru i  wypełnienia,
* **ObjectManager** - przechowywanie malowanych ścian, logika Reversi, zmiana koloru przez obiekty klasy **Hero**, zliczanie punktow, warunek zakonczenia gry
* **Scena** - tworzenie scenerii gry
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

