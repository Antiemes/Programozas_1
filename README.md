# Szakdolgozat LaTeX template

## Saját repository létrehozása

Ahhoz, hogy használhassuk a template-et, először készíteni
kell belőle egy saját repositoryt. Ehhez a webfelületen
a (zölddel kiemelt) "Use this template" gombot kell használni.
Miután adtunk neki egy saját nevet, ebben az új repositoryban
tudjuk folytatni a munkát.

## A dolgozat szövegének szerkesztése

A dolgozat szövege tulajdonképpen egy forráskód, ami egyrészt
folyó szöveget, másrészt formázási elemeket tartalmaz. Ezt a
**thesis.tex** fájlba írhatjuk. A szerkesztéshez
valamilyen kód-editort (például
(VSCode)[https://code.visualstudio.com/download]-ot) használhatunk.

A példaként szereplő fájl minden fontosabb formázásra tartalmaz
példát, amire szükségünk lehet. Ha valamire esetleg még szükségünk
lenne, akkor (Itt)[https://math.bme.hu/latex/dl/latex78.pdf]
találunk referenciaként használható leírást.

A dolgozat ábráit a **fig** könyvtárban helyezzük el.

## Fedlap, nyilatkozat

A fedlapot, a nyilatkozatot és az egyéb, a dolgozat elejére
illesztendő tartalmat a **cover.pdf** fájlban kell elhelyezni.
A rendszer ezt automatikusan össze fogja fűzni a dokumentumunkkal.

## A dokumentum fordítása

Mivel a dokumentumunk tulajdonképpen egy forráskód, ahhoz, hogy
ebből egy szépen formázott pdf-et kapjunk, ezt le kell fordítani.

### Fordítás Docker használatával

A Docker-rel történő fordításhoz a 

```code
make docker-all
```

parancsot kell használni. Ez, ha nincs letöltve a fordításhoz szükséges
Docker image, akkor letölti azt. Ez kb. 700 MB helyet foglal el.
(Természetesen ezt csak a legelső fordításkor kell megtenni, utána
már a letöltött Docker image-et használja a rendszer.) A parancs
sikeres futtatás esetén egy **thesis.pdf**, illetve egy
**thesis-with-cover** fájlt fog létrehozni. A sikertelen fordításról
hibaüzenetben kapunk tájékoztatást.

### Fordítás a felhőben

Miután egy új verziót push-oltunk a repositoryba, a fordítás a felhőben
is megtörténik. A kész dokumentumot az Actions fül alatt találjuk. Itt
látható az összes fordítás eredménye (a legfrissebb van legfelül),
erre kattintva a lap alján az **Artifacts** csoportban a
**Final document**-re kattintva tölthető le az eredmény (a pdf-et
tartalmazó zip).
