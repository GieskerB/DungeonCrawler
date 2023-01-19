#ifndef ITEM_MATERIAL_HPP_
#define ITEM_MATERIAL_HPP_

#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

/*
 * Java-like Enum-Class für konstatne Objekte
 */
class Material {

public:

	// Konstante Objekte
	static const Material LEATHER;
	static const Material WOOD;
	static const Material STONE;
	static const Material CHAIN;
	static const Material GOLD;
	static const Material IRON;
	static const Material DIAMOND;
	static const Material NETHERITE;

	// Attribute
	const string str;
	const short baseDamage, baseDefense;

	Material(const Material &mat) = delete;

private:

	// Konstruktor
	Material(const string tag, const int baseDmg, const int baseDef) ;

public:

	// Methods

	/*
	 * Gibt ein zufälliges Material für ein Rüstungsstück zurück.
	 * Seltenheit basiert auf dem Wert des Materials
	 */
	static const Material* randomArmor() ;

	/*
	 * Gibt ein zufälliges Material für eine Waffe zurück.
	 * Seltenheit basiert auf dem Wert des Materials
	 */
	static const Material* randomWeapon() ;

	/*
	 * Muss aus unerklärlichen Gründen selbst geschrieben werden
	 */
	bool operator==(const Material &mat) const;


	/*
	 * Überprüft, ob das gegebene Material valide für ein Rüstungsteil ist.
	 * Und gibt ansosnten ein valides Material zurück
	 */
	static const Material* checkArmor(const Material *mat) ;

	/*
	 * Überprüft, ob das gegebene Material valide für eine Waffe ist.
	 *  Und gibt ansosnten ein valides Material zurück
	 */
	static const Material* checkWeapon(const Material *mat) ;

};

#endif /* ITEM_MATERIAL_HPP_ */
