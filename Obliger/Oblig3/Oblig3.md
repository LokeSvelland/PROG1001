/**
 *  Lar spillerne sette brikker, og finner evt en vinner.
 *
 *  @return   Spillernummeret som har vunnet (1, 2), evt. 0 (ingen vinner)
 *  @see      sjekkBrett(...)
 *  @see      skrivBrett(...)
 *  @see      sjekkVinner(...)
 */
int spillSpillet() {

loop opp til runde 9 så stopp
    skrivBrett for hver runde
    sjekkBrett for hver runde
    ved partallsrunder skal spiller 1 spille ellers ska lspiller 2 spille
        spiller 1 velg rute
            hvis rute er ledig
                plasser X
                    hvis ikke rute er ledig
                        returner "rute ikke ledig"
        når spiller 1 har plassert X skal spiller 2 plassere O
            hvis rute ledig
                plasser O
                    hvis rute ikke ledig
                        returner "rute ikke ledig"

hvis sjekkVinner == X
    så har Spiller1 vunnet
    retunr 1
ellers hvis sjekkVinner == O
    så har spiller2 vunnet
    retunr 2

}
