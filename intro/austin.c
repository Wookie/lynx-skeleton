// input file lynx1.mid

// format 1 file 5 tracks

//X: 1

//M:4/4

//L:1/16

//Q:1/4=75

// Last note suggests Dorian mode tune

//K:C// 4 flats

// MIDI Key signature, sharp/flats=-2  minor=0

// Time signature=4/4  MIDI-clocks/click=48  32nd-notes/24-MIDI-clocks=8

//from austin.mid

char voice1[] = {

//from austin.mid

// Flute 1

//MIDI program 73

// intro

"z16|z16|z16|z16|"

"z16|z12 zaf'f'|"

// Main tune (a)

"d'/z/d'z3af'f' d'/z/d'z3af'f'|d'/z/d'z3af'f' d'/z/d'z3af'f'|"

"d'/z/d'z3af'f' d'/z/d'z3af'f'|d'/z/d'z3af'f' d'/z/d'z3f'f'd'|f'/z/f'z3f'f'd' f'/z/f'z3af'f'|d'2z8z3af'f'|"

// Main tune (b)

"d'/z/d'z3af'f' d'/z/d'z3af'f'|d'/z/d'z3af'f' d'/z/d'z3af'f'|d'/z/d'z3af'f' d'/z/d'z3af'f'|d'/z/d'z3af'f' d'/z/d'z3f'f'd'|"

"f'/z/f'z3f'f'd' f'/z/f'z3af'f'|d'2z12z2|"

// Flute bridge

"^fa6z ^fdzB edz2|^fa6z ^fdzB edz2|"

"^fa6z ^fdzB edz2|z12 zaf'f'|"

// Main tune (b)

"d'/z/d'z3af'f' d'/z/d'z3af'f'|d'/z/d'z3af'f' d'/z/d'z3af'f'|"

"d'/z/d'z3af'f' d'/z/d'z3af'f'|d'/z/d'z3af'f' d'/z/d'z3f'f'd'|f'/z/f'z3f'f'd' f'/z/f'z3af'f'|d'2z12z2|"

"z"

// Trumpet Bridge

"A2B2B3 Az6z|zA2B2B3 cz6z|zA2B2B3 Az6z|zA2B2B3 d2Be d2B2|"

// ad lib. solo

"d2fd gfdd2ddA c2dA|c2dA c2dc2ddc dfgf|a2a2 c'a2c' d'd'd'c' agfc|dAcA c2^cd z8|"

// Flute bridge (DS)

"^fa6z ^fdzB edz2|^fa6z ^fdzB edz2|^fa6z ^fdzB edz2|z12 zaf'f'|"

// Main tune (b) (DS)

"d'/z/d'z3af'f' d'/z/d'z3af'f'|d'/z/d'z3af'f' d'/z/d'z3af'f'|d'/z/d'z3af'f' d'/z/d'z3af'f'|d'/z/d'z3af'f' "

// Coda

"d'/z/d'z3f'f'd'|"

"f'/z/f'z3f'f'd' f'/z/f'z3af'f'|d'2z8z3f'f'd'|f'/z/f'z3f'f'd' f'/z/f'z3af'f'|d'2z6 d'2"

};

char voice2[] = {
// Trumpet 1

//MIDI program 56

// intro

"z16|z16|z16|z16|"

"z16|a2za az2a aza2 z4|z16|z16|"

"z16|z12 z"

// Main tune (a)

"ffd|ffz3ffd ffz3Aff|d2z12z2|"

"z3"

// Main tune (b)

"d z12|z3d z12|z3g z12|z3d z8 zffd|"

"ffz3ffd ffz3Aff|d2z12z2|z2"

// Flute bridge

"dz ddz2 dzdd z4|z2dz ddz2 dzdd z4|"

"z2dz ddz2 dzdd z4|zc'^c'^d' e'^f'g'^g' a'z6z|z3"

// Main tune (b)

"d z12|z3d z12|"

"z3g z12|z3d z8 zffd|ffz3ffd ffz3Aff|d2z8a2 gfdB|"

// Trumpet Bridge

"d6-dz2dfg2fdB|d6-dz3a2 gfdB|d6-dz2dfg2fdB|d6-dz8z|"

"z16|z16|z16|z16|"

"z2"

// ad lib. solo

// Flute bridge (DS)

"dz ddz2 dzdd z4|z2dz ddz2 dzdd z4|z2dz ddz2 dzdd z4|zc'^c'^d' e'^f'g'^g' a'z6z|"

"z3"

// Main tune (b) (DS)

"d z12|z3d z12|z3g z12|z3d z8 z"

// Coda

"ffd|"

"ffz3ffd ffz3Aff|d2z8z3ffd|ffz3ffd ffz3Aff|d2z6 f2"

};

char voice3[] = {

// Trombone 1

//MIDI program 57

// intro

"D,z2D z2D,z3D,z2Dz2|D,zD,D zDD,z D,zD,D zDD,z|D,zD,D zDD,z D,zD,D zDD,z|D,zD,D zDD,z D,zD,D zDD,z|"

"D,zD,D zDD,z D,zD,D zDD,z|z16|z16|z16|"

"z16|z12 z"

// Main tune (a)

"B,B,^G,|B,B,z3B,B,^G, A,A,z3A,FF|D2z12z2|"

"z8 z2"

// Main tune (b)

"D,2 z4|z8 z2D,2 z4|z8 z2G,2 z4|z8 z2B,2 zB,B,^G,|"

"B,B,z3B,B,^G, A,A,z3A,FF|D2z8z3^F,G,^G,|"

// Flute bridge

"A,3z2^G,A,_B, B,3z2^F,G,^G,|A,3z2^G,A,_B, B,3z2^F,G,^G,|"

"A,3z2^G,A,_B, B,3z2^CD^D|E6Ez3A,,4A,,z|z8 z2"

// Main tune (b)

"D,2 z4|z8 z2D,2 z4|"

"z8 z2G,2 z4|z8 z2B,2 zB,B,^G,|B,B,z3B,B,^G, A,A,z3A,FF|D2z12z2|"

"z"

// Trumpet Bridge

"A,2B,2B,3 Dz6z|zD2B,2B,3 A,z6z|zA,2B,2B,3 Dz6z|zD2B,2B,3 A,z6z|"

// ad lib. solo

"G,zG,G zGG,z G,zG,G zGG,z|D,zD,D zDD,z D,zD,D zDD,z|A,zA,A zAA,z G,zG,G zGG,z|D2z8z3^F,G,^G,|"

// Flute bridge (DS)

"A,3z2^G,A,_B, B,3z2^F,G,^G,|A,3z2^G,A,_B, B,3z2^F,G,^G,|A,3z2^G,A,_B, B,3z2^CD^D|E6Ez3A,,4A,,z|"

"z8 z2"

// Main tune (b) (DS)

"D,2 z4|z8 z2D,2 z4|z8 z2G,2 z4|z8 z2"

// Coda

"B,2 zB,B,^G,|"

"B,B,z3B,B,^G, A,A,z3A,FF|D2z8z3B,B,^G,|B,B,z3B,B,^G, A,A,z3A,FF|D2z6 D2"

};

char voice4[] = {

//MIDI channel 10

// Drums

// intro

"G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4|G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4|G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4|G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4|"

"G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4|G,/4z/z/4z2G,/4z/z/4 G,/4z/z/4z2G,/4z/z/4 G,/4z/z/4z^Cz4z|"

// Main tune (a)

"G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4|G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4|"

"G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4|G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4|G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4|G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 ^F,/4z/z/4^F,/4z/z/4^F,/4z/z/4^F, ^F,^F,/4z/z/4E,^F,/4z/z/4|"

// Main tune (b)

"G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4|G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4|G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4|G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4|"

"G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4|G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4|"

// Flute bridge

"G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4|G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4|"

"G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4|G,/4z/z/4^F,/4z/z/4^F,/4z/z/4^F,/4z/z/4 ^F,/4z/z/4^F,/4z/z/4^F,/4z/z/4^F,/4z/z/4 ^F,/4z/z/4z^Cz2F,/4z/z/4F,/4z/z/4F,/4z/z/4|"

// Main tune (b)

"G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4|G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4|"

"G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4|G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4|G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4|G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4|"

// Trumpet Bridge

"G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4|G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4|G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4|G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4|"

// ad lib. solo

"G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4|G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4|G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4|G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4|"

// Flute bridge (DS)

"G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4|G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4|G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4|G,/4z/z/4^F,/4z/z/4^F,/4z/z/4^F,/4z/z/4 ^F,/4z/z/4^F,/4z/z/4^F,/4z/z/4^F,/4z/z/4 ^F,/4z/z/4z^Cz2F,/4z/z/4F,/4z/z/4F,/4z/z/4|"

// Main tune (b) (DS)

"G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4|G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4|G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4|G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 "

// Coda

"G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4|"

"G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4|G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4|G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4 G,/4z/z/4G,/4z/z/4G,/4z/z/4G,/4z/z/4|"

};

