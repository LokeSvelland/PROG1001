Brukeren tilbys hele tiden disse valgene:
L – Legge til bane
S – Se alle baner
Q – Avslutt

Disse kommandoene skal virke som følgende:

L: Hvis det allerede er lagt til MAXBANER, skrives det ut en beskjed om dette, og ingen
baner kan legges til. I motsatt fall leses den nye banens lengde (0 eller et positivt tall).
Skriver bruker 0 (null), legges ingen bane til allikevel. Det kommer da bare en egen
beskjed, og det gås tilbake til hovedmenyen. Ellers lagres den nye banens lengde.
Par (lovlige verdier: 2-8), OB (lovlige verdier: ‘J’/’N’) og beskrivelse for banen leses
deretter. Det skal altså sikres (vha. looping) at tall (lengde og par) og bokstaver (OB)
er i lovlige intervaller/lovlig tegn. Husk å oppdatere antallBaner korrekt.

S: Alle banene som er registrert for øyeblikket skal skrives på skjermen med alle sine
data (nummer, beskrivelse, lengde, par og om OB eller ei).
Til slutt skrives nåværende antall baner og totalt antall kast for å havne på par
(summen av alle de nåværende banenes par).

Q: Når programmet avsluttes, skrives en egen melding om at det avsluttes.
Det kommer en egen melding dersom bruker skriver ulovlig menyvalg.
Programmet skal også håndtere at bruker skriver små bokstaver for menyvalgene/OB.


hovedprogram;
    menyvalg;

        når L {
            hvis maxbaner > i {
                maxbaner lagt til
                stopp
            } ellers {
                banelengde (i > 0) {
                    hvis i<=0 {
                        ikke legg til bane
                        PRINT ikke lagt til bane
                        returner hovedmeny
                    }
            
                }
            }
        }