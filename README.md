# Spectru


Proiectul presupune diferentierea culorii fasciculelor de lumina.Principiul fizic pe care se bazeaza proiectul este urmatorul: se  transmite un fascicol de lumina printr-o prisma care are rolul de dispersie a luminii in functie de lungimea ei de unda,lungime de unda care este caracteristica pentru fiecare culoare.
Fasciculele dispersate sunt refectate dupa de o oglinda amplasata pe un servo-motor,care efectueaza 100 de miscari per masuratoare.Intensitatea luminii reflectate de oglinda este masurata cu ajutorului unui fotorezistor.
Datorita dispersiei diferite a luminii in functie de culoare, intensitatea medie a luminii este diferita si specifica pentru fiecrae culoare, astfel facandu-se diferenta.Pentru a fi masuratorile independete de mediu am implementat o functie numita resetBaseline(),care masoara lumina ambientala ce va fi folosit ca offset pentru masuratorile viitoare.Pentru fiecare culoare , respectiv rosu si verde, am creat cate o functie pentru determinarea intrensitatii medii in mediul respectiv. Dupa determinarea acestor valori, se pot recunoaste culoarile respective.

Piese esentiale folosite:
1. Arduino Nano : https://www.emag.ro/placa-de-dezvoltare-compatibila-arduino-nano-v3-cl04/pd/D69C2JBBM/?cmpid=87002&gclid=Cj0KCQjw4uaUBhC8ARIsANUuDjXe2DjjlcfFYQVPhVsbZhbv6-cC5m7YpzCqYfa4nl5HTV4_f0neyVYaAqTmEALw_wcB
2. Prisma 10 cm : https://www.coleter.ro/menaj/prisma-optica-livrare-gratuita/?gclid=Cj0KCQjw4uaUBhC8ARIsANUuDjUCm7dk5VjS7gFIq6P65Y8HTFblYy9loaf93k9rstOMPLntSQs2M34aAl9JEALw_wcB
3. Servo-motor : https://www.sigmanortec.ro/servomotor-sg90-360-continuu?gclid=Cj0KCQjw4uaUBhC8ARIsANUuDjWOJH3MMLrmcjldOwW3YrSxwktL9zun3pSmPu3kuGHyUYlIpd518QYaAmPZEALw_wcB
4. Foto-resistor : https://www.ebay.com/itm/12mm-Light-Dependent-Resistor-CDS-LDR-Photoresistor-/301179223736?mkevt=1&siteid=1&mkcid=2&mkrid=711-153320-877673-6&source_name=google&mktype=dsa&campaignid=16585816532&groupid=138229060967&crlp=588544646323&keyword=&targeted=dsa-19959388920&MT_ID=&adpos=&device=c&googleloc=1011837&geo_id=167&gclid=Cj0KCQjwheyUBhD-ARIsAHJNM-MNXoUAOrUWFSmldowPzQrxtsfbT4AxtMQFEHoCcgweQBzCRyi1hI0aAgFTEALw_wcB


Linkuri utilizate pentru studiu:
1. https://www.arduino.cc/
2. https://ro.wikipedia.org/wiki/Spectrometrie_de_mas%C4%83
3. https://www.youtube.com/watch?v=kUHmYKWwuWs
