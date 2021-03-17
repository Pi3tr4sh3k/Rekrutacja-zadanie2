# Rekrutacja-zadanie2
<p>Celem zadania jest wyznaczenie drogi robota przy minimalnym zużyciu energii na danych odcinkach drogi. Każdy typ drogi (zielony, żółty i czerwony) swój koszt przejechania na każdy 1m pokonanej trasy. Do celów diagnostycznych koszt czerwonej trasy = 3, żółtej = 2, zielonej = 1. Program wykorzystuje algorytm Dijkksty do znajdowania najkrótszej trasy</p>
<ol>
   <h2><li>Rozrysowanie grafu</h2>
  <p>Pierwszym krokiem było rozpisanie grafu dla danej trasy. Graf prezętuje się następująco:</p>
   <p><img src=graph1.png/></p></li>
   <h2><li>Implementacja macierzy</h2>
      <p>Kolejnym krokiem było utworzenie macierzy i implementacja w kodzie. Nasza macierz będzie przekazywana jako argument do funkcji w którym będzie szukana nakrótsza trasa.            Natomiast zanim to nastąpi musimy pobrac od użytkownika informacje o kosztach przejazdu po poszczególnych typach tras. W tym celu została wprowadzona nieskończona pętla            z warunkiem przerwania w momencie kiedy wszystkie nasze trzy zmienne są większe od zera. Pobrane wartości razem z oryginalną macierzą trafiają do funkcji pathWeight,              która wymnaża poszczególne elementy macierzy przez koszta przejazdu na odpowiadających im typach trasy. Funkcja zwraca poprawioną macierz, której reprezentacja w formie            graf znajduje się poniżej:</p>
   <p><img src=graph2.png/></p></li>
   <h2><li>Algorytm Djikstry</h2>
      <ul>
         <li>Zostaje zainicjowana tablica sptSet w której będą przechowywane informacje o wierzchołkach które należą do najkrótszej ścieżki</li>
         <li>Następuje inicjacja tablicy dist w której będą przechowywane informacje o najkrótszych odległościach od pkt startowego do poszczególnych wierzchołków. Naszym celem                jest wyznaczenie najkrótszej trasy pomiędzy wierzchołkiem 0 - 4</li>
         <li>Wartości tablicy dist są ustawiane początkowo na INT_MAX (jedynie wierzchołek z którego zaczynamy przyjmuje wartość 0. Wartości tablicy sptSet również są ustawione na              0.</li>
         <li>Algorytm wybiera następne wierzchołki i decyduje, która ścieżka jest krótsza. Od tego jest funkcja minDistance. Wartość jest zwracana jako min_index</li>
         <li>Następnie w pętli w funkcji djikstra jest liczona najmniejsza odległość pomiędzy punktami od punktu wyściowego</li>
         <li>Jako ostatni krok jest zwracana wartość dist[4] - czyli najmniejsza odległość od naszego docelowego wierzchołka (B)</li>
      </ul>
    <li><h2>Sprawdzenie poprawności wykonania algorytmu</h2>
      <p>Dla danych r=3, y=2, g=1 program powinien zwracać wartość 33,5. Dla porównania ustawiłem wagi poszczególnych tras na grafie i rzeczywiście najmniejsza odległość pomiędzy wierzchołkiem 0-4 (A - B) wynosi 33,5
   <p><img src=spr.JPG/></p></li>
</ol>
   
   



