#ifndef ASSETS_H
#define ASSETS_H

#include <SFML/Graphics/Texture.hpp>
#include <string>

// Resolves a path under Resources/ from the executable location or the
// working directory. `relative` looks like "Texture/castle-tileset.png".
std::string assetPath(const char *relative);

// One GPU copy per file. The returned texture lives for the whole process.
const sf::Texture &cachedTexture(const char *relative, bool repeated = false);

#endif // ASSETS_H
