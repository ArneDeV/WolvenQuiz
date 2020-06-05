# Arduino test
Quiz systeem met GUI voor scorebord.
Indien score bord gebruikt wil worden, verander bij Serial poort naar de poort waarop de Arduino is aangesloten.

## Kleurcodes van bedrading:
  - Rood --> Button pin
  - Wit --> Led grond   
  - Geel --> Button grond
  - Blauw --> LED pin

## Opmerkingen
  * Update van score kan tot 20 seconden duren
  * Soms zal de score niet onmiddelijk updaten (Vooral als zelfde team meerdere malen achter elkaar juist is), dit probleem zal uiteindelijk van zelf opgelost worden
  * Waarom het bovenstaande gebeurt is mij nog niet 100% duidelijk, waarschijnlijk fout in communicatie tussen Arduino en python.
