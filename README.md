# Rekrutacja-zadanie2
<p>Celem zadania jest wyznaczenie drogi robota przy minimalnym zużyciu energii na danych odcinkach drogi. Każdy typ drogi (zielony, żółty i czerwony) swój koszt przejechania na każdy 1m pokonanej trasy. Do celów diagnostycznych koszt czerwonej trasy = 3, żółtej = 2, zielonej = 1. Program wykorzystuje algorytm Dijkksty do znajdowania najkrótszej trasy</p>
<ol>
   <h2><li>Rozrysowanie grafu</h2>
  <p>Pierwszym krokiem było rozpisanie grafu dla danej trasy. Graf prezętuje się następująco:</p>
   <p><img src=graph1.png/></p></li>
   <h2><li>Implementacja macierzy</h2>
   <p>Kolejnym krokiem było utworzenie macierzy i implementacja w kodzie. Nasza macierz będzie przekazywana jako argument do funkcji w którym będzie szukana nakrótsza trasa. Natomiast zanim to nastąpi musimy pobrac od użytkownika informacje o kosztach przejazdu po poszczególnych typach tras. W tym celu została wprowadzona nieskończona pętla z warunkiem przerwania w momencie kiedy wszystkie nasze trzy zmienne są większe od zera. Pobrane wartości razem z oryginalną macierzą trafiają do funkcji pathWeight, która wymnaża poszczególne elementy macierzy przez koszta przejazdu na odpowiadających im typach trasy. Funkcja zwraca poprawioną macierz, której reprezentacja w formie grafu znajduje się poniżej:</p>
   <p><img src=graph2.png/></p></li>
   
   



