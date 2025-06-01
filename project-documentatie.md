# Automatisch Bewateringssysteem voor Planten
## Procesverslag

### 1. Opdrachtbeschrijving

#### Projectdoel
Het ontwikkelen van een automatisch bewateringssysteem voor planten met behulp van een Arduino. Het systeem moet in staat zijn om de vochtigheid van de grond te meten en automatisch water toe te dienen wanneer nodig.

#### Benodigde Hardware
- Arduino microcontroller
- Bodemvochtigheidssensor
- 5V waterpomp
- Relaismodule (voor aansturing van de pomp)
- Waterreservoir
- LED Scherm (voor statusweergave)
- Ultrasoon sensor (voor waterniveau meting)

#### Gebruikte Libraries
- Arduino.h (standaard Arduino library)
- Wire.h (voor I2C communicatie)
- u8g2 (Aansturing Oled panel)

### 2. Procesbeschrijving

Het project verliep over het algemeen goed. Tijdens de ontwikkeling kwamen er verschillende uitdagingen naar voren, maar door onderzoek en het gebruik van online bronnen konden deze problemen worden opgelost. Het proces was een goede leerervaring waarbij praktische kennis over Arduino-programmering en elektronica werd opgedaan.

Een belangrijke uitdaging was het vinden van een geschikte voeding voor het systeem. De Arduino zelf bleek niet krachtig genoeg te zijn om de waterpomp aan te sturen. Na verschillende tests en onderzoek kwam ik tot de oplossing om een telefoonoplader als externe voeding te gebruiken. Deze werd aangesloten op het breadboard, wat een directe 5V output mogelijk maakte. Deze aanpak had als bijkomend voordeel dat de Arduino nu puur als besturingssysteem kon functioneren, zonder de extra belasting van het voeden van de componenten. Dit maakte het systeem niet alleen betrouwbaarder, maar ook efficiënter in gebruik.

Een specifieke uitdaging was het werken met het LED scherm. In eerste instantie probeerde ik het scherm aan te sturen met de standaard LiquidCrystal library, maar dit werkte niet. Na verder onderzoek ontdekte ik dat mijn specifieke OLED scherm de u8g2 library nodig had. Deze library biedt meer geavanceerde mogelijkheden voor het aansturen van OLED displays, zoals het tekenen van grafieken en het weergeven van verschillende lettertypes. 

Een andere uitdaging was het gebrek aan soldeerervaring en -materiaal. Dit beperkte de mogelijkheden om extra sensoren, zoals een luchtvochtigheidssensor, direct te implementeren. Hoewel dit een beperking was, heeft het me wel geleerd om creatief om te gaan met de beschikbare middelen en te focussen op wat wel mogelijk was. Het project is nu functioneel met de basiscomponenten en simpele externe sensoren, maar er zijn plannen voor uitbreiding in de toekomst.

### 3. Reflectie

#### Situatie 1: Eerste Implementatie
**Situatie**: Het begin van het project waarbij de basiscomponenten werden aangesloten.  
**Taak**: Het correct aansluiten van de vochtigheidssensor en het testen van de metingen.  
**Actie**: Onderzoek naar de juiste aansluitwijze en het schrijven van testcode.  
**Resultaat**: Succesvolle implementatie van de vochtigheidsmeting.  
**Reflectie**: Door eerst goed onderzoek te doen naar de componenten, kon veel tijd worden bespaard bij de implementatie.

#### Situatie 2: Pomp Aansturing
**Situatie**: Het implementeren van de waterpomp met relais en het vinden van een geschikte voeding.  
**Taak**: Het veilig aansturen van de 5V pomp via het relais en het voorzien van voldoende stroom.  
**Actie**: Testen van verschillende voedingen en het implementeren van een externe voeding via een telefoonoplader.  
**Resultaat**: Werkend systeem met veilige pompbediening en betrouwbare voeding.  
**Reflectie**: Het belang van een goede voeding en het scheiden van besturing en voeding werd duidelijk. Deze ervaring heeft mijn begrip van elektrische systemen verbeterd.

#### Situatie 3: Gebruikersinterface
**Situatie**: Het toevoegen van het LED scherm voor statusweergave.  
**Taak**: Het ontwikkelen van een duidelijke gebruikersinterface met het OLED scherm.  
**Actie**: Onderzoek naar de juiste library (u8g2) en het implementeren van verschillende statusberichten.  
**Resultaat**: Succesvolle implementatie van een duidelijke statusweergave met het OLED scherm.  
**Reflectie**: Het belang van het kiezen van de juiste library en het goed documenteren van de gebruikte componenten werd duidelijk. Deze ervaring heeft mijn probleemoplossend vermogen verbeterd.

#### Situatie 4: Waterniveau Meting
**Situatie**: Het implementeren van een ultrasoon sensor voor het meten van het waterniveau in de tank.  
**Taak**: Het omzetten van de tijdsduur van het ultrasone signaal naar een bruikbaar volume.  
**Actie**: Onderzoek naar de wiskundige formules voor het berekenen van het volume op basis van de afstand. Implementatie van de berekeningen in de code.  
**Resultaat**: Succesvolle implementatie van een nauwkeurige waterniveau meting die het volume in de tank kan berekenen.  
**Reflectie**: Deze uitdaging heeft mijn begrip van zowel de technische als wiskundige aspecten van sensortechnologie vergroot. Het was een goede oefening in het toepassen van theoretische kennis in een praktische situatie.

### Conclusie

Het project heeft geleid tot een functioneel automatisch bewateringssysteem dat planten kan onderhouden zonder dagelijkse handmatige interventie. De opgedane ervaring met Arduino-programmering, elektronica en gebruikersinterface-ontwerp heeft geleid tot waardevolle inzichten voor toekomstige projecten. 

Wat dit project extra bijzonder maakt, is dat het niet alleen een leerzame ervaring was, maar ook direct praktisch toepasbaar in mijn eigen huis. Het systeem helpt nu actief bij het onderhouden van mijn planten, wat het project extra betekenisvol maakt. De combinatie van technische uitdagingen, praktische toepasbaarheid en het zien van concrete resultaten heeft dit project tot een zeer bevredigende ervaring gemaakt.

### Toekomstplannen

Het project is nog niet afgerond in de zin dat er nog uitbreidingsmogelijkheden zijn. Een luchtvochtigheidssensor ligt klaar om geïmplementeerd te worden zodra de benodigde soldeervaardigheden zijn opgedaan. Deze uitbreiding zal het systeem nog intelligenter maken door ook rekening te houden met de luchtvochtigheid bij het bepalen van de bewateringsfrequentie. Het project dient dus als een goede basis voor verdere ontwikkeling en verbetering. 

[Link naar videomateriaal op OneDrive](https://npcg-my.sharepoint.com/:v:/g/personal/fmbruinzeel_st_noorderpoort_nl1/EcY6Gwl-1C5JpAvCs7VAy8oB03Bo1ltVrjRtvPel-TYyrg?nav=eyJyZWZlcnJhbEluZm8iOnsicmVmZXJyYWxBcHAiOiJPbmVEcml2ZUJ1c2luZXNzIiwicmVmZXJyYWxBcHBQbGF0Zm9ybSI6IldlYiIsInJlZmVycmFsTW9kZSI6InZpZXciLCJyZWZlcnJhbFZpZXciOiJNeUZpbGVzTGlua0NvcHkifX0&email=n.vermeulen%40noorderpoort.nl&e=EVf7AX) Alleen toegangkijk voor Niels Vermeulen, Docent Noorderpoort.