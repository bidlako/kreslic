# kreslic
## Zadání

Aplikace bude z příkazové řádky přejímat 3 parametry:
drawing.exe <input_file> <output_file> <size>

Zde <input_file> označuje vstupní soubor se sekvencí příkazů (popsáno níže), <output_file> výstupní soubor a size specifikátor velikostu plátna, resp. rastru.

Program detekuje z názvu výstupního souboru (resp. jeho přípony) požadovaný výstupní formát. Validními rozpoznávanými příponami jsou:

    pgm - formát PGM (specifikaci formátu PGM lze naleznout zde: http://netpbm.sourceforge.net/doc/pgm.html)
    svg - základní formát (specifikaci formátu SVG lze naleznout zde: https://www.w3.org/TR/SVG2/)

Specifikátor velikosti plátna je vždy zadán jako dvojice přirozených čísel (bez nuly) oddělených znakem 'x', ve které je prvním číslem šířka a ve druhém výška plátna (resp. rastru).

Program tedy může být spouštěn třeba takto:

./drawing.exe house.txt house.pgm 150x100

Pokud dojde k jakékoliv chybě, program vypíše srozumitelný popis chyby a ukončí se s nenulovým návratovým kódem. Mezi tyto chyby může například patřit nevalidní parametr příkazové řádky, neexistující vstupní soubor, špatný formát dat v tomto souboru, nedostatek paměti a jiné.

Pokud však k chybě nedojde, program pouze vypíše na konzoli řetězec OK a na další řádce počet příkazů, které úspěšně zpracoval (nemusí souhlasit s počtem řádek, viz níže).

Výstupem tak může například být následující text:
OK
16
