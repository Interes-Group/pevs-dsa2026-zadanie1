# PEVŠ DSA 2026 - Semestrálny projekt 1

# 🛡️ SENTINEL – Systém pre spracovanie sieťových hrozieb

![C++ 17](https://img.shields.io/badge/language-C++17-blue)
![Deadline 25.03.2026 23:59](https://img.shields.io/badge/deadline-25.03.2026%2023%3A59-red)
[![Github Classrom](https://img.shields.io/badge/GitHub-Classroom-green)](https://classroom.github.com/classrooms)
[![Static Badge](https://img.shields.io/badge/Web-DSA.Interes.Group-aquamarine)](https://dsa.interes.group/assignments/assignments1)

Cieľom zadania je implementovať jednoduchú konzolovú aplikáciu (tzv. CLI - command line interface)
pre zachytenie a vyriešenie sieťových incidentov.

Program umožní používateľovi zaznamenať incident na počítačovej sieťi a následne získať informácie o incidente, ktorý je
na rade na vyriešenie. Program udržiava zoznam zariadení v počítačovej sieti. Incident sa vždy odohrá voči nejakému
zariadeniu v sieti.

Program má pracovať s triedami a kontajnermi/kolekciami pre udržiavanie objektov (zariadení a incidentov).
Program má pracovať s dvoma rôznymi kolekciami – fronta a mapa. V mape program ukladá známe zariadenia a vo fronte
ukladá incidenty, ktoré sa majú vyriešiť.
Aby bolo možné pokračovať práci pri opakovanom spustení, zariadenia a incidenty sú ukladané do súborov.

Program po skompilovaní je spustení z konzoly/terminálu s tzv. pomenovaným argumentami (options), napríklad:

```shell
./sentinel --help
```

## Zoznam zariadení

Program udržiava zoznam zariadení v počítačovej sieti. Program umožňuje pridať a vypísať zariadenie.
Zariadenie uchováva nasledovné informácie:

- IP adresa
- Názov zariadenia
- Počet incidentov

Zariadenia sú ukladané do kolekcie typu **map**, kde kľúč je IP adresa zariadenia a hodnota je objekt typu
**Zariadenie** (alebo príslušnej triedy reprezentujúc zariadenie).
So záznamami má program pracovať pomocou vstupných argumentov. Program ukladá záznamy do súboru _zariadenia.txt_,
aby boli dostupné pri ďalšom spustení programu.

### Práca so zariadeniami

Program umožňuje používateľovi pridať nové zariadenie a vypísať existujúce zariadenia, ktoré program pozná.

O ktorú funkcionalitu programu ide je vyjadrené prvým argumentov, tzv. príkazom, programu:

- `new` - Pridanie nového zariadenia.
- `list` - Vypísanie zoznamu zariadení.

Za príkazom programu nasledujú argumenty, ktoré sú určené pre daný príkaz. Spustenie programu by teda mohlo vyzerať
nasledovne:

```shell
./sentinel list
```

Počet incidentov v rámci zariadenia sa zvyšuje o jedna vždy keď je na jeho IP adresu vytvorený incident.

### Vytvorenie zariadenia

Program umožňuje používateľovi vytvoriť nové zariadenie pomocou príkazu `new` s nasledujúcimi argumentami:

| Argument         | Dátový typ | Povinný | Popis                   |
|------------------|------------|---------|-------------------------|
| `--name NAZOV`   | string     | Áno     | Názov knihy.            |
| `--ip IP_ADRESA` | string     | Áno     | IPv4 adresa zariadenia. |

Program môže by teda zavolaný napríklad:

- `./sentinel new --name iPhone --ip 192.168.1.10`
- `./sentinel new --name PC --ip 192.168.1.11`
- `./sentinel new --name Server --ip 10.10.25.30`

**Nie je možné vytvoriť 2 zariadenia s rovnakou IP adresou**. IP adresa musí byť unikátna v rámci celého programu.

Program musí používateľovi komunikovať výsledok vytvorenia zariadenia a informovať ho o chybných argumentoch,
či iných chybách. Program nové zariadenie musí uložiť do súboru pre zariadenia.

### Vypísanie zariadení

Program umožňuje používateľovi vypísať aktuálne uložené zariadenia pomocou príkazu `list`.
Program pre každé zariadenie vypíše v čitateľnej podobe všetky údaje o danom zariadení, kde jednotlivé zariadenia
sú viditeľne od seba oddelené.

Program môže byť teda zavolaný pre výpis nasledovne: `./sentinel list`.

## Fronta incidentov

Program spracováva incidenty, ktoré sú ukladané vo fronte. Program o každom incidente eviduje:

- IP adresu zariadenia
- Časová pečiatka incidentu
- Typ incidentu

Incident vzniká zapísaním do fronty a používateľ má možnosť zobraziť a vyriešiť incident, ktorý je podľa kolekcie na
rade. Vyriešením incidentu sa incident odstráni z fronty a ako objekt v programe zaniká. Program pracuje s frontou 
pomocou vstupných argumentov. Program ukladá aktuálny stav fronty do súboru _incidenty.txt_, aby bola dostupná 
pri ďalšom spustení programu.

### Práca so frontom incidentov

Program umožňuje používateľovi pracovať s frontou incidentov pomocou príkazov:

- `add` - Pridanie nového incidentu do fronty.
- `fix` - Vyriešenie incidentu, ktorý je na rade.
- `count` - Zobrazenie počtu incidentov v fronte.

Za príkazom programu nasledujú argumenty, ktoré sú určené pre daný príkaz. Spustenie programu by teda mohlo vyzerať
nasledovne:

```shell
./sentinel fix
```

### Pridanie incidentu do fronty

Program umožňuje pridanie nového incidentu do fronty pomocou príkazu `add` s nasledovnými argumentami:

| Argument               | Dátový typ | Povinný | Popis                                              |
|------------------------|------------|---------|----------------------------------------------------|
| `--ip IP_ADRESA`       | string     | Áno     | IPv4 adresa zariadania na ktorom vznikol incident. |
| `--type TYP_INCIDENTU` | string     | Nie     | Jeden z dostupných typov incidentu.                |

Typ incidentu môže byť jedna z nasledujúcich hodnôt:

- `ddos` - Distributed Denial of Service
- `sql_injection` - SQL Injection
- `xss` - Cross-Site Scripting
- `brute_force` - Brute Force Attack
- `broken_auth` - Broken Authentication
- `unknown` - Neznámy typ incidentu

V prípade nezadania typu incidentu, bude použitý predvolený typ `unknown`.

Program môže by teda zavolaný napríklad:

- `./sentinel add --ip 192.168.1.10 --type ddos`
- `./sentinel add --ip 192.168.1.11 --type sql_injection`
- `./sentinel add --ip 10.10.25.30`

Incident je možné vytvoriť len na známu IP adresu, t.j. len na zariadenie, ktoré je už známe programu.

Pri vytvorení incidentu je do neho uložená časová pečiatka (počet sekúnd od 1.1.1970, viac info: 
[https://docs.vultr.com/cpp/standard-library/ctime/time](https://docs.vultr.com/cpp/standard-library/ctime/time))
kedy incident vznikol a počítadlo incidentov pre dané zariadenie sa zvýši o 1.

Program musí používateľovi komunikovať výsledok zaznamenania incidentu a informovať ho o chybných argumentoch,
či iných chybách. Program nový incident musí uložiť do súboru pre incidenty.

### Spracovanie incidentu

Program umožňuje používateľovi vyriešiť incident, ktorý je podľa fronty aktuálne na rade pre vyriešenie,
pomocou príkazu `fix`.

Program vypíše všetky informácie o incidente a o zariadení, na ktorom daný incident vznikol. Program následne vypíše
otázku pre vstup od používateľa či incident bol vyriešený.
Program čaká na vstup od používateľa, ktorý musí byť jeden z nasledujúcich možností:

- `Y` - Ak incident bol vyriešený.
- `N` - Ak incident ešte nie je vyriešený.

Ak používateľ zadá ako vstup `Y` tak incident je odstránený z fronty. Ak používateľ zadá vstup `N`, program nič
nevykoná. Ak používateľ zadá neplatný vstup je o tom informovaný a otázka s požiadavkov o vstup je vypísaná znovu. 
Po zadaní vstupu program uloží aktuálny stav fronty incidentov do súboru a skončí.

Ak vo fronte nie sú žiadne incidenty, program vypíše túto skutočnosť používateľovi a skončí.

Program môže byť teda zavolaný nasledovne: `./sentinel fix`.

### Počet incidentov v fronte

Program pri zadaní príkazu `count` vypíše počet incidentov v fronte. Ak je fronta prázdna, vypíše jednoducho číslo 0.

Program môže byť teda zavolaný nasledovne: `./sentinel count`.

## Implementácia

V rámci implementácie môžete použiť všetky štandardné funkcie a knižnice jazyka C++, v štandarde C++17. Kód musí byť
skompilovateľný základnou inštaláciou programu **G++**, takže pozor na Windows/Mac špecifické kompilátory.

Funkcionalitu programu rozdeľte do niekoľkých funkcií a tried, ktoré následne použijete v programe.

Program implementujte v jednom súbore _main.cpp_, ktorý musí byť umiestnený v priečinku _src_ v tomto repozitáry. Ak je
zdrojový súbor umiestnený na inom mieste, alebo bude nazvaný iným menom, nebude braný pri kompilácii do úvahy, a teda
ani pri hodnotení.

Pri spracovaní vstupov sa môžete inšpirovať
článkom [Práca s argumentami programu v jazyku C](https://zapr.interes.group/guides/program_arguments/#spracovanie-prep%c3%adna%c4%8dov-flags)
na stránke predmetu ZAPR, alebo inými technikami uvedených na internete, napr.:

- [https://www.geeksforgeeks.org/cpp/command-line-arguments-in-cpp/](https://www.geeksforgeeks.org/cpp/command-line-arguments-in-cpp/)
- [https://leimao.github.io/blog/Argument-Parser-Getopt-C/](https://leimao.github.io/blog/Argument-Parser-Getopt-C/)

Pri implementácii si môžete vypomáhať s AI nástrojmi, pre inšpiráciu, diskusiu riešenia problémov, či testovanie avšak 
**je prísne zakázané priame generovanie kódu vypracovania zadania, či kopírovanie väčších častí kódu z AI či internetu**
. Táto práca je ukážkou vašich schopností a vedomostí programovania nie definovania promptu do AI.

### Implementácia kolekcií (mapa, fronta)

V rámci implementácie zadania **je povinné vypracovať vlastnú implementáciu jednej z použitých kolekcií**, 
t.j. mapu alebo frontu. Druhú kolekciu môžte použiť zo štandartných STL C++ knižníc (`<map>` a `<queue>`).

V rámci vlastnej implementácie môžte použiť iné STL knižnice, napr. `<vector>` alebo `<list>`, ktoré nie sú priamo
daná kolekcia, ktorú implementujete. Vami implementovaná kolekcia musí spĺňať funkcionalitu kolekcie tak ako je formálne
definovaná:

- mapa - Kolekcia párov kľúč-hodnota, kde kľúč musí byť unikátny v rámci kolekcie. Operácie nad kolekciou sú uskutočnené
  pomocou map kľúča.
- fronta - Kolekcia prvkov, kde prvý pridaný prvok je prvý vybraný (FIFO).

### Súbor zariadení a incidentov

Pre opakované použitie definovaných zariadení a pre uchovanie fronty incidentov pracuje program s dvoma súbormi:

- zariadenia.txt
- incidenty.txt

Oba súbory musia byť textové a uložené údaje musia byť voľne čitateľné aj mimo programu. Vnútorný formát súborov nie je
definovaný, takže pokojne zvoľte taký, s ktorými sa vám bude dobre pracovať.

Oba súbory sú vždy načítané pri spustení programu. Ak súbory neexistujú, program ich vytvorí prázdne.

Pre prácu so súborom sa môžte inšpirovať článkami:

- [https://www.programiz.com/cpp-programming/file-handling](https://www.programiz.com/cpp-programming/file-handling)
- [https://www.geeksforgeeks.org/cpp/file-handling-c-classes/](https://www.geeksforgeeks.org/cpp/file-handling-c-classes/)
- [https://www.w3schools.com/cpp/cpp_files.asp](https://www.w3schools.com/cpp/cpp_files.asp)

### Kompilácia

Pre testovanie je možné kód skompilovať príkazom:

```bash
g++ -std=c++17 -o bin/sentinel -Wall -Wextra src/main.cpp
```

Kompilátor vytvorí spustený program v priečinku _bin_ v repozitáry.

### Git

Zdrojový kód tohto projektu je manažovaný verziovacím systémom Git. Pomocou Gitu je toto vypracovanie zadania aj
odovzdané. Pre oboznámenie práce s Gitom si prečítajte tento
článok [Git pre začiatočníkov](https://dsa.interes.group/other/git-for-beginners/) alebo akýkoľvek iný tutoriál na
internete.

Pre kontrolu kompilácie je v repozitáry nastavená automatizácia cez GitHub Actions pipeline. Pipeline sa
spustí automaticky pri aktualizácii kódu vo vetve `main` (napr. `git push`). GitHub zdrojový súbor `src/main.cpp`
skompiluje pomocou poslednej verzie kompilátora **G++** pre štandard jazyka C++17. Pipeline následne pokračuje
jednoduchým
testom spustenia programu. Spustenie je testované a zaznamenané pomocou
programu [tui-test](https://github.com/microsoft/tui-test) a na konci pipeline je vypísaný výsledok takého testu.
Pipeline vždy testuje posledný commit vo vetve `main` a testuje program s argumentom `--help`. Pre správnu kontrolu
programu musí nápoveda/pomocný text programu obsah slovo "Help".
Pipeline je možné spustiť ľubovoľný počet krát. Spustenie pipeline je možné vidieť v záložke _Actions_ vo vašom
repozitáry zadania.

## Hodnotenie

Zadanie je **ohodnotené 20 bodmi**. Odovzdaný program musí byť skompilovateľný kompilátorom G++ a spustiteľný, inak je
hodnotený 0 bodmi. Pri hodnotení vypracovania zadania sa kontroluje originalita odovzdaného vypracovania medzi všetkými
študentmi a zároveň aj voči AI nástrojom (kód vygenerovaný pomocou ChatGPT, Gemini a Claude Sonnet a pod.). Vypracovanie
**so
zhodou vyššou ako 70% sú hodnotené 0 bodmi**. Hodnotený je iba kód ku poslednému commitu vo vetve `main`, ktorý bol
urobený do termínu odovzdania.

Vypracovanie bude **podrobené automatizovaným testom**, ktoré budú spúšťať program s definovanými argumentami a
kontrolovať obsah výstupu programu. Je teda veľmi dôležité dodržať špecifikáciu argumentov, ako aj formát výstupu
programu pre používateľa. Výsledky automatizovaných testov budú zverejnené do tohto repozitára do vetvy `feedback`.
V prípade chyby v testoch, budú testy spustené znovu a nový výsledkom zverejnený. Po uplynutí termínu odovzdania
zadania budú definície testov zverejnené a ak v nim nájdete chybu prosím nahláste
ju [sem ako nové GitHub issue](https://github.com/Interes-Group/pevs-dsa2026-zadanie1).

Vypracovanie bude hodnotené aj ručne. Pri hodnotení vypracovania sa bude prihliadať na:

- práca s premennými
- definovanie control flow programu
- definovanie vlastných funkcií a ich použitie
- definovanie tried a práca s nimi
- spracovanie argumentov
- implementácia a využitie kontajnerov/kolekcií
- komunikácia chybového stavu programu používateľovi
- štruktúrovane kódu
- dodržanie špecifikácie zadania

## Odovzdanie

Po prihlásení sa na zadanie 1 cez [GitHub Classroom]() vám je automaticky vytvorená kópia repozitára, ktorý bude
nastavený ako privátny pre vás na vypracovanie (t.j. máte povolený commit a push do repozitára). Skontrolujte si, či sa
váš repozitár nachádza pod skupinou _Interes-Group_, inak vyučujúci nemajú prístup ku vášmu repozitáru a zadanie sa
nepovažuje za odovzdané. Ak sa vám repozitár nevytvorí ihneď kontaktuje vyučujúceho na MS Teams alebo na univerzitnom
emaily. Je prísne zakázané dávať prístup k vášmu repozitára inému študentovi, alebo osobe, ktorá nie je vyučujúci. V
repozitáry by sa mali vytvoriť dve vetvy `main` a `feedback` a vytvorí sa tzv. pull request z vetvy `main` do vetvy
`feedback`. **Váš kód pushujte (t.j. `git push`) do vetvy `main`**. Hodnotenie vypracovania, ako aj komentár ku kódu,
uvidíte v danom pull requeste. Ak sa vám vetva `feedback` alebo pull request nevytvorí ihneď kontaktuje vyučujúceho na
MS Teams alebo na univerzitnom emaily.

V repozitáry upravujte iba súbory pod priečinkom **src**. Ostatné súbory je zakázané upravovať, predovšetkým súbory pre
kompiláciu, súbory obsahujúce GitHub pipeline (.github) a súbory obsahujúce automatizované testy (priečinok **test**).
Pri zmene týchto súborov môže byť vypracovanie ohodnotené 0 bodmi.

Vypracovanie zadania priebežne commitujte (`git commit`)/pushujte (`git push`) do repozitára vytvoreného GitHubom
pre toto zadanie. Váš kód commitujte/pushujte do vetvy `main`. Hodnotený bude posledný commit/push do termínu odovzdania
vypracovania. Vypracovanie je nutné odovzdať/commitnúť/pushnúť do repozitára **do 25.03.2026 23:59**. Neodovzdanie je
hodnotené 0 bodmi.

V prípade otázok, alebo technických problémov môžete kontaktovať vyučujúcich na MS Teams alebo na univerzitnom emaily.

## Automatizované testovanie

Tento repozitár obsahuje aj nastavenie pre automatizované testovanie pomocou nástroje _tui-test_.
Tento program je založený na jazyku Typescript a je spúšťaný pomocou Node.js. Všetky testy a nastavenia sú uchované
v priečinku _test_ a **prísne zakázané ich prípadnú zmenu pushnúť do repozitára na odovzdanie**. Pre tých, ktorý
ovládajú tento jazyk a sú schopný si rozšíriť test suite o vlastné testy pokojne môžu, len ich nikde nezdieľajte a
nepushujte do repozitára na GitHube na odovzdanie.

### Návod pre nastavenie a spustenie testov

#### Prerekvizity:

- Nainštalovaný **Node.js** (verzia 20 alebo vyššia)
- Nainštalovaný **npm** (Node Package Manager)
- Skompilovaný program `sentinel` v priečinku `bin/`

#### Postup:

1. **Skompilujte program** (ak ste to ešte neurobili):

```shell script
mkdir -p bin
g++ -std=c++17 -o bin/sentinel -Wall -Wextra src/main.cpp
```

2. **Prejdite do priečinka test**:

```shell script
cd test
```

3. **Nainštalujte závislosti**:

```shell script
npm install
```

4. **Spustite testy**:

```shell script
npm test
```

**Alternatívne spustenie:**

Môžete použiť priamo nástroj tui-test:

```shell script
cd test
npx @microsoft/tui-test
```

#### Čo testy kontrolujú:

Testy používajú nástroj **tui-test** od Microsoftu, ktorý:

- Spúšťa váš program s rôznymi argumentami
- Zachytáva výstup programu v termináli
- Porovnáva výstup s očakávanými výsledkami (uložené v `__snapshots__`)
- Overuje formát výstupu a správnosť výpočtov