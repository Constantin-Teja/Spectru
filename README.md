# Spectru


Proiectul presupune diferentierea culorii fasciculelor de lumina.Principiul fizic pe care se bazeaza proiectul este urmatorul: se  transmite un fascicol de lumina printr-o prisma care are rolul de dispersie a luminii in functie de lungimea ei de unda,lungime de unda care este caracteristica pentru fiecare culoare.
Fasciculele dispersate sunt refectate dupa de o oglinda amplasata pe un servo-motor,care efectueaza 100 de miscari per masuratoare.Intensitatea luminii reflectate de oglinda este masurata cu ajutorului unui fotorezistor.
Datorita dispersiei diferite a luminii in functie de culoare, intensitatea medie a luminii este diferita si specifica pentru fiecrae culoare, astfel facandu-se diferenta.Pentru a fi masuratorile independete de mediu am implementat o functie numita resetBaseline(),care masoara lumina ambientala ce va fi folosit ca offset pentru masuratorile viitoare.Pentru fiecare culoare , respectiv rosu si verde, am creat cate o functie pentru determinarea intrensitatii medii in mediul respectiv. Dupa determinarea acestor valori, se pot recunoaste culoarile respective.
