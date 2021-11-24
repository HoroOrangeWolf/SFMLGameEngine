#include "UpdateableObject.h"

/**
 * .
 * \brief Dodaje obiekt z kluczami i przesunieciem
 * \param key Klucz 
 */
void UpdateableObject::addKeyAndStore(KeyAndVector key)
{
	vectorList.push_back(key);
}
