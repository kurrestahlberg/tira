#ifndef __TREENODE_H__
#define __TREENODE_H__

/**
 * Huffman-puun solmu. Jos kyseessä on lehtisolmu pitää luokka sisällään varsinaisen
 * datan ja mikäli kyseessä on runkosolmu on sillä linkit lapsisoluihin. Lehti- ja
 * runkosolmut voidaankin siis erottaa toisistaan helposti tarkistamalla onko solmulla
 * lapsia vai ei. Jokaisella solmulla on myös puuta muodostettaessa paino (weight)
 * jota käytetään puun osien järjestämiseen sitä rakennettaessa.
 */
class TreeNode {
public:
	/**
	 * Lehtisolmun luova konstruktori
	 */
	TreeNode(char _value, int _weight);
	/**
	 * Tyhjän solmun, eli käytännössä runkosolmun, luova konstruktori
	 */
	TreeNode();
	~TreeNode();
	
	/**
	 * Metodi solmun koodausbittien määrittelyyn. Metodi tallettaa solmuun parametrina
	 * annettavat bitit ja niiden määrän sekä antaa lapsilleen bitit joihin on lisätty
	 * joko nolla (vasen) tai ykkönen (oikea) jotta ne voivat määrittää omat bittinsä.
	 */
	void figureOutBits(unsigned int bits, int count);
	
	/**
	 * Etsii alipuusta oikeaa lehtisolmua. Mikäli tämä solmu on lehtisolmu palauttaa
	 * metodi itsensä (eli this-olion), muuten se kutsuu rekursiivisesti jomman kumman
	 * lapsensa vastaavaa metodia riippuen siitä onko annetun bittijonon ensimmäinen bitti
	 * nolla (vasen) vai ykkönen (oikea) ja antaa parametriksi yhdellä shiftatun 
	 * bittijonon
	 */
	TreeNode * getChild(unsigned int bits);
	
	/**
	 * Solmun arvo. Ainoastaan lehtisolmulla nollasta poikkeava
	 */
	unsigned char value;
	/**
	 * Solmun paino. Runkosolmulla kaikkien lasten yhteenlaskettu paino.
	 */
	unsigned int weight;
	
	/**
	 * Vasen lapsisolmu
	 */
	TreeNode * left;
	/**
	 * Oikea lapsisolmu
	 */
	TreeNode * right;
	
	/**
	 * Solmun bitit jotka vastaavat solmun sijaintia puussa. Talletetaan jokaiseen solmuun
	 * jotta pakkausvaiheessa niitä ei tarvitse kasata joka kerta uudelleen.
	 */
	unsigned int bits;
	/**
	 * Solmun bittien määrä. Talletetaan solmuun koska bittimäärän määrittäminen on 
	 * mahdotonta monessa tilanteessa
	 */
	int bitCount;

	/**
	 * Debuggausta ja statistiikkaa tulostava metodi
	 */
	int print();
};

#endif // __TREENODE_H__